/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:25:49 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 15:39:17 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	init_img(t_scene *scene, t_data *data)
{
	int	width;
	int	height;
	int	i;

	scene->textures.addr[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			scene->textures.paths[0], &width, &height);
	scene->textures.addr[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			scene->textures.paths[1], &width, &height);
	scene->textures.addr[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			scene->textures.paths[2], &width, &height);
	scene->textures.addr[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			scene->textures.paths[3], &width, &height);
	i = 0;
	while (i < 4)
	{
		if (!scene->textures.addr[i])
			return (0);
		i++;
	}
	return (1);
}

void	destroy_img(t_scene *scene, t_data *data)
{
	if (scene->textures.addr[0])
		mlx_destroy_image(data->mlx_ptr, scene->textures.addr[0]);
	if (scene->textures.addr[1])
		mlx_destroy_image(data->mlx_ptr, scene->textures.addr[1]);
	if (scene->textures.addr[2])
		mlx_destroy_image(data->mlx_ptr, scene->textures.addr[2]);
	if (scene->textures.addr[3])
		mlx_destroy_image(data->mlx_ptr, scene->textures.addr[3]);
}
