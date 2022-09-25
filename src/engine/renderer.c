#include "cube.h"

static bool	ray_is_facing_up(float angle)
{
	if (angle >= 0 && angle <= 180)
		return (true);
	return (false);
}

static void	chk_horizontal_intersecs(t_point *from, float angle)
{
	int y_a;
	int x_a;
	(void)from;

	if (ray_is_facing_up(angle) == true)
		y_a = -TILE_SIZE;
	else
		y_a = TILE_SIZE;
	x_a = 64 / tan(angle);
	y_a = x_a;
	x_a = y_a;
}

// what about angles close to 0 like 350 or 10? need to add some checks
void	render(t_prog *prog, t_player *player)
{
	int 	ray_n;
	float	ray_angle;
	float	degree_per_ray;
	(void)prog;

	ray_n = 0;
	degree_per_ray = (float)FOV_ANGLE / (float)SCREEN_WIDTH;
	printf("dpr = %f, define %d\n", degree_per_ray, DEGREE_PER_RAY);
	ray_angle = player->player_view_angle + HALF_FOV_ANGLE;
	while (ray_n++ < SCREEN_WIDTH)
	{
		//cast ray
		printf("casting ray %d, angle = %f\n", ray_n, ray_angle);
		chk_horizontal_intersecs(&player->pos, ray_angle);
		//calc distance from player to wall
		ray_angle -= degree_per_ray;
	}
}