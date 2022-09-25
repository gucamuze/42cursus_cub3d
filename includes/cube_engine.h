#ifndef CUBE_ENGINE_H
#define CUBE_ENGINE_H

typedef struct s_player	t_player;

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
// draw
void	draw_line(t_img *img, t_point from, t_point to);
// mlx_utils
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
// renderer
void	render(t_prog *prog, t_player *player);
// maths_functions
float	degrees_to_radians(float degree);
float	radians_to_degrees(float radians);
float	get_vector_magnitude(t_point a, t_point b);
// player_moves
void    player_move_forward(t_prog *prog);


#endif