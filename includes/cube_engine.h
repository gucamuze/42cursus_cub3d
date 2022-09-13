#ifndef CUBE_ENGINE_H
#define CUBE_ENGINE_H

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_point {
	float	x;
	float	y;
}	t_point;

void	game_loop(t_prog *prog);
// colors
int		create_trgb(int t, int r, int g, int b);
// mlx_utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
// maths_functions
float	degrees_to_radians(float degree);
float	radians_to_degrees(float radians);
// player_moves
void    player_move_forward(t_prog *prog);


#endif