/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:17:20 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:14:57 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	free_ceiling(t_prog *prog)
{
	if (prog->textures->ceiling)
		free(prog->textures->ceiling);
	prog->textures->ceiling = NULL;
	return (0);
}
