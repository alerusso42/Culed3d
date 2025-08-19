/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/04 10:20:09 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <bsd/string.h>
# include <ctype.h>
# include <limits.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>
# include "./minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"	

# define RST		"\033[0m" /* Reset to default color */
# define RED		"\033[1;31m" /* Bold Red */
# define BGREEN		"\033[1;32m" /* Bold Green */
# define BYELLOW	"\033[1;33m" /* Bold Yellow*/
# define BBLUE		"\033[1;34m" /* Bold Blue*/
# define BMAGENTA	"\033[1;35m" /* Bold Magenta*/
# define BCYAN		"\033[1;36m" /* Bold Cyan*/
# define BWHITE		"\033[1;37m" /* Bold White*/

# define FPS 60
# define FRAME_TIME (1000000 / FPS)

#ifndef DEBUG
# define DEBUG true
# endif
# define VALID_CHARS " 01NSEWD"
# define PLAYER_CHARS "NSEWP"
# define FFILL_CHARS "0NSEW"

# define SCREEN_TXTR "textures/screen.xpm"
# define PLAYER_TXTR "textures/pisnelo.xpm"
# define WALL_TXTR "textures/mini_wall.xpm"
# define DOOR_TXTR "textures/gabibbo.xpm"
# define CROSS_TXTR "textures/Crosshair.xpm"
# define MINI_PLAYER_0_TXTR "textures/mini_player_0.xpm"
# define MINI_PLAYER_20_TXTR "textures/mini_player_20.xpm"
# define MINI_PLAYER_40_TXTR "textures/mini_player_40.xpm"
# define MINI_PLAYER_60_TXTR "textures/mini_player_60.xpm"
# define MINI_PLAYER_80_TXTR "textures/mini_player_80.xpm"
# define MINI_PLAYER_100_TXTR "textures/mini_player_100.xpm"
# define MINI_PLAYER_120_TXTR "textures/mini_player_120.xpm"
# define MINI_PLAYER_140_TXTR "textures/mini_player_140.xpm"
# define MINI_PLAYER_160_TXTR "textures/mini_player_160.xpm"
# define MINI_PLAYER_180_TXTR "textures/mini_player_180.xpm"
# define MINI_PLAYER_200_TXTR "textures/mini_player_200.xpm"
# define MINI_PLAYER_220_TXTR "textures/mini_player_220.xpm"
# define MINI_PLAYER_240_TXTR "textures/mini_player_240.xpm"
# define MINI_PLAYER_260_TXTR "textures/mini_player_260.xpm"
# define MINI_PLAYER_280_TXTR "textures/mini_player_280.xpm"
# define MINI_PLAYER_300_TXTR "textures/mini_player_300.xpm"
# define MINI_PLAYER_320_TXTR "textures/mini_player_320.xpm"
# define MINI_PLAYER_340_TXTR "textures/mini_player_340.xpm"
# define MINI_PLAYER_360_TXTR "textures/mini_player_360.xpm"

# define HIMG 64
# define WIMG 64
# define WIMG_MINIMAP 24
# define HIMG_MINIMAP 24
# define MINIMAP 15
# define TXTR 300
# define PIX_PLAYER HIMG + (HIMG / 2)
# define PLAYER_OFFSET (HIMG / 2)
# define SHADE_INTENSITY 30
# define WSCREEN 1200
# define HSCREEN 1080

//# define RADIANT 0.008726

/*
	180 degrees are PI radiant.
	Degree changes every PI / 180.
*/
# define RADIANT (PI / 180)

//	see RADIANT for explaination.
//	putting it to 1 makes the line sensibility to 1 degree.
//	putting it to 20 makes the line sensibility to (1 degree / 20), and so on.
//NOTE [L_A: 30; FOV: 64]
# define ANGULAR_SPEED RADIANT * 2.5
# define PLAYER_SPEED 5
# define SENSITIVITY 0.4

//	FOV (=Field Of View) represents the angle of the player vision.
# define FOV 60


# define PI 3.1415926

//FIXME	This flag is in debug state.
# define SPEED 0.01
# define ANIMATION_SPEED 12
# define TANTA 50

# define ANGLE_0 0
# define ANGLE_1 RADIANT
# define ANGLE_20 (RADIANT * 20)
# define ANGLE_90 (PI / 2)
# define ANGLE_180 (PI)
# define ANGLE_270 (ANGLE_90 * 3)
# define ANGLE_360 (ANGLE_90 * 4)

typedef struct timeval		t_time;

typedef struct s_texture
{
	void	*ptr;
	char	*path;
	char	*xpm;
	double	shade;
	int		bpp;
	int		size[2];
	int		endian;
	int		offset;
	char	filters;
}	t_txtr;

typedef struct s_entity
{
	double	curr_x;
	double	curr_y;
	double	pov[2];
	double	speed;
	int		screen[2];
	int		map[2];
	int		*frames;
	int		f_curr;
	int		f_time;
	int		f_elapsed;
	int		vite_rimaste;
	char	type;
	char	input;
	bool	render;
}	t_entity;


typedef struct s_data
{
	t_entity	player;
	t_time		start;
	t_entity	*doors;
	void		*mlx;
	void		*win;
	t_txtr	*txtr;
	char		*screen;
	char		**map;
	char		*txtr_north;
	char		*txtr_west;
	char		*txtr_south;
	char		*txtr_east;
	char		*txtr_floor;
	char		*txtr_ceiling;
	char		*txtr_player;
	char		*img_ptr;
	int			img_data[3];
	int			bpp;
	int			size_line;
	int			endian;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	int			max_x;
	int			max_y;
	int			column;
	int			color;
}	t_data;

