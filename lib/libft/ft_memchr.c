/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:43:23 by recarlie          #+#    #+#             */
/*   Updated: 2021/11/26 19:28:58 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte	*s_ptr;
	size_t	i;

	if (!n)
		return (0);
	s_ptr = (t_byte *)s;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] != (t_byte)c)
			i++;
		else
			return (s_ptr + i);
	}
	return (0);
}
