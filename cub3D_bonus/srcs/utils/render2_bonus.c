/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 17:19:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static bool	check_north_collision(t_data *data, t_entity *entity);

//REVIEW	wall_face
/*
	Returns the wall face, based on the ray angle.
	1. Checks if the wall is north/south or east/west;
	2. Then, based on the ray angle, returns the wall face.

				PI / 2
		   ~.----~~~ -- .
   	  ..-~        |       ~-.
	 /            |           /
	 /            |            /	NORTH/SOUTH: 	________________________
	 |            |             |			NORTH:	|0	    	|  PI		|
PI	 | ___________|____________ | 0			SOUTH:	|PI			| 2 * PI (0)|
	 |            |             |					________________________|
	  /           |            /	WEST/EAST:								|
	   /          |           /				WEST:	|PI / 2 | (PI / 2) * 3|	|
	    `-.       |        .-'				EAST:	|3 * PI / 2 - 2 * PI|	|
	        ~- . _|__ . -~							________________________
			(PI / 2) * 3
*/
int	wall_face(t_data *data, t_entity *entity, double angle)
{
	char	face;

	face = 0;
	if ((((int)(entity->curr_y) % HIMG == 0) || \
((int)(entity->curr_y + 1) % HIMG == 0) || \
((int)(entity->curr_y - 1) % HIMG == 0)) \
&& check_north_collision(data, entity))
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

static bool	check_north_collision(t_data *data, t_entity *entity)
{
	int	x[3];
	int	y[3];

	x[0] = (int)(entity->curr_x) / WIMG;
	y[0] = (int)(entity->curr_y) / HIMG;
	x[1] = (int)(entity->curr_x - 1) / WIMG;
	y[1] = (int)(entity->curr_y) / HIMG;
	x[2] = (int)(entity->curr_x + 1) / WIMG;
	y[2] = (int)(entity->curr_y) / HIMG;
	if ((ft_strchr("1D", data->map[y[0]][x[0]])) && \
(ft_strchr("1D", data->map[y[1]][x[1]])) && \
(ft_strchr("1D", data->map[y[2]][x[2]])))
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

	pov_diff = cos(ray_angle - data->player.pov[X]);
	ray = ray_lenght(data, x, y);
	ray = ray * pov_diff;
	ray = safe_division((HSCREEN * 10), ray);
	height = round(ray / 1.5);
	return ((int)height);
}

t_txtr	*texture_finder(t_data *data, double ray_angle, int hit_x, int hit_y)
{
	int	we;

	if (all_collision(data, hit_x / WIMG, hit_y / HIMG) == true)
	{
		we = which_entity(data, hit_x / WIMG, hit_y / HIMG, ENTITY_DOOR);
		printf("door chosen: %d\n", we);
		if (data->doors[we].type == DOOR_OPENED)
			return (&data->txtr[DOOR_OPEN]);
		else
			return (&data->txtr[DOOR]);
	}
	else
		return (&data->txtr[wall_face(data, &data->player, ray_angle)]);
}

int	texture_x_offset(t_data *data, double ray_angle, int hit_x, int hit_y)
{
	int			wall_txtr;
	int			pixel;

	wall_txtr = wall_face(data, &data->player, ray_angle);
	if (wall_txtr == NORTH || wall_txtr == SOUTH)
		pixel = (int)((((double)hit_x / WIMG) - (int)(hit_x / WIMG)) * TXTR);
	else
		pixel = (int)((((double)hit_y / WIMG) - (int)(hit_y / WIMG)) * TXTR);
	if (wall_txtr == WEST || wall_txtr == SOUTH)
		pixel = TXTR - pixel;
	return (pixel * (data->bpp / 8));
}
