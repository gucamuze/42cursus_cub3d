/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:28:26 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 18:17:36 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_walled(t_prog *prog)
{
	prog->map->walled = 1;
	prog->map->voided = 0;
	prog->map->floored = 0;
}

int	ft_floored(t_prog *prog, int y, int x)
{
	prog->map->walled = 0;
	prog->map->voided = 0;
	prog->map->floored = 1;
	if (prog->map->data[y][x + 1] == VOID)
		return (0);
	if (prog->map->data[y][x - 1] == VOID)
		return (0);
	if (prog->map->data[y + 1][x] == VOID)
		return (0);
	if (prog->map->data[y - 1][x] == VOID)
		return (0);
	return (1);
}

int	process_char(t_prog *prog, char *line, int *i, int index)
{
	if (line[*i] == FLOOR && prog->map->voided == 0 && prog->map->walled == 0
		&& prog->map->floored == 0)
		return (0);
	if (line[*i] == VOID)
		prog->map->voided = 1;
	else if (line[*i] == WALL)
		ft_walled(prog);
	else if (line[*i] == FLOOR && !ft_floored(prog, index, *i))
		return (0);
	return (!(line[*i + 1] == '\0' && prog->map->floored == 1));
}

int	enclosed_wall(t_prog *prog, char *line, int index)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == VOID)
		i++;
	while (line[i])
	{
		if (!process_char(prog, line, &i, index))
			return (0);
		i++;
	}
	return (prog->map->walled);
}
