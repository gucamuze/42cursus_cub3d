/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:10:16 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/24 21:27:13 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include "get_next_line.h"
#include "libft.h"
#include "mlx.h"
#include "cube_ui.h"
#include "cube_engine.h"
#include "cube_player.h"
#include "cube_const_enum.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_textures {
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
}	t_textures;

typedef struct s_map {
	int		fd;
	int		x_max;
	int		y_max;
	char	*path;
	char	*map_str;
	char	**data;
	int		walled;
	int		floored;
	int		voided;
}	t_map;

typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_player	t_player;

typedef struct s_prog {
	t_map		*map;
	t_player	*player;
	t_textures	*textures;
	t_mlx		*mlx;
	bool		display_minimap;
}	t_prog;

// FREE
int			custom_free_str(char *str);
int			custom_free_arr(char **arr);
void		free_map(t_prog *prog);
void		free_textures(t_prog *prog);
int			free_floor(t_prog *prog);
int			free_ceiling(t_prog *prog);
int			free_mlx(t_prog *prog);
int			free_prog(t_prog *prog);
int			free_intarr(int *arr); // TODO =>
					// You can't have a function to free an int array without a size

// INIT
int			init_textures(t_prog *prog);
t_map		*init_map(t_prog *prog);

// PARSING
t_map		*read_map(t_prog *prog, char *map_path);
int			read_floor(t_prog *prog);
int			read_ceiling(t_prog *prog);
int			valid_map(t_prog *prog);
int			enclosed_wall(t_prog *prog, char *line, int i);
t_textures	*read_textures(t_prog *prog);

// ENGINE
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif