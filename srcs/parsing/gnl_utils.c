/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:30:23 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 11:23:55 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s)
{
	char	*cpy;
	int		i;

	i = -1;
	if (!s)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cpy)
		return (NULL);
	while (s[++i])
		cpy[i] = s[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (i < len && s[start] && start < ft_strlen(s))
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

char	*gnl_strchr(const char *s, int c)
{
	int		i;
	char	*s_cpy;

	i = 0;
	s_cpy = (char *)s;
	if (!s)
		return (NULL);
	while (s_cpy[i])
	{
		if (s_cpy[i] == c)
		{
			return (s_cpy + i);
		}
		i++;
	}
	if (c == '\0')
	{
		return (s_cpy + i);
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (gnl_strdup(s2));
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[j])
		s3[i++] = s1[j++];
	free(s1);
	s1 = NULL;
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}
