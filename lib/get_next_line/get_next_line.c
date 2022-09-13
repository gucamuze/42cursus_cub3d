/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:44:06 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/25 13:31:30 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_leftovers(int fd, char *leftover)
{
	char	*buffer;
	int		rode_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rode_bytes = 1;
	while (!ft_strchr(leftover, '\n') && rode_bytes != 0)
	{
		rode_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rode_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rode_bytes] = '\0';
		leftover = ft_strjoin(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*result;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover = get_leftovers(fd, leftover);
	if (!leftover)
		return (NULL);
	result = get_line(leftover);
	leftover = getrid_old_line(leftover);
	return (result);
}
