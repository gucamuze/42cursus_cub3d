/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:11:07 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:16:55 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	free_textures(t_prog *prog)
{
	if (prog->textures)
	{
		if (prog->textures->north)
			free(prog->textures->north);
		if (prog->textures->south)
			free(prog->textures->south);
		if (prog->textures->west)
			free(prog->textures->west);
		if (prog->textures->east)
			free(prog->textures->east);
		free_ceiling(prog);
		free_floor(prog);
	}
	free(prog->textures);
}
