/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:17:49 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/25 21:15:55 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_data *data, int keycode)
{
	int	moveX;
	int	moveY;
	int **map;

	__DEBUG_map_dump(data);
	map = data->scene->map.map;
	if (keycode == 119)
	{
		moveX = 0;
		moveY = -1;
	}
	else if (keycode == 97)
	{
		moveX = -1;
		moveY = 0;	
	}
	else if (keycode == 100)
	{
		moveX = 1;
		moveY = 0;
	}
	else
	{
		moveX = 0;
		moveY = 1;
	}
	printf("moveX = %d, moveY = %d\n", moveX, moveY);
	if (map[data->player.posY + moveY][data->player.posX + moveX] == 0)
	{
		map[data->player.posY][data->player.posX] = 0;
		data->player.posX += moveX;
		data->player.posY += moveY;
		map[data->player.posY][data->player.posX] = 2;
		__DEBUG_map_dump(data);
	}
}