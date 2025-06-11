/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:19:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/11 19:29:38 by lparolis         ###   ########.fr       */
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

typedef struct s_data
{
	char	*texture_north;
	char	*texture_west;
	char	*texture_south;
	char	*texture_east;
	char	*texture_floor;
	char	*texture_ceiling;
	int		lunghezza_pene;
	bool	is_black;
}	t_data;

enum	e_errors
{
	E_MALLOC = 1,
	E_OPEN,
	E_ARGC,
	E_EXT,
	E_TYPE,
};

enum	e_type_identifers
{
	NO,
	SO,
	EA,
	WE,
	F,
	C,
};

void	spread_democracy(t_data *data);
void	parsing(t_data *data, int argc, char **argv);
void	error(t_data *data, int err, char *file);

//SECTION	parsing

void	get_type(t_data *data, int fd);
void	get_map(t_data *data, int fd);

//SECTION	utils

int	double_cmp(char *s1, char *s2, int s1_len);

#endif