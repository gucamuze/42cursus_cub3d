#include "cube.h"

int down(int keycode)
{
	printf("down keycode %d\n", keycode);
	return 0;
}
int up(int keycode)
{
	printf("up keycode %d\n", keycode);
	return 0;
}

// Enum for all mlx supported event are in the cube_ui.h header file
static void	init_event_hooks(t_prog *prog)
{
	t_mlx	*mlx;

	mlx = prog->mlx;
	mlx_hook(mlx->win, ON_KEYDOWN, 1L<<0, keydown_hook, prog);
	mlx_hook(mlx->win, ON_KEYUP, 1L<<1, keyup_hook, prog);
	mlx_mouse_hook(mlx->win, mouse_click_hook, prog);
	mlx_hook(mlx->win, ON_DESTROY, 0, end_mlx_loop, prog);
	mlx_do_key_autorepeaton(mlx->ptr);
}

int	init_ui(t_prog *prog)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (0);
	prog->display_minimap = false;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (0);
	mlx->win = mlx_new_window(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
		return (0);
	prog->mlx = mlx;
	init_event_hooks(prog);
	return (1);
}