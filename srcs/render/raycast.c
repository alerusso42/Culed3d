/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/21 15:36:02 by alerusso         ###   ########.fr       */
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

#define FABIO fabs

void	test_wall3D(t_data *data, int x, int y, double ray_angle)
{
	double pov_diff;
	int		color;
	double	ray;
	int		i;

	i = -1;
	pov_diff = FABIO(cos(ray_angle - data->player.line.pov[X]));
	ray = ray_lenght(data, x, y);
	ray = ray * pov_diff;
	ray = safe_division((HSCREEN * 10), ray);
	ray = round(ray / 1.5);
	color = 255 << 16 | 0 << 8 | 255; //violet
	++data->column;
	i = ((HSCREEN / 2) + ray);
	while (i >= (HSCREEN / 2) - ray)
	{
		put_pixel(data, data->column, i, color);
		--i;
	}
}
//	SCREEN:     


		// k = -1;
		// while (++k < FOV_RATIO)
		// {
		// }
		// column += k;
		// mlx_put_image_to_window(data->mlx, data->win, \
		// 	data->textures[SCREEN], 0, 0);
		// mlx_do_sync(data->mlx);
// draw.io integration
// void	test_wall3D(t_data *data, int x, int y)
// {
// 	static char	*wall_addr;
// 	int			color;
// 	int			index;

// 	x %= WIMG;
// 	y %= HIMG;
// 	if (!wall_addr)
// 		wall_addr =  mlx_get_data_addr(data->textures[WALL], &data->bpp, &data->size_line, &data->endian);
// 	else if (!wall_addr)
// 		return ;
// 	index = y * data->size_line + x * (data->bpp / 8);
// 	color = wall_addr[index];
// 	color = color | (wall_addr[index + 1] << 8);
// 	color = color | (wall_addr[index + 2] << 16);
// 	put_pixel(data, y, x, color);
// }
