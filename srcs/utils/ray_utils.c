/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/21 10:41:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//	Increments print coordinates, when the next integer points
//	is surpassed.
// void	update_coord(t_drawline *line_data)
// {
// 	line_data->curr_x += line_data->delta_x;
// 	line_data->curr_y += line_data->delta_y;
// 	if ((line_data->x_sign == POSITIVE && \
// 		line_data->curr_x > (double)line_data->next_x) || \
// 		(line_data->x_sign == NEGATIVE && \
// 		line_data->curr_x < (double)line_data->next_x))
// 	{
// 		line_data->int_x += line_data->x_sign;
// 		line_data->next_x += line_data->x_sign;
// 	}
// 	if ((line_data->y_sign == POSITIVE && \
// 		line_data->curr_y > (double)line_data->next_y) || \
// 		(line_data->y_sign == NEGATIVE && \
// 		line_data->curr_y < (double)line_data->next_y))
// 	{
// 		line_data->int_y += line_data->y_sign;
// 		line_data->next_y += line_data->y_sign;
// 	}
// }

/*
	//FIXME To optimize line, we should:
	1)	calculate minimal vectors using DDA;
	2)	incrementing curr_x and curr_y by that minimal values;
	3)	calling this function normally;
	4)	stop printing the line.
		At that point, we could differentiate this method using DEBUG macro.
*/
int	the_wall_checker(t_drawline *line_data, t_data *data)
{
	int	x;
	int	y;

	x = (int)line_data->curr_x / WIMG;
	y = (int)line_data->curr_y / HIMG;
	if (data->map[y][x] == '1')
	{
		//printf("COLLISION:\tx:%d\ty:%d\n", line_data->int_x, line_data->int_y);
		return (true);
	}
	return (false);
}

//	init all data to draw a line.
// void	init_line_data(t_data *data, t_drawline *line_data, double pov_x)
// {
// 	*line_data = (t_drawline){0};
// 	line_data->int_x = (data->player.line.screen[X] + WIMG / 2);
// 	line_data->int_y = (data->player.line.screen[Y]) + HIMG / 2;
// 	line_data->curr_x = (int)data->player.line.screen[X] + WIMG / 2;
// 	line_data->curr_y = (int)data->player.line.screen[Y] + HIMG / 2;
// 	line_data->next_x = line_data->int_x + line_data->x_sign;
// 	line_data->next_y = line_data->int_y + line_data->y_sign;
// 	update_delta(pov_x, &line_data->delta_x, &line_data->delta_y);
// 	line_data->x_sign = POSITIVE;
// 	line_data->y_sign = POSITIVE;
// 	if (line_data->delta_x < 0)
// 		line_data->x_sign = NEGATIVE;
// 	if (line_data->delta_y < 0)
// 		line_data->y_sign = NEGATIVE;
// }

/*
	sqrt is not what you may think
*/
double	ray_lenght(t_data *data, int rx, int ry)
{
	double	ray;
	// double	angle;
	int		px;
	int		py;

	px = data->player.line.screen[X];
	py = data->player.line.screen[Y];
	rx = abs(rx);
	ry = abs(ry);
	// angle = atan2(ry - data->player.line.curr_y, rx - data->player.line.curr_x)  - data->player.line.pov[X];
	ray = sqrt(pow((double)(rx - px), 2) + pow((double)(ry - py), 2))/*  * cos(angle) */;
	if (DEBUG == true)
	{
		//printf("px: %d\tpy: %d\trx: %d\try: %d\n", px, py, rx, ry);
		//printf("a: %d\tb: %d\n", abs(rx - px), abs(ry - py));
		//printf("ray lenght: %d\n", ray);
		//printf("player coords: px: %d\tpy: %d\n", px, py);
		//printf("rx:\t%d\nry:\t%d\n", rx, ry);
	}	
	return (ray);
}
