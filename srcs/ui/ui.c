/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:17:31 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/18 12:50:01 by gucamuze         ###   ########.fr       */
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

// 0 for horizontal, 1 for vertical
void	minimap_draw_line(t_data *data, int x, int y, int mode)
{
	int	i;
	int draw_x;
	int	draw_y;

	i = 10;
	draw_x = MMAP_STRT + (x * 10);
	draw_y = MMAP_STRT + (y * 10);
	while (i--)
	{
		my_mlx_pixel_put(&data->img, draw_x, draw_y, 0x00FFFFFF);
		if (mode)
			draw_y++;
		else
			draw_x++;
	}
}

void	add_minimap(t_data *data)
{
	int	x;
	int	y;
	char map[6][7] = {
		{'1','1','1','1','1','1', 0},
		{'0','1','0','1','0','1', 0},
		{'1','0','1','0','0','1', 0},
		{'1','1','0','0','2','1', 0},
		{'1','1','1','1','1','1', 0}, 
		{0, 0 , 0, 0, 0 ,0 ,0}
	};

	y = 0;
	while (map[y][0] != 0)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] == '1')
			{
				if (map[y][x + 1] && map[y][x + 1] == '1')
					minimap_draw_line(data, x, y, 0);
				if (map[y + 1][x] && map[y + 1][x] == '1')
					minimap_draw_line(data, x, y, 1);
				// printf("1");
			}
			x++;
		}
		y++;
	}
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