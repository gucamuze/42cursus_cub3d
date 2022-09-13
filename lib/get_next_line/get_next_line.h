/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:41:38 by recarlie          #+#    #+#             */
/*   Updated: 2022/08/09 16:14:45 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_byte;
char	*get_next_line(int fd);
char	*get_line(char *str);
char	*getrid_old_line(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strjoin(char *s1, char *s2);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif