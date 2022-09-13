/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:47:01 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:16:26 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	init_textures(t_prog *prog)
{
	prog->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!prog->textures)
		return (0);
	prog->textures->north = NULL;
	prog->textures->south = NULL;
	prog->textures->west = NULL;
	prog->textures->east = NULL;
	prog->textures->floor = NULL;
	prog->textures->ceiling = NULL;
	return (1);
}
