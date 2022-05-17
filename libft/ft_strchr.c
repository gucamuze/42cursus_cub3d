/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 03:07:06 by gucamuze          #+#    #+#             */
/*   Updated: 2022/05/17 18:07:33 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	index;

	index = 0;
	if (s)
	{
		while (*(s + index))
		{
			if (*(s + index) == c)
				return ((char *)(s + index));
			index++;
		}
		if (*(s + index) == '\0' && c == '\0')
			return ((char *)(s + index));
	}
	return (NULL);
}
