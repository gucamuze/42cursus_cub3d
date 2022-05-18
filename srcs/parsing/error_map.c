/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:40:43 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 11:21:19 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_error(int i, t_scene *scene, int *line, int col)
{
	int	j;

	j = 0;
	while (j < col - 1)
	{
		if (scene->map.map[i][j] == 0 || scene->map.map[i][j] == 2)
		{
			if (scene->map.map[i][j + 1] == 42
				|| scene->map.map[i][j + 1] == 10)
			{
				free_tab(scene, (*line));
				return (0);
			}
			if (i == 0 && scene->map.map[i][j] == 0)
			{
				free_tab(scene, (*line));
				return (0);
			}
		}
		j++;
	}
	return (1);
}

static int	check_erro(int i, t_scene *scene, int *line, int col)
{
	int	j;

	j = 0;
	while (j < col - 1)
	{
		if ((scene->map.map[i][j] == 0
			|| scene->map.map[i][j] == 2))
		{
			if (i < (*line) - 1 && (scene->map.map[i + 1][j] == 42
				|| scene->map.map[i][j + 1] == 10))
			{
				free_tab(scene, (*line));
				return (0);
			}
			if (i == (*line) - 1)
			{
				free_tab(scene, (*line));
				return (0);
			}
		}
		j++;
	}
	return (1);
}

static int	check_er(int i, t_scene *scene, int *line, int col)
{
	int	j;

	j = 0;
	while (j < col - 1)
	{
		if (scene->map.map[i][j] == 42 || scene->map.map[i][j + 1] == 10)
		{
			if (scene->map.map[i][j + 1] == 0 || scene->map.map[i][j + 1] == 2)
			{
				free_tab(scene, (*line));
				return (0);
			}
		}
		if (i < (*line) - 1 && (scene->map.map[i][j] == 10
			|| scene->map.map[i][j] == 42))
		{
			if (scene->map.map[i + 1][j] == 0 || scene->map.map[i + 1][j] == 2)
			{
				free_tab(scene, (*line));
				return (0);
			}
		}
		j++;
	}
	return (1);
}

int	error_map(t_scene *scene, int *line, int col)
{
	int	i;

	i = 0;
	while (i < (*line))
	{
		if (!check_error(i, scene, line, col))
			return (0);
		if (!check_er(i, scene, line, col))
			return (0);
		if (!check_erro(i, scene, line, col))
			return (0);
		i++;
	}
	return (1);
}
