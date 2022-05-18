/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:24:26 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/17 16:23:53 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_max(char *str, int fd)
{
	int	max;
	int	size;

	size = 0;
	max = len_ret(str);
	while (str)
	{
		if (str != NULL)
		{
			free(str);
			str = get_next_line(fd);
			if (str != NULL)
				size = len_ret(str);
			if (size > max)
				max = size;
		}
	}
	close (fd);
	return (max + 1);
}

static char	*find_map(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (str[0] == '1' || str[0] == ' ')
			return (str);
		free(str);
		str = get_next_line(fd);
	}
	return (NULL);
}

int	create_map(t_scene *scene, int fd, int *line)
{
	int		i;
	int		max;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	str = find_map(fd);
	max = check_max(str, fd);
	malloc_tab(scene, line);
	while (i < (*line))
	{
		malloc_line(&max, &size, scene, i);
		while (size < max - 1)
		{
			scene->map.map[i][size] = 42;
			size++;
		}
		scene->map.map[i][size] = (int) '\n';
		i++;
	}
	return (max);
}
