/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:59:47 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/15 16:50:47 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keyboard_hook(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 65307)
	{
		cleanup(mlx);
		exit(0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 100 || keycode == 115)
	{
		printf("wasd => movement\n");
	}
	printf("Hello from key_hook!\nkeycode = %d\n", keycode);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)mlx;
	printf("button %d\tx = %d\ty=%d\n", button, x, y);
	return (1);
}

int mouse_move_hook(int x, int y, t_mlx *mlx)
{
	(void)mlx;(void)x;(void)y;
	// printf("mouse moving, x = %d\ty=%d\n", x, y);
	return (1);
}

int close_hook(t_mlx *mlx)
{
	cleanup(mlx);
	exit(0);
}