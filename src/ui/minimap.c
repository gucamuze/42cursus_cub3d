#include "cube.h"

static int	get_cell_color(char cell)
{
	if (cell == '1')
		return (create_trgb(0, 255, 255, 255));
	else
		return (create_trgb(0, 0, 0, 0));
}

static void	draw_player(t_img *img, t_player *player)
{
	int	y_offset;
	int	x_offset;
	int y;
	int x;
	int player_color;

	y_offset = MINIMAP_OFFSET + player->pos.y * TILE_SIZE;
	x_offset = MINIMAP_OFFSET + player->pos.x * TILE_SIZE;
	player_color = create_trgb(0, 0, 255, 0);
	y = 0;
	while (y < PLAYER_SIZE)
	{
		x = 0;
		while (x < PLAYER_SIZE)
		{
			my_mlx_pixel_put(img, x_offset + x, y_offset + y, player_color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_cell(t_img *img, char cell, int y, int x)
{
	int	y_draw;
	int	x_draw;
	int	x_offset;
	int	y_offset;
	int	cell_color;

	y_offset = MINIMAP_OFFSET + TILE_SIZE * y + 1;
	x_offset = MINIMAP_OFFSET + TILE_SIZE * x + 1;
	cell_color = get_cell_color(cell);
	y_draw = 0;
	while (y_draw < TILE_SIZE)
	{
		x_draw = 0;
		while (x_draw < TILE_SIZE)
		{
			my_mlx_pixel_put(img, x_offset + x_draw, y_offset + y_draw, cell_color);
			x_draw++;
		}
		y_draw++;
	}
}

void	draw_minimap(t_prog *prog)
{
	char	**map;
	int		x;
	int		y;

	map = prog->map->data;
	y = 0;
	while (y < prog->map->y_max)
	{
		x = 0;
		while (x < prog->map->x_max)
		{
			draw_minimap_cell(prog->mlx->img, map[y][x], y, x);
			x++;
		}
		y++;
	}
	draw_player(prog->mlx->img, prog->player);
}