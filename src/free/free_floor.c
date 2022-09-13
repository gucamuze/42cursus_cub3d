/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:19:20 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:15:05 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	free_floor(t_prog *prog)
{
	if (prog->textures->floor)
		free(prog->textures->floor);
	prog->textures->floor = NULL;
	return (0);
}
