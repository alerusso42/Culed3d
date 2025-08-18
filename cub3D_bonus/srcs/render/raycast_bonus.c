/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/18 15:47:14 by lparolis         ###   ########.fr       */
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
    //     x += cos_angle;	// * dda_data[X]
    //     y += sin_angle;	// * dda_data[Y]

void line(t_data *data, t_entity *entity, double angle)
{
    double x;
    double y;
    float cos_angle;
    float sin_angle;
	
	x = entity->screen[X];
	y = entity->screen[Y];
    entity->curr_x = x;
    entity->curr_y = y;
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
	// double	dda_data[2];
	// dda_data[X] = atan2(sin_angle, cos_angle);
	// dda_data[Y] = atan2(cos_angle, sin_angle);
	// printf("atan x:%f\tatan y:%f\n", dda_data[X], dda_data[Y]);
    while (!the_wall_checker(entity, data))
    {
        //put_pixel(data, (int)x, (int)y, 0xFF0000);
        x += cos_angle;	// * dda_data[X]
        y += sin_angle;	// * dda_data[Y]
        entity->curr_x = x;
        entity->curr_y = y;
    }
	// wall(data, entity->curr_x, data->textures[wall_face(data, line, angle)]);
	test_wall3D(data, (int)entity->curr_x, (int)entity->curr_y, angle);
}

void	test_wall3D(t_data *data, int x, int y, double ray_angle)
{
	double	wall_h;
	double	scaler;
	double	index;
	int		k;
	t_txtr	*txtr;
	int		i;

	(void)i;
	wall_h = wall_height(data, x, y, ray_angle);
	txtr = texture_finder(data, ray_angle, x, y);
	// txtr_size = find_txtr_size(data->img_ptr, data->img_data[SIZE]);
	// printf("TXTR:%d\n", TXTR);
	txtr->shade = wall_h / SHADE_INTENSITY;
	if (txtr->shade > 1)
		txtr->shade = 1;
	scaler = (txtr->size[Y] / wall_h) / 2;
	index = txtr->size[Y] - 1;
	k = (HSCREEN / 2) + wall_h;
	while (k >= (HSCREEN / 2) - wall_h && index > 0)
	{
		i = txtr->offset + (txtr->size[X] * (int)index);
		index -= scaler;
		put_pixel(data, data->column, k, get_pixel_color(txtr, i));
		k--;
	}
}
