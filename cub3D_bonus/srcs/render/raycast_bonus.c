/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/20 16:46:47 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

	// double	dda_data[2];
	// dda_data[X] = atan2(sin_angle, cos_angle);
	// dda_data[Y] = atan2(cos_angle, sin_angle);
	// printf("atan x:%f\tatan y:%f\n", dda_data[X], dda_data[Y]);
    // while (!the_wall_checker(entity, data))
    // {
    //     //put_pixel(data, (int)x, (int)y, 0xFF0000);
    //     x += cos_angle;
    //     y += sin_angle;

int		ill_be_back(t_entity *entity, t_data *data, double angle);

void line(t_data *data, t_entity *entity, double angle, int i)
{
    float cos_angle;
    float sin_angle;
	
    entity->curr_x = entity->screen[X];
    entity->curr_y = entity->screen[Y];
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
	// double	dda_data[2];
	// dda_data[X] = atan2(sin_angle, cos_angle);
	// dda_data[Y] = atan2(cos_angle, sin_angle);
	// printf("atan x:%f\tatan y:%f\n", dda_data[X], dda_data[Y]);
    while (!the_wall_checker(entity, data, angle, i))
    {
        entity->curr_x += cos_angle;
        entity->curr_y += sin_angle;
    }
	test_wall3D(data, (int)entity->curr_x, (int)entity->curr_y, angle);
	while (!ill_be_back(entity, data, angle))
    {
        entity->curr_x -= cos_angle;
        entity->curr_y -= sin_angle;
    }
	// wall(data, entity->curr_x, data->textures[wall_face(data, line, angle)]);
}

void	test_wall3D(t_data *data, int x, int y, double ray_angle)
{
	double	wall_h;
	t_txtr	*txtr;

	wall_h = wall_height(data, x, y, ray_angle);
	txtr = texture_finder(data, ray_angle, x, y);
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
