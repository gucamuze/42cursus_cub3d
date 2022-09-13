/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:38:18 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:08:09 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/**
 * @brief Get a malloc'd string from the map and delete the '\n' at the end.
 * 
 * @param ID 
 * @param fd 
 * @return char* 
 */
char	*get_texture_path(char *ID, int fd)
{
	char	*tmp;
	char	*texture_path;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (ft_strncmp(line, ID, 2) != 0)
	{
		free(line);
		return (NULL);
	}
	tmp = ft_strchr(line, ' ');
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	texture_path = ft_strdup(tmp + 1);
	texture_path[ft_strlen(texture_path) - 1] = '\0';
	free(line);
	return (texture_path);
}

int	get_textures(t_prog *prog, int fd)
{
	prog->textures->north = get_texture_path("NO", fd);
	prog->textures->south = get_texture_path("SO", fd);
	prog->textures->west = get_texture_path("WE", fd);
	prog->textures->east = get_texture_path("EA", fd);
	if (!prog->textures->north || !prog->textures->south
		|| !prog->textures->west || !prog->textures->east)
		return (0);
	return (1);
}

t_textures	*read_textures(t_prog *prog)
{
	init_textures(prog);
	if (!prog->textures)
		return (NULL);
	if (!get_textures(prog, prog->map->fd))
	{
		free_textures(prog);
		return (NULL);
	}
	return (prog->textures);
}
