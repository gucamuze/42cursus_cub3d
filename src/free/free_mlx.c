#include "cube.h"

int	free_mlx(t_prog *prog)
{
	if (prog->mlx)
	{
		mlx_destroy_image(prog->mlx->ptr, prog->mlx->img->ptr);
		mlx_destroy_window(prog->mlx->ptr, prog->mlx->win);
		mlx_destroy_display(prog->mlx->ptr);
		free(prog->mlx->ptr);
		free(prog->mlx->img);
		free(prog->mlx);
	}
	return (0);
}