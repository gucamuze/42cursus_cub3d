/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:43:58 by recarlie          #+#    #+#             */
/*   Updated: 2021/11/25 11:47:12 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	t_byte	*b_ptr;

	i = 0;
	b_ptr = (t_byte *)b;
	while (i < len)
	{
		b_ptr[i] = (t_byte)c;
		i++;
	}
	return (b);
}
