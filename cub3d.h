/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/15 17:56:22 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
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

# define FPS 30
# define FRAME_TIME (1000000 / FPS)

#ifndef DEBUG
# define DEBUG true
# endif
# define VALID_CHARS " 01NSEW"
# define CONTENT_CHARS "NSEW"
# define FFILL_CHARS "0NSEW"

# define SCREEN_TXTR "textures/screen.xpm"
# if DEBUG == true
#  define PLAYER_TXTR "textures/pisnelo.xpm"
#  define WALL_TXTR "textures/debug_wall.xpm"
# else
#  define PLAYER_TXTR "textures/pisnelo.xpm"
#  define WALL_TXTR "textures/debug_wall.xpm"
# endif

# define HIMG 48
# define PIX_PLAYER HIMG + (HIMG / 2)
# define PLAYER_OFFSET (HIMG / 2)
# define WIMG 48
# define WSCREEN 1920
# define HSCREEN 1080

//# define RADIANT 0.008726

/*
	180 degrees are PI radiant.
	Degree changes every PI / 180.
	We need more precision: so we multiply 180 for LINE_ACCURACY.
	RADIANT = (PI / (180 * LINE_ACCURACY)).
	
	LINE_ACCURACY shows the size of the angle the line makes when
	player changes what is seeing.
	Setting it to 1 makes the line moving by 1 degree as sensibility;
	Setting to 20 makes the line moving by (1 degree / 20)
	20 is enough to touch all pixel during raycasting.
*/
# define RADIANT (PI / 3600)

//	see RADIANT for explaination.
//	putting it to 1 makes the line sensibility to 1 degree.
//	putting it to 20 makes the line sensibility to (1 degree / 20), and so on.
//NOTE [L_A: 30; FOV: 64]
# define LINE_ACCURACY 10

//	FOV (=Field Of View) represents the angle of the player vision.
# define FOV 32 * LINE_ACCURACY

//	determines how much time you need to print the texture to fill all screen.
# define FOV_RATIO (int)((WSCREEN / FOV) / LINE_ACCURACY)

# define PI 3.1415926

//FIXME	This flag is in debug state.
# define SPEED 5

typedef struct timeval		t_time;
typedef struct s_drawline	t_drawline;

typedef struct s_drawline
{
	double	delta_x;
	double	delta_y;
	double	curr_x;
	double	curr_y;
	double	pov[2];
	int		screen[2];
	int		map[2];
	int		speed;
	int		int_x;
	int		int_y;
	int		next_x;
	int		next_y;
	char	type;
	char	x_sign:2;
	char	y_sign:2;
}	t_drawline;

typedef struct s_data
{
	t_drawline	player;
	t_time		start;
	void		*mlx;
	void		*win;
	void		**textures;
	char		*screen;
	char		**map;
	char		*txtr_north;
	char		*txtr_west;
	char		*txtr_south;
	char		*txtr_east;
	char		*txtr_floor;
	char		*txtr_ceiling;
	char		*txtr_player;
	int			bpp;
	int			size_line;
	int			endian;
	int			floor_rgb[3];
	int			ceiling_rgb[3];
	int			max_x;
	int			max_y;
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
	PLAYER,
	WALL,
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
};

enum	e_type_identifers
{
	NO,
	SO,
	EA,
	WE,
	F,
	C,
	TYPE_IDENTIFERS_NUM,
};

enum e_utils
{
	X,
	Y,
	POSITIVE = 1,
	NEGATIVE = -1,
	LEFT = XK_a,
	RIGHT = XK_d,
	UP = XK_w,
	DOWN = XK_s,
	R_LEFT = XK_Left,
	R_RIGHT = XK_Right,
};

void	lets_start_the_party(t_data *data);
void	spread_democracy(t_data *data);
void	free_texture(t_data *data);
void	parsing(t_data *data, int argc, char **argv);
void	error(t_data *data, int err, char *file);

//SECTION	input

void	init_player(t_data *data);
int		ft_cross_close(t_data *data);
int		commands(int keycode, t_data *data);
int		move(t_data *data, t_drawline *entity, int keycode);
void	rotate(t_data *data, t_drawline *entity, int dir);

//SECTION	parsing

void	get_type(t_data *data, int fd);
void	check_textures(t_data *data, int fd);
void	get_map(t_data *data, int fd);
void	parse_map(t_data *data);
void	check_chars(t_data *data);
void	check_walls(t_data *data);
void	check_map_access(t_data *data);
void	finish_him(int fd);

//SECTION	utils

void	*safe_malloc(size_t size);
void	ft_sleep(long long microsecond);
long	elapsed_time(t_time start);
double	safe_division(double delta, double sum);
double	grad2rad(double rad);
double	round_rad(double rad);
double	rad2deg(double rad);
void	update_delta(double pov, double *delta_x, double *delta_y);
void	put_pixel(t_data *data, int x, int y, int color);
void	clear_window(t_data *data);
int		ray_lenght(t_data *data, int rx, int ry);
void	update_delta(double pov, double *delta_x, double *delta_y);
void	update_coord(t_drawline *line_data);

//SECTION debug

int		map_start(t_data *data);
int		game_loop(t_data *data);

//SECTION render

int		compute_line(t_data *data, double pov_x);
void	test_wall3D(t_data *data, int x, int y, bool STOP_PLEASE_STOP_AAAAAH);
int		commands(int key, t_data *data);
void	backgrounder(t_data *data);
void	get_texture(t_data *data);

#endif