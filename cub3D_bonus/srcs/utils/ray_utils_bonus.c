/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 11:52:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	save_coord(t_data *data, t_entity *ent, int map[2], double screen[2]);

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
	int		map[2];
	int		we;

	map[X] = (int)entity->curr_x / WIMG;
	map[Y] = (int)entity->curr_y / HIMG;
	if (ft_strchr(FFILL_CHARS, data->map[map[Y]][map[X]]))
		return (false);
	if (ft_strchr(WALL_CHARS, data->map[map[Y]][map[X]]))
		return (true);
	we = which_entity(data, map[X], map[Y], ENTITY_DOOR);
	if (we != ENTITY_NOT_FOUND)
	{
		if (data->doors[we].type == DOOR_OPENED)
			return (false);
		return (true);
		data->doors[we].ray_num = i;
		data->doors[we].ray_angle = angle;
		save_coord(data, &data->doors[we], (int [2]){map[X], map[Y]}, \
		(double [2]){entity->curr_x, entity->curr_y});
	}
	return (false);
}

int		the_door_checker(t_entity *entity, t_data *data, double angle, int i)
{
	int		map[2];
	int		we;

	(void)i, (void)angle;
	map[X] = (int)entity->curr_x / WIMG;
	map[Y] = (int)entity->curr_y / HIMG;
	if (ft_strchr(FFILL_CHARS, data->map[map[Y]][map[X]]))
		return (false);
	if (ft_strchr(WALL_CHARS, data->map[map[Y]][map[X]]))
		return (true);
	we = which_entity(data, map[X], map[Y], ENTITY_DOOR);
	if (we != ENTITY_NOT_FOUND)
	{
		if (data->doors[we].type == DOOR_OPENED)
			return (false);
		return (true);
	}
	return (false);
}


// int		ill_be_back(t_entity *entity, t_data *data, double angle)
// {
// 	int	x;
// 	int	y;
// 	int	we;

// 	x = (int)entity->curr_x / WIMG;
// 	y = (int)entity->curr_y / HIMG;
// 	if (x > data->max_x)
// 		return (true);
// 	if (y > data->max_y)
// 		return (true);
// 	if (data->map[y][x] && data->map[y][x] == '0')
// 		return (false);
// 	if (ft_strchr(PLAYER_CHARS, data->map[y][x]))
// 		return (true);
// 	else if (data->map[y][x] == 'D')
// 	{
// 		we = which_entity(data, x, y, ENTITY_DOOR);
// 		if (data->doors[we].type == DOOR_OPENED)
// 			return (false);
// 		draw_wall(data, (int)entity->curr_x, (int)entity->curr_y, angle);
// 		entity->curr_x += WIMG * 1.3;
// 		entity->curr_y += HIMG * 1.3;
// 	}
// 	else if (data->map[y][x] == 'F')
// 	{
// 		we = which_entity(data, x, y, ENTITY_ENEMY);
// 		//data->enemies[we].ray_num = i;
// //		save_coords(data, (int [2]){x, y}, &data->enemies[we], angle);
// 	}
// 	return (false);
// }

void	save_coord(t_data *data, t_entity *ent, int map[2], double screen[2])
{
	int	i;

	ent->contact = true;
	if (ent->contact_first[X] == -1 && ent->contact_first[Y] == -1)
	{
		ent->contact_first[X] = map[X];
		ent->contact_first[Y] = map[Y];
		i = 0;
		while (data->entities && data->entities[i])
			++i;
		data->entities[i] = ent;
		ent->curr_x = screen[X];
		ent->curr_y = screen[Y];
	}
	ent->contact_last[X] = map[X];
	ent->contact_last[Y] = map[Y];
}


double	ray_lenght(t_data *data, int rx, int ry)
{
	double	ray;
	int		px;
	int		py;

	px = data->player.screen[X];
	py = data->player.screen[Y];
	rx = abs(rx);
	ry = abs(ry);
	ray = sqrt(pow((double)(rx - px), 2) + pow((double)(ry - py), 2));
	return (ray);
}
