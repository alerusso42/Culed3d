/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/01 18:29:48 by lparolis         ###   ########.fr       */
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

# define FPS 60
# define FRAME_TIME (1000000 / FPS)

# define DEBUG true
# define VALID_CHARS " 01NSEW"
# define CONTENT_CHARS "NSEW"
# define FFILL_CHARS "0NSEW"

# define SCREEN_TXTR "textures/screen.xpm"
# if DEBUG == true
#   define PLAYER_TXTR "textures/pisnelo.xpm"
#   define WALL_TXTR "textures/debug_wall.xpm"
# else
#   define PLAYER_TXTR "textures/pisnelo.xpm"
#   define WALL_TXTR "textures/debug_wall.xpm"
# endif

# define HIMG 48
# define PIX_PLAYER HIMG + (HIMG / 2)
# define PLAYER_OFFSET (HIMG / 2)
# define WIMG 48
# define WSCREEN 1920
# define HSCREEN 1080

//# define RADIANT 0.008726

//(((2 * PI) / 360) * 0.2)
# define RADIANT (PI / 3600)

//	*5: adapt to RADIANT
# define FOV 60 * 5
# define PI 3.1415926

typedef struct timeval	t_time;

typedef struct s_data
{
	t_time	start;
	void	*mlx_connection;
	void	*mlx_window;
	void	**textures;
	char	*screen;
	char	**map;
	char	*txtr_north;
	char	*txtr_west;
	char	*txtr_south;
	char	*txtr_east;
	char	*txtr_floor;
	char	*txtr_ceiling;
	char	*txtr_player;
	int		bpp;
	int		size_line;
	int		endian;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	int		p_pos[2];
	int		max_x;
	int		max_y;
	int		color;
}	t_data;

typedef struct s_drawline
{
	int				line[WIMG + 1][2];
	double			delta_x;
	double			delta_y;
	double			curr_x;
	double			curr_y;
	int				pixel_p[2];
	int				pixel_win[2];
	int				int_x;
	int				int_y;
	int				next_x;
	int				next_y;
	int				final_x;
	int				final_y;
	char			x_sign:2;
	char			y_sign:2;
	unsigned char	radiant:1;
}	t_drawline;

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
};

void	lets_start_the_party(t_data *data);
void	spread_democracy(t_data *data);
void	free_texture(t_data *data);
void	parsing(t_data *data, int argc, char **argv);
void	error(t_data *data, int err, char *file);

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
double 	round_rad(double rad);
double	rad2deg(double rad);
void 	put_pixel(t_data *data, int x, int y, int color);
int		ray_lenght(t_data *data, int rx, int ry);

//SECTION debug

int		map_start(t_data *data);
int		game_loop(t_data *data);

//SECTION render

void	get_texture(t_data *data);
int		draw_line(t_data *data, double pov_x, double pov_y);
void	update_coord(t_drawline *line_data);
void	add_coord(int line[WIMG + 1][2], int x, int y);
void	reset_coord(int line[WIMG + 1][2]);
void	print_coord(t_data *data, int line[WIMG + 1][2]);
void	print_last_coord(t_data *data, t_drawline *line_data);


#endif