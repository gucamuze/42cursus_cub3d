#include "cube.h"

float	degrees_to_radians(float degree)
{
	return (degree * PI_DIV);
}

float	radians_to_degrees(float radians)
{
	return (radians * DIV_PI);
}

float	get_hypothenuse_len(t_point a, t_point b)
{
	int x;
	int y;

	x = abs(a.x - b.x);
	y = abs(a.y - b.y);
	return (sqrt(x * x + y * y));
}