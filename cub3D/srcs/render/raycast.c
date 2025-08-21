/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 09:30:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	test_wall3D(t_data *data, int x, int y, double ray_angle)
{
	double	wall_h;
	double	scaler;
	double	index;
	int		k;
	int		offset;
	int		i;

(void)i;
	wall_h = wall_height(data, x, y, ray_angle);
	offset = index_finder(data, ray_angle, x, y);
	scaler = (TXTR / wall_h) / 2;
	index = TXTR - 1;
	k = (HSCREEN / 2) + wall_h;
	while (k >= (HSCREEN / 2) - wall_h && index > 0)
	{
		i = offset + (data->img_data[SIZE] * (int)index);
		index -= scaler;
		put_pixel(data, data->column, k, get_pixel_color(data->img_ptr, i));
		k--;
	}
}
