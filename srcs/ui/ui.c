/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:17:31 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/14 19:10:42 by gucamuze         ###   ########.fr       */
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
	mlx_mouse_hide(mlx->ptr, mlx->window);
	mlx_mouse_hook(mlx->window, mouse_hook, mlx);
	return (mlx);
}