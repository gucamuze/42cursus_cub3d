/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:58:15 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/17 16:23:42 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_color(char *str, int *i)
{
	int		j;
	int		ret;
	char	color[100];

	j = 0;
	while (j < 100)
		color[j++] = '\0';
	j = 0;
	while (str[(*i)])
	{
		if (str[(*i)] <= '9' && str[(*i)] >= '0')
		{
			color[j] = str[(*i)];
			(*i)++;
			j++;
		}
		else if (str == NULL || str[(*i)] == ' '
			|| str[(*i)] == ',' || str[(*i)] == '\n')
		{
			ret = ft_atoi((const char *)color);
			return (ret);
		}
	}
	ret = ft_atoi((const char *)color);
	return (ret);
}

static int	zap_space(char *str, int *i, int verif)
{
	if (verif == 1 && str[(*i)] != ' ')
		return (0);
	while (str[(*i)] == ' ')
		(*i)++;
	if (str[(*i)] != ',' && verif == 0)
		return (0);
	if (verif == 0)
		(*i)++;
	while (str[(*i)] == ' ')
		(*i)++;
	if (str[(*i)] && str[(*i)] < '0' && str[(*i)] > '9')
		return (0);
	return (1);
}

int	parsing_color(char *str, t_scene *scene)
{
	int		r;
	int		g;
	int		b;
	int		i;

	i = 1;
	if (!zap_space(str, &i, 1))
		return (-1);
	r = find_color(str, &i);
	if (!zap_space(str, &i, 0))
		return (-1);
	g = find_color(str, &i);
	if (!zap_space(str, &i, 0))
		return (-1);
	b = find_color(str, &i);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	if (str[0] == 'C' && scene->mlx.sky_color == -1)
		scene->mlx.sky_color = create_trgb(0, r, g, b);
	else if (str[0] == 'F' && scene->mlx.ground_color == -1)
		scene->mlx.ground_color = create_trgb(0, r, g, b);
	else
		return (-1);
	return (1);
}
