#include "cube.h"

// Might be worth renaming to loop_end or something
int	end_mlx_loop(t_prog *prog)
{
	// free_prog(prog);
	mlx_loop_end(prog->mlx->ptr);
	return (0);
}

void set_minimap_display(t_prog *prog)
{
	if (prog->display_minimap == false)
		prog->display_minimap = true;
	else
		prog->display_minimap = false;
}

void set_player_movement(t_prog *prog, int keycode)
{
	__uint8_t	*moves;

	moves = &prog->player->moves;
	if (keycode == W_KEY)
		*moves |= FORWARD;
	else if (keycode == S_KEY)
		*moves |= BACKWARDS;
	else if (keycode == A_KEY)
		*moves |= LEFT;
	else if (keycode == D_KEY)
		*moves |= RIGHT;
}

int	key_hook(int keycode, t_prog *prog)
{
	(void)prog;
	printf("Hello from keycode %d\n", keycode);
	if (keycode == ESC_KEY)
		end_mlx_loop(prog);
	else if (keycode == TAB_KEY)
		set_minimap_display(prog);//tab
	else if (keycode == W_KEY || keycode == A_KEY
			|| keycode == S_KEY || keycode == D_KEY)
		set_player_movement(prog, keycode); // player moves
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		; // camera rotation
	return (0);
}

int mouse_click_hook(int button, int x, int y, t_prog *prog)
{
	(void)prog;
	printf("Mouse button %d x=%d, y=%d\n", button, x, y);
	return (0);
}

// int	mouse_move_hook(int x, int y, t_prog *prog)
// {
// 	(void)prog;
// 	printf("Mousemove => x=%d, y=%d\n", x, y);
// 	return (0);
// }
