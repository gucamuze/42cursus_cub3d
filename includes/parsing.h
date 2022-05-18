/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucamuze <gucamuze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:10:33 by malbrand          #+#    #+#             */
/*   Updated: 2022/05/18 13:02:17 by gucamuze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct s_map
{
	int	**map;
	int	height;
	int width;
	int hero;
}		t_map;

typedef struct s_textures
{
	char	*addresses[4];
	char	paths[4][300];
	int		sky_color;
	int		ground_color;
}		t_textures;

typedef struct s_scene
{
	t_textures	textures;
	t_map		map;
}			t_scene;

int		len_ret(char *s);
int		fill_path(char *str, t_scene *scene);
int		malloc_tab(t_scene *scene, int *line);
int		parsing_color(char *str, t_scene *scene);
int		parsing(int ac, char **av, t_scene *scene);
int		fill_map(t_scene *scene, int *line, int fd);
int		error_map(t_scene *scene, int *line, int col);
int		create_map(t_scene *scene, int fd, int *line);
int		malloc_line(int *size, int *j, t_scene *scene, int i);
int		check_texture(int fd, t_scene *scene, int line, char *s);

void	free_tab(t_scene *scene, int i);

#endif
