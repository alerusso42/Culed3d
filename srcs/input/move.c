/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/02 15:42:40 by alerusso         ###   ########.fr       */
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
		angle[COS] = cos(entity->line.pov[X]);
		angle[SIN] = sin(entity->line.pov[X]) * -1;
		one_step(data, entity, angle, (int [2]){0, 1});
	}
	if (entity->input & LEFT)
	{		
		angle[COS] = cos(entity->line.pov[X] + ANGLE_90);
		angle[SIN] = sin(entity->line.pov[X] + ANGLE_90) * -1;
		one_step(data, entity, angle, (int [2]){0, 1});
	}
	if (entity->input & DOWN)
	{
		angle[COS] = cos(entity->line.pov[X]) * -1;
		angle[SIN] = sin(entity->line.pov[X]);
		one_step(data, entity, angle, (int [2]){1, 0});
	}
	if (entity->input & RIGHT)
	{
		angle[COS] = cos(entity->line.pov[X] - ANGLE_90);
		angle[SIN] = sin(entity->line.pov[X] - ANGLE_90) * -1;
		one_step(data, entity, angle, (int [2]){1, 0});
	}
}

void	one_step(t_data *data, t_entity *entity, double angle[], int offset[])
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->line.screen[X] + (angle[COS] * entity->speed) + offset[X];
    new_y = entity->line.screen[Y] + (angle[SIN] * entity->speed) + offset[Y];
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
    if (map_y < 0 || map_y >= data->max_y || \
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1' || data->map[map_y][map_x] == ' ')
        return;
    entity->line.screen[X] = new_x;
    entity->line.screen[Y] = new_y;
}

void	rotate(t_data *data, t_entity *entity)
{
	(void)data;
    if (entity->input & R_LEFT)
    {
        entity->line.pov[X] += ANGULAR_SPEED;
        if (entity->line.pov[X] > 2 * PI)
            entity->line.pov[X] -= 2 * PI;
    }
    if (entity->input & R_RIGHT)
    {
        entity->line.pov[X] -= ANGULAR_SPEED;
        if (entity->line.pov[X] < 0)
            entity->line.pov[X] += 2 * PI;
    }
}
