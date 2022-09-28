#ifndef CUBE_CONST_ENUM_H
# define CUBE_CONST_ENUM_H

// CUBE.H
enum e_colors {red, green, blue};

# define FLOOR '0'
# define WALL '1'
# define VOID '3'

# define NA -1
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

// CUBE_UI.H
// mlx hooks enum
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// Keycode defines
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define TAB_KEY 65289
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define PI_DIV M_PI / 180.0f
# define DIV_PI 180.0f / M_PI

// Player movement enum for bitwise mask operations
// /r/surdev watch me 
enum {
	FORWARD = 1, //0x1
	BACKWARDS = 2, // 0x10
	LEFT = 4, // 0x100
	RIGHT = 8 // 0x1000
};

// CUBE_ENGINE.H
// mlx sync defines
# define MLX_SYNC_IMAGE_WRITABLE	1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3
// Custom defines
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define TILE_SIZE 64
# define MINIMAP_SIZE_RATIO 0.05
# define MINIMAP_OFFSET 20 // in pixels
# define PLAYER_SIZE 2
# define PLAYER_HEIGHT 32
# define PLAYER_MOVESPEED 2
# define FOV_ANGLE 60
# define HALF_FOV_ANGLE (FOV_ANGLE / 2)
# define DEGREE_PER_RAY (FOV_ANGLE / SCREEN_WIDTH)
# define DIST_FROM_PPLANE (SCREEN_WIDTH / tan(HALF_FOV_ANGLE * PI_DIV))

#endif