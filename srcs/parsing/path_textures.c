/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:28:58 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 11:21:44 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*strcpy_path(char *str, char *path)
{
	int	i;
	int	j;

	i = 2;
	if (str[2] != ' ')
		return (NULL);
	while (str[i] && str[i] == ' ')
		i++;
	j = 0;
	while (str[i + j] && str[i + j] != '\n')
	{
		path[j] = str[i + j];
		j++;
	}
	path[j] = '\0';
	return (path);
}

static int	check_path(t_scene *scene, char *str, int i)
{
	int	fd;

	if (scene->mlx.textures_paths[i][0] != '\0'
		|| strcpy_path(str, scene->mlx.textures_paths[i]) == NULL)
		return (0);
	fd = open(scene->mlx.textures_paths[i], O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	fill_path(char *str, t_scene *scene)
{
	if (str != NULL && str[0] == 'N' && str[1] == 'O')
	{
		if (!check_path(scene, str, 0))
			return (0);
	}
	else if (str != NULL && str[0] == 'S' && str[1] == 'O')
	{
		if (!check_path(scene, str, 1))
			return (0);
	}
	else if (str != NULL && str[0] == 'E' && str[1] == 'A')
	{
		if (!check_path(scene, str, 2))
			return (0);
	}
	else if (str != NULL && str[0] == 'W' && str[1] == 'E')
	{
		if (!check_path(scene, str, 3))
			return (0);
	}
	else
		return (0);
	return (1);
}
