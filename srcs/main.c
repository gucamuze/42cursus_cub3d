/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:25:57 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/17 18:01:27 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	init_img(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->ptr, W_LEN, W_HGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, 
		&mlx->img.line_length, &mlx->img.endian);
	return (1);
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	t_mlx	*mlx;

	mlx = init_ui();
	scene = malloc(sizeof(t_scene));
	if (!mlx)
		return (1);
	if (parsing(ac, av, scene))
		printf("parsing ok");
	init_img(mlx);
	add_minimap(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	mlx_loop(mlx->ptr);
	cleanup(mlx);
	return (0);
}