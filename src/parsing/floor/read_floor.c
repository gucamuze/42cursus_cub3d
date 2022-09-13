/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:56:21 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:20:58 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_valid_floor_norm(t_prog *prog, int i)
{
	while (prog->textures->floor[++i])
		if (prog->textures->floor[i] < 0 || prog->textures->floor[i] > 255)
			return (0);
	return (1);
}

int	check_valid_floor(t_prog *prog, char **arr)
{
	int	i;
	int	j;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	if (i != 3)
		return (0);
	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			if (!ft_isdigit(arr[i][j]))
				return (custom_free_arr(arr));
	}
	i = -1;
	while (arr[++i])
		prog->textures->floor[i] = ft_atoi(arr[i]);
	if (!check_valid_floor_norm(prog, -1))
		return (custom_free_arr(arr));
	custom_free_arr(arr);
	return (1);
}

int	read_floor(t_prog *prog)
{
	char	*line;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	prog->textures->floor = malloc(sizeof(int) * 3);
	if (!prog->textures->floor)
		return (0);
	tmp = get_next_line(prog->map->fd);
	if (!tmp)
		return (0);
	free(tmp);
	tmp = get_next_line(prog->map->fd);
	if (ft_strncmp(tmp, "F ", 2) != 0)
		return (free_intarr(prog->textures->floor) + custom_free_str(tmp));
	line = ft_strdup(tmp + 2);
	if (!line || ft_strlen(line) < 2)
		return (free_intarr(prog->textures->floor) + custom_free_str(tmp));
	line[ft_strlen(line) - 1] = '\0';
	if (!check_valid_floor(prog, ft_split(line, ',')))
		return (custom_free_str(tmp) + custom_free_str(line));
	return (1 + custom_free_str(tmp) + custom_free_str(line));
}
