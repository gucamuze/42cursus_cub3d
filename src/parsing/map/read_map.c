/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:27:21 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/23 17:24:03 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	reopen_map_to_map_str(t_prog *prog)
{
	int		i;
	char	*line;

	close(prog->map->fd);
	prog->map->fd = open(prog->map->path, O_RDONLY);
	if (prog->map->fd == -1)
		return (0);
	i = -1;
	line = get_next_line(prog->map->fd);
	while (line && ++i < 7)
	{
		free(line);
		line = get_next_line(prog->map->fd);
	}
	if (line)
		free(line);
	return (1);
}

int	set_map_length(t_prog *prog)
{
	int		i;
	char	*line;

	line = get_next_line(prog->map->fd);
	if (line == NULL)
		return (0);
	i = -1;
	while (line && ++i >= 0)
	{
		free(line);
		line = get_next_line(prog->map->fd);
		if ((int)ft_strlen(line) > prog->map->x_max)
			prog->map->x_max = (int)ft_strlen(line);
	}
	free(line);
	prog->map->y_max = i;
	reopen_map_to_map_str(prog);
	return (1);
}

int	save_map(t_prog *prog)
{
	int		i;
	int		j;
	char	*line;

	set_map_length(prog);
	prog->map->data = malloc(sizeof(char *) * (prog->map->y_max + 1));
	if (!prog->map->data)
		return (0);
	i = -1;
	while (++i < prog->map->y_max)
	{
		line = get_next_line(prog->map->fd);
		prog->map->data[i] = ft_calloc(prog->map->x_max + 1, sizeof(char));
		if (!prog->map->data[i])
			return (0);
		ft_strlcat(prog->map->data[i], line, prog->map->x_max + 1);
		prog->map->data[i][ft_strlen(line) - 1] = '\0';
		free(line);
		j = -1;
		while (prog->map->data[i][++j])
			if (prog->map->data[i][j] == ' ')
				prog->map->data[i][j] = VOID;
	}
	prog->map->data[i] = NULL;
	return (1);
}

int	open_map(t_prog *prog, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("cube3d: couldn't open map file", 2);
		return (0);
	}
	prog->map->fd = fd;
	return (1);
}

t_map	*read_map(t_prog *prog, char *map_path)
{
	prog->map = init_map(prog);
	if (!prog->map)
		return (NULL);
	prog->map->path = map_path;
	if (!open_map(prog, map_path))
		return (NULL);
	prog->textures = read_textures(prog);
	if (!prog->textures)
		return (NULL);
	if (!read_floor(prog) || !read_ceiling(prog))
		return (NULL);
	if (!save_map(prog))
		return (NULL);
	if (!valid_map(prog))
		return (NULL);
	return (prog->map);
}
