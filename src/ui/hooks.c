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

void set_player_moves(t_prog *prog, int keycode, bool set)
{
	if (set == true)
	{
		if (keycode == W_KEY)
			prog->player->move_forward += 1;
		else if (keycode == S_KEY)
			prog->player->move_forward -= 1;
		else if (keycode == A_KEY)
			prog->player->move_lateral -= 1;
		else if (keycode == D_KEY)
			prog->player->move_lateral += 1;
		else if (keycode == LEFT_KEY)
			prog->player->turn_direction -= 1;
		else if (keycode == RIGHT_KEY)
			prog->player->turn_direction += 1;
	}
	else
	{
		if (keycode == W_KEY || keycode == S_KEY)
			prog->player->move_forward = 0;
		else if (keycode == A_KEY || keycode == D_KEY)
			prog->player->move_lateral = 0;
		else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
			prog->player->turn_direction = 0;
	}
}

int	keydown_hook(int keycode, t_prog *prog)
{
	printf("Hello from keydown %d\n", keycode);
	if (keycode == W_KEY || keycode == A_KEY
			|| keycode == S_KEY || keycode == D_KEY
			|| keycode == RIGHT_KEY || keycode == LEFT_KEY)
		set_player_moves(prog, keycode, true);
	return (0);
}

int keyup_hook(int keycode, t_prog *prog)
{
	printf("Hello from keyup %d\n", keycode);
	if (keycode == ESC_KEY)
		end_mlx_loop(prog);
	else if (keycode == TAB_KEY)
		set_minimap_display(prog);//tab
	if (keycode == W_KEY || keycode == A_KEY
			|| keycode == S_KEY || keycode == D_KEY)
		set_player_moves(prog, keycode, false); // player moves
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