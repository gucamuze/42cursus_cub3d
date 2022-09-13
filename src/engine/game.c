#include "cube.h"

static void	prep_img(t_mlx *mlx)
{
	t_img	*img;

	img = mlx->img;
	img->ptr = mlx_new_image(mlx->ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
		&img->line_length, &img->endian);
}

// FOR NOW ONLY UPDATES AS IF PLAYER IS ALWAYS FACING NORTH
// ALSO NO COLLISION OR ANYTHING SO IT CAN DEFINITELY SEGFAULT
void update_player(t_prog *prog)
{
	t_point		*player_pos;
	__uint8_t	*moves;

	player_pos = &prog->player->pos;
	moves = &prog->player->moves;
	if (*moves & FORWARD)
	{
		player_pos->y -= PLAYER_MOVESPEED;
	}
	if (*moves & BACKWARDS)
	{
		player_pos->y += PLAYER_MOVESPEED;
	}
	if (*moves & LEFT)
	{
		player_pos->x -= PLAYER_MOVESPEED;
	}
	if (*moves & RIGHT)
	{
		player_pos->x += PLAYER_MOVESPEED;
	}
	*moves = 0;
}

void	debug_print_player(t_point pos)
{
	printf("player x:%f\tplayer y: %f\n", pos.x, pos.y);
}

int	render_next_frame(t_prog *prog)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = prog->mlx;
	img = mlx->img;
	update_player(prog);
	// debug_print_player(prog->player->pos);
	if (prog->display_minimap == true)
		draw_minimap(prog);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->ptr, 0, 0);
	return (1);
}

// MAIN GAME LOOP :
// launches the mlx loop
void	game_loop(t_prog *prog)
{
	t_mlx	*mlx;

	mlx = prog->mlx;
	prep_img(mlx);
	mlx_loop_hook(mlx->ptr, render_next_frame, prog);
	mlx_loop(mlx->ptr);
}