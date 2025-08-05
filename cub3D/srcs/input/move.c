/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/05 10:51:36 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//static void	move_forward(t_data *data, t_entity *entity, double cos, double sin);
void	one_step(t_data *data, t_entity *entity, double angle[], int offset[]);

/*
	In our game, every entity (player, enemies, objects that moves?) is a
	vector.
	When moving, your are just updating your vector data, and moving
	according to those data.
*/
void	move(t_data *data, t_entity *entity, double angle[])
{
	if (entity->input & UP)
	{
		angle[COS] = cos(entity->pov[X]);
		angle[SIN] = sin(entity->pov[X]) * -1;
		one_step(data, entity, angle, (int [2]){0, 1});
	}
	if (entity->input & LEFT)
	{		
		angle[COS] = cos(entity->pov[X] + ANGLE_90);
		angle[SIN] = sin(entity->pov[X] + ANGLE_90) * -1;
		one_step(data, entity, angle, (int [2]){0, 1});
	}
	if (entity->input & DOWN)
	{
		angle[COS] = cos(entity->pov[X]) * -1;
		angle[SIN] = sin(entity->pov[X]);
		one_step(data, entity, angle, (int [2]){1, 0});
	}
	if (entity->input & RIGHT)
	{
		angle[COS] = cos(entity->pov[X] - ANGLE_90);
		angle[SIN] = sin(entity->pov[X] - ANGLE_90) * -1;
		one_step(data, entity, angle, (int [2]){1, 0});
	}
}

void	one_step(t_data *data, t_entity *entity, double angle[], int offset[])
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->screen[X] + (angle[COS] * entity->speed) + offset[X];
    new_y = entity->screen[Y] + (angle[SIN] * entity->speed) + offset[Y];
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
    if (map_y < 0 || map_y >= data->max_y || \
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1' || data->map[map_y][map_x] == ' ')
        return;
    entity->screen[X] = new_x;
    entity->screen[Y] = new_y;
	entity->map[X] = map_x;
	entity->map[Y] = map_y;
}

void	rotate(t_data *data, t_entity *entity)
{
	(void)data;
    if (entity->input & R_LEFT)
    {
        entity->pov[X] += ANGULAR_SPEED;
        if (entity->pov[X] > 2 * PI)
            entity->pov[X] -= 2 * PI;
    }
    if (entity->input & R_RIGHT)
    {
        entity->pov[X] -= ANGULAR_SPEED;
        if (entity->pov[X] < 0)
            entity->pov[X] += 2 * PI;
    }
}
