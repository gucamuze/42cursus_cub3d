/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:34:11 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:20:58 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_valid_ceiling_norm(t_prog *prog, int i)
{
	while (prog->textures->ceiling[++i])
		if (prog->textures->ceiling[i] < 0 || prog->textures->ceiling[i] > 255)
			return (0);
	return (1);
}

int	check_valid_ceiling(t_prog *prog, char **arr)
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
		prog->textures->ceiling[i] = ft_atoi(arr[i]);
	if (!check_valid_ceiling_norm(prog, -1))
		return (custom_free_arr(arr));
	custom_free_arr(arr);
	return (1);
}

int	read_ceiling(t_prog *prog)
{
	char	*line;
	char	*tmp;

	line = NULL;
	tmp = NULL;
	prog->textures->ceiling = malloc(sizeof(int) * 3);
	if (!prog->textures->ceiling)
		return (0);
	tmp = get_next_line(prog->map->fd);
	if (!tmp)
		return (free_intarr(prog->textures->ceiling));
	if (ft_strncmp(tmp, "C ", 2) != 0)
		return (free_intarr(prog->textures->ceiling) + custom_free_str(tmp));
	line = ft_strdup(tmp + 2);
	if (!line || ft_strlen(line) < 2)
		return (free_intarr(prog->textures->ceiling) + custom_free_str(tmp));
	line[ft_strlen(line) - 1] = '\0';
	if (!check_valid_ceiling(prog, ft_split(line, ',')))
		return (custom_free_str(tmp) + custom_free_str(line));
	return (1 + custom_free_str(tmp) + custom_free_str(line));
}
