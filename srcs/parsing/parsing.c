/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:12:34 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 12:54:47 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_fd(char **av, int *fd)
{
	int	size;

	size = ft_strlen(av[1]);
	if (size < 4 || av[1][size - 1] != 'b' || av[1][size - 2] != 'u'
		|| av[1][size - 3] != 'c' || av[1][size - 4] != '.')
	{
		printf("Error\nIsn't a .cub\n");
		return (-1);
	}
	(*fd) = open(av[1], O_RDONLY);
	if ((*fd) == -1)
	{
		printf("Error\nThe file doesn't exist\n");
		close(*fd);
		return (-1);
	}
	return (*fd);
}

void	init_info(t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 300)
			scene->textures.paths[i][j++] = '\0';
		i++;
	}
	scene->textures.sky_color = -1;
	scene->textures.ground_color = -1;
}

static int	check_data(int line, t_scene *scene)
{
	int	i;

	i = 0;
	if (line == 0)
		return (0);
	if (scene->textures.paths[0][0] == '\0'
		&& scene->textures.paths[1][0] == '\0'
		&& scene->textures.paths[2][0] == '\0'
		&& scene->textures.paths[3][0] == '\0')
		i++;
	else if (scene->textures.paths[0][0] == '\0'
			|| scene->textures.paths[1][0] == '\0'
			|| scene->textures.paths[2][0] == '\0'
			|| scene->textures.paths[3][0] == '\0')
		return (0);
	if (scene->textures.sky_color == -1 && scene->textures.ground_color == -1)
		i++;
	else if (scene->textures.sky_color == -1 || scene->textures.ground_color == -1)
		return (0);
	return (i + 1);
}

static int	print_error(int er)
{
	if (er == 1)
		printf("Error\nWrong number of argument\n");
	else if (er == 2)
		printf("Error\nThe file is not correct\n");
	else if (er == 3)
		printf("Error\nInvalid map\n");
	else if (er == 4)
		printf("Error\nInvalid map_bis\n");
	return (0);
}

int	parsing(int ac, char **av, t_scene *scene)
{
	int		fd;

	scene->map.height = 0;
	init_info(scene);
	if (ac != 2)
		return (print_error(1));
	if (check_fd(av, &fd) == -1)
		return (0);
	scene->map.height = check_texture(fd, scene,
			scene->map.height, get_next_line(fd));
	if (scene->map.height == 0)
		return (print_error(2));
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!check_data(scene->map.height, scene))
		return (print_error(2));
	scene->map.width = create_map(scene, fd, &scene->map.height);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (!fill_map(scene, &scene->map.height, fd))
		return (print_error(3));
	close(fd);
	if (!error_map(scene, &scene->map.height, scene->map.width))
		return (print_error(4));
	return (1);
}
