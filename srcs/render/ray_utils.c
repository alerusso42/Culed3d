/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 14:31:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//	Increments print coordinates, when the next integer points
//	is surpassed.
void	update_coord(t_drawline *line_data)
{
	line_data->curr_x += line_data->delta_x;
	line_data->curr_y += line_data->delta_y;
	if ((line_data->x_sign == POSITIVE && \
		line_data->curr_x > (double)line_data->next_x) || \
		(line_data->x_sign == NEGATIVE && \
		line_data->curr_x < (double)line_data->next_x))
	{
		line_data->int_x += line_data->x_sign;
		line_data->next_x += line_data->x_sign;
	}
	if ((line_data->y_sign == POSITIVE && \
		line_data->curr_y > (double)line_data->next_y) || \
		(line_data->y_sign == NEGATIVE && \
		line_data->curr_y < (double)line_data->next_y))
	{
		line_data->int_y += line_data->y_sign;
		line_data->next_y += line_data->y_sign;
	}
}

// 0x53dd03
/*
	sqrt is not what you may think
*/
int	ray_lenght(t_data *data, int rx, int ry)
{
	int	ray;
	int	px;
	int	py;

	px = data->player.map[X] * WIMG;
	py = data->player.map[Y] * HIMG;
	rx = abs(rx);
	ry = abs(ry);
	// printf("px: %d\tpy: %d\trx: %d\try: %d\n", px, py, rx, ry);
	printf("a: %d\tb: %d\n", abs(rx - px), abs(ry - py));
	ray = sqrt(pow((rx - px), 2) + pow((ry - py), 2));
	printf("ray lenght: %d\n", ray);
	return (ray);
}
