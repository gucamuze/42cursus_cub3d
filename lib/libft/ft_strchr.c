/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:15:55 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/09 14:24:47 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char *)s;
	while (*s_ptr && *s_ptr != (t_byte)c)
		s_ptr++;
	if (*s_ptr == (t_byte)c)
		return (s_ptr);
	return (0);
}
