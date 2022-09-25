/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:32:18 by recarlie          #+#    #+#             */
/*   Updated: 2022/09/25 22:15:05 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	set_player(t_prog *prog, int y, int x, char dir)
{
	if (prog->player->pos.x != -1)
		return (0);
	prog->map->data[y][x] = 'P';
	prog->player->pos.x = x * TILE_SIZE;
	prog->player->pos.y = y * TILE_SIZE;
	if (dir == 'E')
		prog->player->player_view_angle = 0;
	else if (dir == 'N')
		prog->player->player_view_angle = 90;
	else if (dir == 'W')
		prog->player->player_view_angle = 180;
	else if (dir == 'S')
		prog->player->player_view_angle = 270;
	return (1);
}

int	process_other_line(t_prog *prog, char *line, int y)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_isalpha(line[i]) && !set_player(prog, y, i, line[i]))
		{
			printf("Line %d: multiple players on map\n", y);
			return (0);
		}
		if (!enclosed_wall(prog, line, y))
		{
			printf("Line %d: Floor must be enclosed\n", y);
			return (0);
		}
	}
	return (1);
}

int	process_first_last_line(char *line)
{
	int	i;
	int	walled;

	i = 0;
	walled = 0;
	if (ft_strchr(line, 'N') || ft_strchr(line, 'S') || ft_strchr(line, 'E')
		|| ft_strchr(line, 'W') || ft_strchr(line, FLOOR))
		return (0);
	while (line[i] == VOID)
		i++;
	if (line[i] == WALL && ft_strlen(line + i) > 1 && line[i + 1] == WALL
		&& line[i + 2] == WALL)
		walled = 1;
	return (walled);
}

int	process_line(t_prog *prog, char *line, int index)
{
	int	i;

	i = -1;
	if (ft_strlen(line) == 0)
	{
		printf("Line %d is empty\n", index);
		return (0);
	}
	while (line[++i])
	{
		if (line[i] != VOID && line[i] != WALL && line[i] != FLOOR
			&& line[i] != NORTH && line[i] != SOUTH && line[i] != EAST
			&& line[i] != WEST && line[i] != '\n')
		{
			printf("Invalid character '%c' on line %d\n", line[i], index);
			return (0);
		}
	}
	if (index == 0 || index == prog->map->y_max - 1)
		return (process_first_last_line(line));
	return (process_other_line(prog, line, index));
}

int	valid_map(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->map->y_max)
		if (!process_line(prog, prog->map->data[i], i))
			return (0);
	if (prog->player->pos.x == -1)
	{
		ft_putstr_fd("Error: no character on map\n", 2);
		return (0);
	}
	return (1);
}
