/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:22:40 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/17 16:25:07 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	free_close(char *s, int fd, int ret)
{
	free(s);
	close(fd);
	return (ret);
}

static char	*free_get_str(char *str, int fd)
{
	free(str);
	str = get_next_line(fd);
	return (str);
}

static char	*count_line(char *str, int fd, int *line)
{
	while (str != NULL && (str[0] == '1' || str[0] == ' '))
	{
		(*line)++;
		str = free_get_str(str, fd);
	}
	return (str);
}

int	check_texture(int fd, t_scene *scene, int line, char *str)
{
	while (str)
	{
		if (str != NULL && (str[0] == 'N' || str[0] == 'S'
				|| str[0] == 'W' || str[0] == 'E') && line == 0)
		{
			if (!fill_path(str, scene))
				return (free_close(str, fd, 0));
			str = free_get_str(str, fd);
		}
		else if (str != NULL && (str[0] == 'F' || str[0] == 'C') && line == 0)
		{
			if (parsing_color(str, scene) == -1)
				return (free_close(str, fd, 0));
			str = free_get_str(str, fd);
		}
		else if (str != NULL && (str[0] == '1' || str[0] == ' ') && line == 0)
			str = count_line(str, fd, &line);
		else if (str != NULL && line != 0 && str[0] != '\n')
			return (free_close(str, fd, 0));
		else if (str != NULL && str[0] == '\n')
			str = free_get_str(str, fd);
		else
			return (free_close(str, fd, 0));
	}
	return (free_close(str, fd, line));
}
