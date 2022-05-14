/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:02:14 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/14 18:22:43 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->window);
	mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	free(mlx);
}