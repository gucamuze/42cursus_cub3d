#include "cube.h"

static bool	ray_is_facing_up(float angle)
{
	if (angle >= 0 && angle <= 180)
		return (true);
	return (false);
}

static bool ray_is_facing_right(float angle)
{
	if (angle > 90 && angle <= 270)
		return (false);
	return (true);
}

static t_point	get_horizontal_wall_hit(t_map *map, t_point from, float angle)
{
	t_point	dest;
	float	x_step;
	int		y_step;

	y_step = TILE_SIZE;
	if (ray_is_facing_up(angle))
		y_step = -TILE_SIZE;
	x_step = TILE_SIZE / tan(degrees_to_radians(angle));
	dest.y = floor(from.y / 64) * 64 + y_step;
	dest.x = from.x + (from.y - dest.y) / tan(degrees_to_radians(angle));
	while (map->data[dest.y>>6][dest.x>>6] != '1')
	{
		dest.y += y_step;
		dest.x += x_step;
	}
	return (dest);
}

static t_point	get_vertical_wall_hit(t_map *map, t_point from, float angle)
{
	t_point	dest;
	float	x_step;
	int		y_step;

	x_step = -TILE_SIZE;
	if (ray_is_facing_right(angle))
		x_step = TILE_SIZE;
	y_step = TILE_SIZE / tan(degrees_to_radians(angle));
	dest.x = floor(from.x / 64) * 64 + x_step;
	dest.y = from.y + (from.x - dest.x) / tan(degrees_to_radians(angle));
	while (map->data[dest.y>>6][dest.x>>6] != '1')
	{
		dest.y += y_step;
		dest.x += x_step;
	}
	return (dest);
}

static void	calc_closest_wall(t_point player, t_ray *ray)
{
	float	horizontalDist;
	float	verticalDist;

	horizontalDist = get_hypothenuse_len(player, ray->horizontal_hit);
	verticalDist = get_hypothenuse_len(player, ray->vertical_hit);
	if (horizontalDist > verticalDist)
		ray->closestDist = horizontalDist;
	else
		ray->closestDist = verticalDist;
}

void	draw_ray(t_prog *prog, t_ray *ray, int ray_n)
{
	(void)prog;(void)ray;(void)ray_n;
	int		proj_height;
	int		draw_y;

	// proj_height = (ray->closestDist * SCREEN_WIDTH) / (SCREEN_WIDTH >> 1);
	proj_height = TILE_SIZE / ray->closestDist * DIST_FROM_PPLANE;
	if (proj_height>800)
		proj_height = 800;
	draw_y = (int)(SCREEN_WIDTH - proj_height) >> 1;
	// printf("wall %f units awat height in pixels %d\n", ray->closestDist, proj_height);
	while (proj_height--)
	{
		my_mlx_pixel_put(prog->mlx->img, ray_n, draw_y, 0xFFFFFF);
		draw_y++;
	}
	// // 0 unit away | 500 units away
	// SCREEN_SIZE | SCREEN_SIZE/2
}

// what about angles close to 0 like 350 or 10? need to add some checks
void	render(t_prog *prog, t_player *player)
{
	int 	ray_n;
	float	ray_angle;
	float	degree_per_ray;
	t_ray	rays[SCREEN_WIDTH];

	ray_n = 0;
	degree_per_ray = (float)FOV_ANGLE / (float)SCREEN_WIDTH;
	ray_angle = player->player_view_angle + HALF_FOV_ANGLE;
	if (ray_angle >= 360)
		ray_angle -= 360;
	while (ray_n < SCREEN_WIDTH)
	{
		//cast ray horizontal and vertical
		rays[ray_n].horizontal_hit = get_horizontal_wall_hit(prog->map, player->pos, ray_angle);
		rays[ray_n].vertical_hit = get_vertical_wall_hit(prog->map, player->pos, ray_angle);
		// calc closest wall
		calc_closest_wall(player->pos, &rays[ray_n]);
		// increment angle and continue
		// printf("done casting ray %d, closest wall is %f units away\n", ray_n, rays[ray_n].closestDist);
		draw_ray(prog, &rays[ray_n], ray_n);
		ray_angle -= degree_per_ray;
		if (ray_angle < 0)
			ray_angle += 360;
		ray_n++;
	}
	// sleep(5);
}