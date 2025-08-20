/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/20 10:02:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	save_coords(t_data *data, int coord[2], t_entity *entity, double angle);

/*
	//FIXME To optimize line, we should:
	1)	calculate minimal vectors using DDA;
	2)	incrementing curr_x and curr_y by that minimal values;
	3)	calling this function normally;
	4)	stop printing the line.
		At that point, we could differentiate this method using DEBUG macro.
*/
int		the_wall_checker(t_entity *entity, t_data *data, double angle, int i)
{
	int	x;
	int	y;
	int	we;

	x = (int)entity->curr_x / WIMG;
	y = (int)entity->curr_y / HIMG;
	if (data->map[y][x] == '0')
		return (false);
	if (data->map[y][x] == '1')
		return (true);
	else if (data->map[y][x] == 'D')
	{
		we = which_entity(data, x, y, ENTITY_DOOR);
		data->doors[we].ray_num = i;
		save_coords(data, (int [2]){x, y}, &data->doors[we] ,angle);
	}
	else if (data->map[y][x] == 'F')
	{
		we = which_entity(data, x, y, ENTITY_ENEMY);
		//data->enemies[we].ray_num = i;
//		save_coords(data, (int [2]){x, y}, &data->enemies[we], angle);
	}
	return (false);
}

void	save_coords(t_data *data, int coord[2], t_entity *entity, double angle)
{
	int	i;

	entity->contact = true;
	if (entity->contact_first[X] == -1 && entity->contact_first[Y] == -1)
	{
		entity->contact_first[X] = coord[X];
		entity->contact_first[Y] = coord[Y];
		i = 0;
		while (data->entities && data->entities[i])
			++i;
		data->entities[i] = entity;
		entity->ray_angle = angle;
	}
	entity->contact_last[X] = coord[X];
	entity->contact_last[Y] = coord[Y];
}
//	init all data to draw a line.
// void	init_line_data(t_data *data, t_entity *entity_data, double pov_x)
// {
// 	*line_data = (t_drawline){0};
// 	line_data->int_x = (data->player.entity.screen[X] + WIMG / 2);
// 	line_data->int_y = (data->player.entity.screen[Y]) + HIMG / 2;
// 	line_data->curr_x = (int)data->player.entity.screen[X] + WIMG / 2;
// 	line_data->curr_y = (int)data->player.entity.screen[Y] + HIMG / 2;
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
	int		px;
	int		py;
	// double	angle;

	px = data->player.screen[X];
	py = data->player.screen[Y];
	rx = abs(rx);
	ry = abs(ry);
	// angle = atan2(ry - data->player.entity.curr_y, rx - data->player.entity.curr_x)  - data->player.entity.pov[X];
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
