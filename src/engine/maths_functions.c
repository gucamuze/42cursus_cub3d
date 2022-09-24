#include "cube.h"

float	degrees_to_radians(float degree)
{
	return (degree * PI_DIV);
}

float	radians_to_degrees(float radians)
{
	return (radians * DIV_PI);
}

float	get_vector_magnitude(t_point a, t_point b)
{
	float x;
	float y;

	x = fabs(a.x - b.x);
	y = fabs(a.y - b.y);
	printf("x = %f, y = %f\n", x, y);
	return (sqrt(x * x + y * y));
}