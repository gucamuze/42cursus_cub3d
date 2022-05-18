/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:37:44 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 11:21:34 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	malloc_tab(t_scene *scene, int *line)
{
	scene->map.map = (int **)malloc(sizeof(int *) * ((*line) + 1));
	scene->map.hero = -1;
	if (scene->map.map == NULL)
		return (0);
	return (1);
}

void	free_tab(t_scene *scene, int i)
{
	int	line;

	line = 0;
	while (line < i)
	{
		free(scene->map.map[line]);
		line++;
	}
	free(scene->map.map);
	scene->map.map = NULL;
}

int	malloc_line(int *size, int *j, t_scene *scene, int i)
{
	scene->map.map[i] = (int *)malloc(sizeof(int) * (*size));
	if (scene->map.map[i] == NULL)
	{
		free_tab(scene, i);
		return (0);
	}
	(*j) = 0;
	return (1);
}
