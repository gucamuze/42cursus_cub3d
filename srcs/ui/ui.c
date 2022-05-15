/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:17:31 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/15 17:49:23 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mode 0 if malloc failed, 1 if init failed, 2 if window failed
void	*return_failure(t_mlx *mlx, int mode)
{
	(void)mode;
	if (mlx->ptr)
	{
		free(mlx->ptr);
	}
	if (mlx->ptr)
	{
		free(mlx->window);
	}
	free(mlx);
	return (NULL);
}

// 0 for horizontal, 1 for vertical
void	minimap_draw_line(t_mlx *mlx, int x, int y, int mode)
{
	int	i;
	int draw_x;
	int	draw_y;

	i = 10;
	draw_x = MMAP_STRT + (x * 10);
	draw_y = MMAP_STRT + (y * 10);
	while (i--)
	{
		my_mlx_pixel_put(&mlx->img, draw_x, draw_y, 0x00FFFFFF);
		if (mode)
			draw_y++;
		else
			draw_x++;
	}
}

void	add_minimap(t_mlx *mlx)
{
	int	x;
	int	y;
	char map[6][7] = {
		{'1','1','1','1','1','1', 0},
		{'1','0','0','1','0','1', 0},
		{'1','0','1','0','0','1', 0},
		{'1','1','0','0','2','1', 0},
		{'1','1','1','1','1','1', 0}, 
		{0}
	};

	x = 0;
	y = 0;
	(void)mlx;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				if (map[y][x + 1] && map[y][x + 1] == '1')
				;
					// minimap_draw_line(mlx, x, y, 0);
				if (map[y + 1][x] && map[y + 1][x] == '1')
				;
					// minimap_draw_line(mlx, x, y, 1);
				printf("1");
			}
			x++;
		}
		y++;
	}
}

t_mlx	*init_ui()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	// mlx->ptr = malloc(sizeof(void *));
	// mlx->window = malloc(sizeof(void *));
	// if (!mlx->ptr || !mlx->window)
	// 	return (return_failure(mlx, 0));
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (return_failure(mlx, 0));
	mlx->window = mlx_new_window(mlx->ptr, W_LEN, W_HGHT, "cub3d");
	mlx_key_hook(mlx->window, keyboard_hook, mlx);
	// mlx_mouse_hide(mlx->ptr, mlx->window);
	mlx_mouse_move(mlx->ptr, mlx->window, 960, 540);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	mlx_hook(mlx->window, 6, 1L<<6, mouse_move_hook, mlx);
	mlx_hook(mlx->window, 17, 1L>>17, close_hook, mlx);
	return (mlx);
}