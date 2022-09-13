/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:18:32 by recarlie          #+#    #+#             */
/*   Updated: 2021/11/30 17:51:29 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		c_index;
	char	*s_ptr;
	int		found;

	s_ptr = (char *)s;
	found = 0;
	while (1)
	{
		c_index = 0;
		while (*s_ptr && *(s_ptr) != (t_byte)c && ++c_index)
			s_ptr++;
		if (*s_ptr == (t_byte)c)
			found = 1;
		if (*s_ptr == '\0')
			break ;
		s_ptr++;
	}
	if ((t_byte)c == '\0' && found)
		return (s_ptr);
	if (found && *(s_ptr - c_index - 1) == (t_byte)c)
		return (s_ptr - c_index - 1);
	return (NULL);
}
