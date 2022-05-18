/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:31:19 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 11:21:22 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*find_map(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (str != NULL && (str[0] != ' ' && str[0] != '1'))
		{
			free(str);
			str = get_next_line(fd);
		}
		if (str != NULL && (str[0] == ' ' || str[0] == '1'))
			return (str);
	}
	return (NULL);
}

int	len_ret(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static void	fill_info(t_scene *scene, char *str, int i, int j)
{
	scene->map.map[i][j] = 2;
	if (str[j] == 'N')
		scene->map.hero = 0;
	else if (str[j] == 'S')
		scene->map.hero = 1;
	else if (str[j] == 'E')
		scene->map.hero = 2;
	else
		scene->map.hero = 3;
}

static int	fill_line(t_scene *scene, char *str, int i, int j)
{
	if (str[j] == '1')
		scene->map.map[i][j] = 1;
	else if (str[j] == '0')
		scene->map.map[i][j] = 0;
	else if (str[j] == 'N' || str[j] == 'S' || str[j] == 'E' || str[j] == 'W')
	{
		if (scene->map.hero != -1)
		{
			free(str);
			free_tab(scene, scene->map.height);
			return (0);
		}
		fill_info(scene, str, i, j);
	}
	else if (str[j] == ' ')
		scene->map.map[i][j] = 42;
	else if (str[j] == '\n')
		return (1);
	else
	{
		free_tab(scene, scene->map.height);
		free(str);
		return (0);
	}
	return (1);
}

int	fill_map(t_scene *scene, int *line, int fd)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	str = find_map(fd);
	while (i < (*line))
	{
		size = len_ret(str) + 1;
		j = 0;
		while (j < size)
		{
			if (!fill_line(scene, str, i, j))
				return (0);
			j++;
		}
		free(str);
		str = get_next_line(fd);
		i++;
	}
	if (scene->map.hero == -1)
		return (0);
	scene->map.map[i] = NULL;
	return (1);
}
