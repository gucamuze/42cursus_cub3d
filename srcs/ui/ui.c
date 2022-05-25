/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:17:31 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/25 21:12:35 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mode 0 if malloc failed, 1 if init failed, 2 if window failed
void	*return_failure(t_data *data, int mode)
{
	(void)mode;
	if (data->mlx_ptr)
	{
		free(data->mlx_ptr);
	}
	if (data->mlx_ptr)
	{
		free(data->window);
	}
	free(data);
	return (NULL);
}

// 0 for walls, 1 for hero
void	minimap_draw(t_data *data, int x, int y, int mode)
{
	int draw_x;
	int	draw_y;
	int	i;
	int j;
	int	size_of_walls;

	i = 0;
	size_of_walls = 10;
	draw_x = MMAP_STRT + (x * size_of_walls);
	draw_y = MMAP_STRT + (y * size_of_walls);
	while (i++ < size_of_walls)
	{
		j = 0;
		while (j++ < size_of_walls)
		{
			if (mode == 0)
				my_mlx_pixel_put(&data->img, draw_x + i, draw_y + j, 0x80FFFFFF);
			else
				my_mlx_pixel_put(&data->img, draw_x + i, draw_y + j, 0x80FFFF00);
		}
	}
}

int	add_minimap(t_data *data)
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
			if (map[y][x] == 1)
				minimap_draw(data, x, y, 0);
			if (map[y][x] == 2)
				minimap_draw(data, x, y, 1);
			x++;
		}
		y++;
	}
	return (1);
}

t_data	*init_ui()
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (return_failure(data, 0));
	data->window = mlx_new_window(data->mlx_ptr, W_LEN, W_HGHT, "cub3d");
	mlx_key_hook(data->window, keyboard_hook, data);
	// mlx_mouse_hide(data->mlx_ptr, data->window);
	mlx_mouse_move(data->mlx_ptr, data->window, 960, 540);
	mlx_mouse_hook(data->window, mouse_hook, data);
	mlx_hook(data->window, 6, 1L<<6, mouse_move_hook, data);
	mlx_hook(data->window, 17, 1L>>17, close_hook, data);
	return (data);
}