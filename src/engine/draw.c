#include "cube.h"

static t_point	set_steps(t_point from, t_point to)
{
	t_point	steps;

	if (from.x < to.x)
		steps.x = 1;
	else
		steps.x = -1;
	if (from.y < to.y)
		steps.y = 1;
	else
		steps.y = -1;
	return (steps);
}

void	draw_line(t_img *img, t_point from, t_point to)
{
	t_point	delta;
	t_point steps;
	int		err;
	int		e2;
	int		color;

	delta.x = abs((int)(to.x - from.x));
	delta.y = -abs((int)(to.y - from.y));
	steps = set_steps(from, to);
	color = create_trgb(0, 255, 0, 0);
	err = delta.x + delta.y;
	my_mlx_pixel_put(img, from.x, from.y, color);
	while (from.x != to.x || from.y != to.y)
	{
		e2 = 2 * err;
		if (e2 >= delta.y)
		{
			err += delta.y;
			from.x += steps.x;
		}
		if (e2 <= delta.x)
		{
			err += delta.x;
			from.y += steps.y;
		}
		my_mlx_pixel_put(img, from.x, from.y, color);
	}
}