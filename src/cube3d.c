#include "cube.h"

void	print_map(t_prog *prog)
{
	int	i;

	i = 0;
	while (prog->map->data[i])
	{
		ft_putendl_fd(prog->map->data[i], 2);
		i++;
	}
}

// Cube3d takes a map file and renders it to the screen.
// The map file is a series of lines. The first lines are used to set the
// textures of each wall. The following lines are used to set the map.
// The map is a series of characters. 1 is a wall, 0 is a floor.
// The map is read from the top left corner and drawn to the screen from the
// bottom right corner.
int	main(int argc, char **argv)
{
	t_prog	prog;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./cube3d map.", 2);
		return (0);
	}
	if (!read_map(&prog, argv[1]))
	{
		ft_putendl_fd("cube3d: invalid map.", 2);
		free_textures(&prog);
		free_map(&prog);
		return (0);
	}
	print_map(&prog);
	printf("test=> %f\n", degrees_to_radians(180));
	if (init_ui(&prog))
		game_loop(&prog);
	free_prog(&prog);
	return (0);
}
