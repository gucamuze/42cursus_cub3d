/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:25:02 by recarlie          #+#    #+#             */
/*   Updated: 2021/11/25 14:18:15 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_ptr;
	char	*str;
	int		i;

	s1_ptr = (char *)s1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*(s1_ptr + i))
	{
		str[i] = *(s1_ptr + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
