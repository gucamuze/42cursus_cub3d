#ifndef CUBE_UI_H
#define CUBE_UI_H

#include "cube_const_enum.h"

typedef struct s_prog	t_prog;
typedef struct s_img	t_img;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	t_img	*img;
}			t_mlx;

// UI
int		init_ui(t_prog *prog);
// HOOKS
int		end_mlx_loop(t_prog *prog);
int		key_hook(int keycode, t_prog *prog);
int		mouse_click_hook(int button, int x, int y, t_prog *prog);
int		mouse_move_hook(int x, int y, t_prog *prog);
// MINIMAP
void	draw_minimap(t_prog *prog);

#endif