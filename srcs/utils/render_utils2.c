/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/25 17:08:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	check_north_collision(t_data *data, t_drawline *line);

//REVIEW	wall_face
/*
	Returns the wall face, based on the ray angle.
	1. Checks if the wall is north/south or east/west;
	2. Then, based on the ray angle, returns the wall face.

				PI / 2
		   ~.----~~~ -- .
   	  ..-~        |       ~-.
	 /            |           \
	 /            |            \			NORTH/SOUTH: 	________________________
	 |            |             |					NORTH:	|0	    	|  PI			|
PI	 | ___________|____________ | 0					SOUTH:	|PI			|  2 * PI (0)	|
	 |            |             |							________________________
	  \           |            /			WEST/EAST:
	   \          |           /						WEST:	|PI / 2 | (PI / 2) * 3|
	    `-.       |        .-'						EAST:	|3 * PI / 2 - 2 * PI|
	        ~- . _|__ . -~									____________________
			(PI / 2) * 3
*/
int	wall_face(t_data * data, t_drawline *line, double angle)
{
	char	face;

	face = 0;
	if ((((int)(line->curr_y) % HIMG == 0) || \
		((int)(line->curr_y + 1) % HIMG == 0) || \
		((int)(line->curr_y - 1) % HIMG == 0)) \
			&& check_north_collision(data, line))
		face |= (NO | SO);
	else
		face |= (WE | EA);
	if (face & (NO | SO))
	{
		if (angle >= 0 && angle < PI)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (angle < PI / 2 || angle >= (PI / 2) * 3)
			return (EAST);
		else
			return (WEST);
	}
}

static bool	check_north_collision(t_data *data, t_drawline *line)
{
	int	x[3];
	int	y[3];

	x[0] = (int)(line->curr_x) / WIMG;
	y[0] = (int)(line->curr_y) / HIMG;
	x[1] = (int)(line->curr_x - 1) / WIMG;
	y[1] = (int)(line->curr_y) / HIMG;
	x[2] = (int)(line->curr_x + 1) / WIMG;
	y[2] = (int)(line->curr_y) / HIMG;
	if (data->map[y[0]][x[0]] == '1' && \
		(data->map[y[1]][x[1]] == '1') && \
		(data->map[y[2]][x[2]] == '1'))
	{
		return (true);
	}
	return (false);
}

int	wall_height(t_data *data, double x, double y, double ray_angle)
{
	double	pov_diff;
	double	ray;
	double	height;

	pov_diff = cos(ray_angle - data->player.line.pov[X]);
	ray = ray_lenght(data, x, y);
	ray = ray * pov_diff;
	ray = safe_division((HSCREEN * 10), ray);
	height = round(ray / 1.5);
	return ((int)height);
}

int	index_finder(t_data *data, double ray_angle, int hit_x, int hit_y)
{
	int		which_wall;
	int		pixel;

	which_wall = wall_face(data, &data->player.line, ray_angle);
	if (which_wall == NORTH || which_wall == SOUTH)
		pixel = (int)((((double)hit_x / WIMG) - (int)(hit_x / WIMG)) * TXTR);
	else
		pixel = (int)((((double)hit_y / WIMG) - (int)(hit_y / WIMG)) * TXTR);
	if (which_wall == WEST || which_wall == SOUTH)
		pixel = TXTR - pixel;
	data->img_ptr = mlx_get_data_addr(data->textures[which_wall], \
		&data->img_data[BPP], &data->img_data[SIZE], &data->img_data[ENDIAN]);
	if (!data->img_ptr)
		return (0);
	return (pixel * (data->img_data[BPP] / 8));
}

int	get_pixel_color(char *img_ptr, int i)
{
	return ((img_ptr[i] & 0xFF) | \
	(img_ptr[i + 1] & 0xFF << 8) | \
	(img_ptr[i + 2] & 0xFF << 16));
}
