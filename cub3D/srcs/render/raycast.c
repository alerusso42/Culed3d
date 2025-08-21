/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 15:05:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	render_column(t_data *data, double wall_h, int offset);

void	draw_wall(t_data *data, int x, int y, double ray_angle)
{
	double	wall_h;
	int		offset;

	wall_h = wall_height(data, x, y, ray_angle);
	offset = index_finder(data, ray_angle, x, y);
	render_column(data, wall_h, offset);
}

static void	render_column(t_data *data, double wall_h, int offset)
{
	int		k;
	int		i;
	double	scaler;
	double	index;

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
