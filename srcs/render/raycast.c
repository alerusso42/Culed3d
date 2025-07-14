/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/14 14:38:17 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	the_wall_checker(t_drawline *line_data, t_data *data);
static void	init_line_data(t_data *data, t_drawline *line_data, double pov_x);

/*
//REVIEW	compute_line

	Brutal force algorythm: every pixel checks if there is a wall.
Key steps:
	1)	Calculate a delta, based on pov_x (the player vision angle).
		The delta normalizes the vector x and y of the line.
		So finds, for every step (1 pixel), how much the line must
		move on the x and how much on the y.

	2)	Data are stored in 4 variable types:
		-	double	delta_x/y	--->	for every pixel, how much to go on x/y?
		-	double	curr_x/y	--->	current position in float values
		-	int		int_x/y		--->	same in integer. Real pixel position. 
		-	int		next_x/y	--->	Next pixel to reach.
		When curr_x/y surpasses next_x/y, int_x/y gets updated.
		To go backward in x and in y, we make the delta POSITIVE or NEGATIVE.

	3)	If DEBUG macro is active, pixel are written on screen too.
		Very cool, right?
		(YES) (NO, lol)
		if (YES)
			"Hehe. We put one fu**ing week in doing this sheet!"
		else
			https://youtu.be/VWBFpKA2IEc?si=wWeW5HXGI-M-EDzN
*/
int	compute_line(t_data *data, double pov_x)
{
	t_drawline	line_data;

	if (!data || pov_x > 360)
		return (printf("ORA ORA ORA!"));
	init_line_data(data, &line_data, pov_x);
	while ((the_wall_checker(&line_data, data) == false))
	{
		if (DEBUG == true)
			put_pixel(data, line_data.int_x, line_data.int_y, data->color);
		update_coord(&line_data);
	}
	// cast_ray();
	return (0);
}

/*
	//FIXME To optimize line, we should:
	1)	calculate minimal vectors using DDA;
	2)	incrementing curr_x and curr_y by that minimal values;
	3)	calling this function normally;
	4)	stop printing the line.
		At that point, we could differentiate this method using DEBUG macro.
*/
static int	the_wall_checker(t_drawline *line_data, t_data *data)
{
	int	x;
	int	y;

	x = (int)line_data->curr_x / WIMG;
	y = (int)line_data->curr_y / HIMG;
	if (data->map[y][x] == '1')
	{
		ray_lenght(data, x * WIMG, y * HIMG);
		return (true);
	}
	return (false);
}

//	init all data to draw a line.
static void	init_line_data(t_data *data, t_drawline *line_data, double pov_x)
{
	*line_data = (t_drawline){0};
	line_data->int_x = (data->player.screen[X] + WIMG / 2);
	line_data->int_y = (data->player.screen[Y]) + HIMG / 2;
	line_data->curr_x = (int)data->player.screen[X] + WIMG / 2;
	line_data->curr_y = (int)data->player.screen[Y] + HIMG / 2;
	line_data->next_x = line_data->int_x + line_data->x_sign;
	line_data->next_y = line_data->int_y + line_data->y_sign;
	update_delta(pov_x, &line_data->delta_x, &line_data->delta_y);
	line_data->x_sign = POSITIVE;
	line_data->y_sign = POSITIVE;
	if (line_data->delta_x < 0)
		line_data->x_sign = NEGATIVE;
	if (line_data->delta_y < 0)
		line_data->y_sign = NEGATIVE;
}
