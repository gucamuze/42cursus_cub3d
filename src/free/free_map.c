/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:35:51 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/25 13:35:05 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_map_data(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->map || !prog->map->data)
		return ;
	while (prog->map->data[i])
	{
		free(prog->map->data[i]);
		i++;
	}
	free(prog->map->data);
}

/**
 * @brief This function frees the map structure and will keep reading
 * map file in case it isn't finished yet. This second part resolve an issue
 * of 1 leak of memory.
 * 
 * @param prog 
 */
void	free_map(t_prog *prog)
{
	char	*line;

	line = NULL;
	if (!prog->map)
		return ;
	if (prog->map->map_str)
		free(prog->map->map_str);
	if (prog->player)
		free(prog->player);
	line = get_next_line(prog->map->fd);
	while (line)
	{
		free(line);
		line = get_next_line(prog->map->fd);
	}
	free(line);
	close(prog->map->fd);
	free_map_data(prog);
	free(prog->map);
}
