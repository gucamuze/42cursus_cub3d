/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:19:08 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/14 19:10:53 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define W_LEN 1920
# define W_HGHT 1080

typedef struct	s_img {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	t_img	img;
}				t_mlx;

// UI START //
// ui
void		*init_failure(t_mlx *mlx, int mode);
t_mlx		*init_ui();
// hooks
int			keyboard_hook(int keycode, t_mlx *mlx);
int			mouse_hook(int button, int x, int y, t_mlx *mlx);
// UI END //

// ENGINE START //
// engine
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
// colors
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
// ENGINE END //

// TBD START //
// cleanup
void		cleanup(t_mlx *mlx);

// TBD END //

#endif