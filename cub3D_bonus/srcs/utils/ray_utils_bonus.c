/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 11:58:16 by alerusso         ###   ########.fr       */
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
int	the_wall_checker(t_entity *ray, t_data *data, double angle, int i)
{
	int			map[2];
	t_entity	*entity;

	map[X] = (int)ray->curr_x / WIMG;
	map[Y] = (int)ray->curr_y / HIMG;
	if (ft_strchr(FFILL_CHARS, data->map[map[Y]][map[X]]))
		return (false);
	if (ft_strchr(WALL_CHARS, data->map[map[Y]][map[X]]))
		return (true);
	entity = which_entity(data, map[X], map[Y]);
	if (!entity)
		return (false);
	if (entity->type == DOOR_OPEN || entity->type == DOOR_CLOSE)
		return (true);
	entity->ray_num = i;
	entity->ray_angle = angle;
	save_coord(data, entity, (int [2]){map[X], map[Y]}, \
(double [2]){entity->curr_x, entity->curr_y});
	return (false);
}

void	save_coord(t_data *data, t_entity *ent, int map[2], double screen[2])
{
	int	i;

	ent->contact = true;
	if (ent->contact_first[X] == -1 && ent->contact_first[Y] == -1)
	{
		ent->contact_first[X] = map[X];
		ent->contact_first[Y] = map[Y];
		i = 0;
		while (data->renderer && data->renderer[i])
			++i;
		data->renderer[i] = ent;
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
