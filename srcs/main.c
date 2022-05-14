/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:25:57 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/14 18:21:59 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	init_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, W_LEN, W_HGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, 
		&mlx->img.line_length, &mlx->img.endian);
	my_mlx_pixel_put(&mlx->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	(void)ac;
	(void)av;
	mlx = init_ui();
	if (!mlx)
		return (1);
	if (!init_img(mlx))
		return (1);
	cleanup(mlx);
	return (0);
}