/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:58:15 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 12:53:17 by gucamuze         ###   ########.fr       */
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
		else if ((str == NULL || str[(*i)] == ' '
				|| str[(*i)] == ',' || str[(*i)] == '\n') && j != 0)
			return (ft_atoi((const char *)color));
		else
			return (-1);
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

static void	init_rgb(int *r, int *g, int *b, int *i)
{
	(*r) = -1;
	(*g) = -1;
	(*b) = -1;
	(*i) = 1;
}

static int	check_end(char *str, int *i)
{
	while (str[(*i)] != '\n')
	{
		if (str[(*i)] != ' ')
			return (-1);
		(*i)++;
	}
	return (0);
}

int	parsing_color(char *str, t_scene *scene)
{
	int		r;
	int		g;
	int		b;
	int		i;

	init_rgb(&r, &g, &b, &i);
	if (!zap_space(str, &i, 1))
		return (-1);
	r = find_color(str, &i);
	if (!zap_space(str, &i, 0))
		return (-1);
	g = find_color(str, &i);
	if (!zap_space(str, &i, 0))
		return (-1);
	b = find_color(str, &i);
	if (check_end(str, &i) == -1)
		return (-1);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	if (str[0] == 'C' && scene->textures.sky_color == -1)
		scene->textures.sky_color = create_trgb(0, r, g, b);
	else if (str[0] == 'F' && scene->textures.ground_color == -1)
		scene->textures.ground_color = create_trgb(0, r, g, b);
	else
		return (-1);
	return (1);
}
