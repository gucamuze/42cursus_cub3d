/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:38:50 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/16 16:20:58 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	free_intarr(int *arr)
{
	if (arr)
		free(arr);
	return (0);
}

int	custom_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

int	custom_free_str(char *str)
{
	if (str)
		free(str);
	return (0);
}