typedef enum e_timecode
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}	t_timecode;

enum e_textures
{
	SCREEN,
	NORTH,
	EAST,
	SOUTH,
	WEST,
	CROSSHAIR,
	PLAYER,
	WALL,
	DOOR,
	M_PLAYER_0,
	M_PLAYER_20,
	M_PLAYER_40,
	M_PLAYER_60,
	M_PLAYER_80,
	M_PLAYER_100,
	M_PLAYER_120,
	M_PLAYER_140,
	M_PLAYER_160,
	M_PLAYER_180,
	M_PLAYER_200,
	M_PLAYER_220,
	M_PLAYER_240,
	M_PLAYER_260,
	M_PLAYER_280,
	M_PLAYER_300,
	M_PLAYER_320,
	M_PLAYER_340,
	TEXTURES_NUM,
};

enum	e_errors
{
	E_MALLOC = 1,
	E_OPEN,
	E_ARGC,
	E_EXT,
	E_TYPE,
	E_FORMAT,
	E_TEXTURE,
	E_NO_MAP,
	E_CHAR,
	E_NO_PLAYER,
	E_MULTIPLAYER,
	E_INVALID_MAP,
	E_MLX_TEXTURE,
	E_INVALID_PATH,
	E_INVALID_DOOR,
};

enum	e_type_identifers
{
	NO = 0,
	SO = 2,
	EA = 4,
	WE = 8,
	F,
	C,
	TYPE_IDENTIFIERS_NUM = 6,
};

enum	e_texture_filters
{
	FILTER_ON = 255,
	FILTER_BLACK_WHITE = 1,
};

enum e_utils
{
	X = 0,
	Y = 1,
	COS = 0,
	SIN = 1,
	POSITIVE = 1,
	NEGATIVE = -1,
	LEFT = 1,
	RIGHT = 2,
	UP = 4,
	DOWN = 8,
	MOVEMENT = LEFT | RIGHT | UP | DOWN,
	R_LEFT = 16,
	R_RIGHT = 32,
	ROTATION = R_LEFT | R_RIGHT,
	BPP = 0,
	SIZE = 1,
	ENDIAN = 2,
	ENTITY_NOT_FOUND = -1,
	ENTITY_END = 0,
	ENTITY_DOOR = 0,
	ENTITY_ENEMY = 1,
	DOOR_OPENED = 'D',
	DOOR_CLOSED = 'O',
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	MOUSE_MIDDLE = 2,
	MOUSE_UP = 4,
	MOUSE_DOWN = 5,
};

void	parsing(t_data *data, int argc, char **argv);
void	error(t_data *data, int err, char *file);
void	lets_start_the_party(t_data *data);
void	spread_democracy(t_data *data);
void	free_texture(t_data *data);

//SECTION	input

void	move(t_data *data, t_entity *entity, double angle[]);
void	rotate(t_data *data, t_entity *entity);
int		commands_release(int keycode, t_data *data);
int		commands_press(int keycode, t_data *data);
void	init_doors(t_data *data, int n_doors);
int		ft_cross_close(t_data *data);
void	mouse_input(t_data *data);
int		move_player(t_data *data);
void	interact(t_data *data);
void	init_player(t_data *data);

//SECTION	parsing

void	check_textures(t_data *data, int fd);
void	get_type(t_data *data, int fd);
void	check_map_access(t_data *data);
void	get_map(t_data *data, int fd);
void	check_chars(t_data *data);
void	check_walls(t_data *data);
void	check_doors(t_data *data);
void	parse_map(t_data *data);
void	finish_him(int fd);

//SECTION	utils

t_txtr	*texture_finder(t_data *data, double ray_angle, int hit_x, int hit_y);
void	init_line_data(t_data *data, t_entity *entity_data, double pov_x);
int		wall_height(t_data *data, double x, double y, double ray_angle);
void	update_delta(double pov, double *delta_x, double *delta_y);
int		which_entity(t_data *data, int x, int y, int entity_type);
int		wall_face(t_data * data, t_entity *entity, double angle);
void	txtr_filters(t_txtr *txtr, int *r, int *g, int *b);
int		the_wall_checker(t_entity *entity, t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
bool	collision_entity(t_data *data, int x, int y);
double	ray_lenght(t_data *data, int rx, int ry);
double	safe_division(double delta, double sum);
bool	value_changed(void *value, size_t type);
int		entity_type(t_data *data, int x, int y);
int		get_pixel_color(t_txtr *txtr, int i);
void	update_coord(t_entity *entity_data);
int		bigger(int a, int b, int c, int d);
void	ft_sleep(long long microsecond);
void	clear_window(t_data *data);
long	elapsed_time(t_time start);
void	*safe_malloc(size_t size);
int		which_p(t_data *data);
double	round_rad(double rad);
double	grad2rad(double rad);
double	rad2deg(double rad);
void	delete(void **ptr);

//SECTION debug

int		map_start(t_data *data, int i, int j);
int		game_loop(t_data *data);

//SECTION render

void	put_image_to_image(t_data *data, int which, int pos[2], int size[2]);
void	put_image_resize(t_data *data, int which, int pos[2], int size[2]);
void	test_wall3D(t_data *data, int x, int y, double ray_angle);
void 	line(t_data *data, t_entity *entity, double angle);
void	animation(t_data *data, t_entity *entity);
void	wall(t_data *data, double x, void *txtr);
int		compute_line(t_data *data, double pov_x);
int		commands(int key, t_data *data);
void	render_entity(t_data *data);
void	backgrounder(t_data *data);
void	get_txtr(t_data *data);
int		which_p(t_data *data);

void	update_map(t_data *data, t_entity *entity, int new_x, int new_y);

#endif
