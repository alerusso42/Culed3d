/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 13:44:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int		the_door_checker(t_entity *entity, t_data *data, double angle, int i);

void	line(t_data *data, t_entity *entity, double angle, int i)
{
	float	cos_angle;
	float	sin_angle;
	// int		pos[2];

	entity->curr_x = entity->screen[X];
	entity->curr_y = entity->screen[Y];
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
	while (!the_wall_checker(entity, data, angle, i))
	{
		entity->curr_x += cos_angle;
		entity->curr_y += sin_angle;
	}
	draw_wall(data, (int [2]){(int)entity->curr_x, (int)entity->curr_y}, angle);
	// if (data->renderer[0])
	// {
	// 	pos[X] = (int)data->renderer[0]->curr_x;
	// 	pos[Y] = (int)data->renderer[0]->curr_y;
	// 	draw_wall(data, pos, angle);
	// 	data->renderer[0]->contact_first[X] = -1;
	// 	data->renderer[0]->contact_first[Y] = -1;
	// 	data->renderer[0] = NULL;
	// }
}

void	draw_wall(t_data *data, int pos[2], double ray_angle)
{
	double	wall_h;
	t_txtr	*txtr;

	wall_h = wall_height(data, pos[X], pos[Y], ray_angle);
	txtr = texture_finder(data, ray_angle, pos[X], pos[Y]);
	txtr->offset = texture_x_offset(data, ray_angle, pos[X], pos[Y]);
	txtr->offset *= txtr->scaler[X];
	txtr->shade = wall_h / SHADE_INTENSITY;
	if (txtr->shade > 1)
		txtr->shade = 1;
	render_column(data, txtr, wall_h);
}

void	render_column(t_data *data, t_txtr *txtr, double h)
{
	int		i;
	int		screen_y;
	double	txtr_line;
	double	scaler_y;

	scaler_y = (txtr->size[Y] / h) / 2;
	txtr_line = txtr->size[Y] - 1;
	screen_y = (HSCREEN / 2) + h;
	while (screen_y >= (HSCREEN / 2) - h && txtr_line > 0)
	{
		i = txtr->offset + (txtr->size[X] * (int)txtr_line);
		txtr_line -= scaler_y;
		put_pixel(data, data->column, screen_y, get_pixel_color(txtr, i));
		screen_y--;
	}
}
