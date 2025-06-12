/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 21:41:43 by lparolis         ###   ########.fr       */
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

# define VALID_CHARS " 01NSEW"
# define CONTENT_CHARS "NSEW"
# define FFILL_CHARS "0NSEW"

typedef struct s_data
{
	char	**map;
	char	*texture_north;
	char	*texture_west;
	char	*texture_south;
	char	*texture_east;
	char	*texture_floor;
	char	*texture_ceiling;
	int		p_pos[2];
	int		max_x;
	int		max_y;
}	t_data;

typedef enum e_timecode
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS,
}	t_timecode;

enum	e_errors
{
	E_MALLOC = 1,
	E_OPEN,
	E_ARGC,
	E_EXT,
	E_TYPE,
	E_TEXTURE,
	E_CHAR,
	E_NO_PLAYER,
	E_MULTIPLAYER,
	E_INVALID_MAP,
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

void	spread_democracy(t_data *data);
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

//SECTION	utils

void	*safe_malloc(size_t size);
void	ft_sleep(long long microsecond);

#endif