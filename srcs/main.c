/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:25:57 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/18 13:44:39 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	init_img(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, W_LEN, W_HGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, 
		&data->img.line_length, &data->img.endian);
	return (1);
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	t_data	*data;

	scene = malloc(sizeof(t_scene));
	if (!parsing(ac, av, scene))
		return (1);
	data = init_ui();
	if (!data)
		return (1);
	init_img(data);
	data->scene = scene;
	add_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img.img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
	cleanup(data);
	free(scene);
	return (0);
}