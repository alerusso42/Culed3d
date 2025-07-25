/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/25 16:43:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

// int	compute_line(t_data *data, double pov_x, double diff)
// {
// 	t_drawline	line_data;

// 	if (!data || pov_x > 360)
// 		return (printf("ORA ORA ORA!"));
// 	init_line_data(data, &line_data, pov_x);
// 	while ((the_wall_checker(&line_data, data) == false))
// 	{
// 		if (DEBUG == true)
// 			put_pixel(data, line_data.int_x, line_data.int_y, data->color);
// 		update_coord(&line_data);
// 	}
// 	test_wall3D(data, line_data.int_x, line_data.int_y, false, diff);
// 	return (0);
// }

// int	compute_line(t_data *data, double ray_angle)
// {
// 	t_drawline	line_data;
// 	double		diff;

// 	if (!data || ray_angle > 360)
// 		return (printf("ORA ORA ORA!"));
// 	init_line_data(data, &line_data, ray_angle);
// 	while ((the_wall_checker(&line_data, data) == false))
// 	{
// 		if (DEBUG == true)
// 			put_pixel(data, line_data.int_x, line_data.int_y, data->color);
// 		update_coord(&line_data);
// 	}
// 	diff = fabs(ray_angle - data->player.line.pov[X]);
// 	// test_wall3D(data, line_data.int_x, line_data.int_y, diff);
// 	return (0);
// }

// int	compute_line(t_data *data, double ray_angle)
// {
// 	t_drawline	line_data;
// 	double		diff;

// 	if (!data || ray_angle > 360)
// 		return (printf("ORA ORA ORA!"));
	
	
// 	return (0);
// }

# define DATA_ADDR mlx_get_data_addr
# define FABIO fabs

// int	find_txtr_size(char *txtr, int line_size)
// {
// 	int	txtr_size;
// 	int	line;

// 	txtr_size = 0;
// 	line = 0;
// 	while (txtr[line + 3])
// 	{
// 		++txtr_size;
// 		line += line_size;
// 	}
// 	return (txtr_size);
// }

void	test_wall3D(t_data *data, int x, int y, double ray_angle)
{
	double	wall_h;
	double	scaler;
	double	index;
	int		k;
	int		offset;
	int		i;
	// int		txtr_size;

(void)i;
	wall_h = wall_height(data, x, y, ray_angle);
	offset = index_finder(data, ray_angle, x, y);
	// txtr_size = find_txtr_size(data->img_ptr, data->img_data[SIZE]);
	// printf("TXTR:%d\n", TXTR);
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
