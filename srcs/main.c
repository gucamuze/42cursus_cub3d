/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:25:57 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/25 21:14:36 by gucamuze         ###   ########.fr       */
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

void	init_player(t_data *data)
{
	int	x;
	int	y;
	int **map;

	y = 0;
	map = data->scene->map.map;
	while (y < data->scene->map.height)
	{
		x = 0;
		while (x < data->scene->map.width)
		{
			if (map[y][x] == 2)
			{
				data->player.posX = x;
				data->player.posY = y;
				data->player.fov_rad = data->scene->map.hero * 90;
			}
			x++;
		}
		y++;
	}
}

void	__DEBUG_map_dump(t_data *data)
{
	int	x;
	int	y;
	int **map;

	printf("MAP DUMP\n\n--------------------------------------------\n");
	y = 0;
	map = data->scene->map.map;
	while (y < data->scene->map.height)
	{
		x = 0;
		while (x < data->scene->map.width)
		{
			printf("%d", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n--------------------------------------------\n");
}

int render_next_frame(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, W_LEN, W_HGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, 
		&data->img.line_length, &data->img.endian);
	add_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img.img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
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
	data->scene = scene;
	init_player(data);
	mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx_ptr);
	cleanup(data);
	free(scene);
	return (0);
}