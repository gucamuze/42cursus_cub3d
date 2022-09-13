/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:17:52 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:50:27 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	free_prog(t_prog *prog)
{
	free_textures(prog);
	free_map(prog);
	free_mlx(prog);
	return (0);
}
