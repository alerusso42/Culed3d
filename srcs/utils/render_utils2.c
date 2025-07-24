/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/24 15:50:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	check_north_collision(t_data *data, t_entity *entity);
	
int	wall_face(t_data * data, t_entity *entity, double angle)
{
	char	face;

	face = 0;
	if ((((int)(entity->curr[Y]) % HIMG == 0) || \
		((int)(entity->curr[Y] + 1) % HIMG == 0) || \
		((int)(entity->curr[Y] - 1) % HIMG == 0)) \
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

	x[0] = (int)(entity->curr[X]) / WIMG;
	y[0] = (int)(entity->curr[Y]) / HIMG;
	x[1] = (int)(entity->curr[X] - 1) / WIMG;
	y[1] = (int)(entity->curr[Y]) / HIMG;
	x[2] = (int)(entity->curr[X] + 1) / WIMG;
	y[2] = (int)(entity->curr[Y]) / HIMG;
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

	pov_diff = cos(ray_angle - data->player.pov[X]);
	ray = ray_lenght(data, x, y);
	ray = ray * pov_diff;
	ray = safe_division((HSCREEN * 10), ray);
	height = round(ray / 1.5);
	return ((int)height);
}

int	index_finder(t_data *data, double ray_angle, int hit_x)
{
	int		which_wall;
	int		color;
	int		pixel;

	color = 0;
	pixel = (int)((((double)hit_x / WIMG) - (int)(hit_x / WIMG)) * TXTR);
	which_wall = wall_face(data, &data->player, ray_angle);
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
