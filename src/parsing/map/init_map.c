/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:57:04 by recarlie          #+#    #+#             */
/*   Updated: 2022/09/25 21:58:06 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_map	*init_map(t_prog *prog)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_str = NULL;
	map->x_max = 0;
	map->y_max = 0;
	prog->textures = NULL;
	map->data = NULL;
	map->fd = -1;
	map->walled = 0;
	map->floored = 0;
	map->voided = 0;
	prog->player = malloc(sizeof(t_player));
	if (!prog->player)
	{
		free(map);
		return (NULL);
	}
	prog->player->pos.x = -1;
	prog->player->pos.y = -1;
	prog->player->player_view_angle = 0;
	prog->player->move_forward = 0;
	prog->player->move_lateral = 0;
	return (map);
}
