#ifndef CUBE_PLAYER_H
#define CUBE_PLAYER_H

#include "cube.h"

typedef struct s_point	t_point;

// move forward -> 1 forward, -1 backwards, 0 neither
// move lateral -> 1 right, -1 left, 0 neither
typedef struct s_player {
	t_point			pos;
	char			dir; // TODO: convert right away to rad value
	float			pov_rad;
	int				move_forward;
	int				move_lateral;
}   t_player;

#endif