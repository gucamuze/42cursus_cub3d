/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:19:08 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/18 13:44:11 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "parsing.h"
# include <math.h>

# define W_LEN 1920
# define W_HGHT 1080
# define MMAP_STRT 20

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*window;
	t_img	img;
	t_scene	*scene;
}				t_data;

// UI START //
// ui
void			*init_failure(t_data *mlx, int mode);
t_data			*init_ui();
void			add_minimap(t_data *mlx);
// hooks
int				keyboard_hook(int keycode, t_data *mlx);
int				mouse_hook(int button, int x, int y, t_data *mlx);
int				mouse_move_hook(int x, int y, t_data *mlx);
int				close_hook(t_data *mlx);
// UI END //

// ENGINE START //
// engine
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	init_img(t_data *mlx);
// colors
int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
// ENGINE END //

// TBD START //
// cleanup
void			cleanup(t_data *mlx);

// TBD END //

// GNL
# define BUFFER_SIZE 250
char			*get_next_line(int fd);
// gnl utils
char			*gnl_strjoin(char *s1, const char *s2);
char			*gnl_strchr(const char *s, int c);
char			*gnl_substr(const char *s, unsigned int start, size_t len);
char			*gnl_strdup(const char *s);
size_t			gnl_strlen(const char *s);

#endif