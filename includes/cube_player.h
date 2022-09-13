#ifndef CUBE_PLAYER_H
#define CUBE_PLAYER_H

#include "cube.h"

typedef struct s_point	t_point;

typedef struct s_player {
	t_point			pos;
	char			dir; // TODO: convert right away to rad value
	float			pov_rad;
	__uint8_t		moves;
}   t_player;

#endif