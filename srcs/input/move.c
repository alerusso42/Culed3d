/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/24 22:09:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	move_forward(t_data *data, t_entity *entity, double cos, double sin);
static void	move_right(t_data *data, t_entity *entity, double cos, double sin);
static void	move_back(t_data *data, t_entity *entity, double cos, double sin);
static void	move_left(t_data *data, t_entity *entity, double cos, double sin);

/*
	In our game, every entity (player, enemies, objects that moves?) is a
	vector.
	When moving, your are just updating your vector data, and moving
	according to those data.
*/
int	move(t_data *data, t_entity *entity)
{
	t_drawline	*line;
	double		cos_angle;
	double		sin_angle;

    cos_angle = cos(entity->line.pov[X]);
    sin_angle = sin(entity->line.pov[X]);
	(void)data;
	line = &entity->line;
	if (entity->input & UP)
		move_forward(data, entity, cos_angle, sin_angle);
	if (entity->input & LEFT)
		move_left(data, entity, cos(entity->line.pov[X] + ANGLE_90),\
					 sin(entity->line.pov[X] + ANGLE_90));
	if (entity->input & DOWN)
		move_back(data, entity, cos_angle, sin_angle);
	if (entity->input & RIGHT)
		move_right(data, entity, cos(entity->line.pov[X] - ANGLE_90),\
					 sin(entity->line.pov[X] - ANGLE_90));
	return (0);
}

static void	move_forward(t_data *data, t_entity *entity, double cos, double sin)
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->line.screen[X] + (cos * PLAYER_SPEED);
    new_y = entity->line.screen[Y] - (sin * PLAYER_SPEED);
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
	(void)data;
    if (map_y < 0 || map_y >= data->max_y ||
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1')
        return;
    entity->line.curr_x = new_x;
    entity->line.curr_y = new_y;
    entity->line.screen[X] = new_x;
    entity->line.screen[Y] = new_y + 1;
}

static void	move_back(t_data *data, t_entity *entity, double cos, double sin)
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->line.screen[X] - (cos * PLAYER_SPEED);
    new_y = entity->line.screen[Y] + (sin * PLAYER_SPEED);
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
	(void)data;
    if (map_y < 0 || map_y >= data->max_y ||
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1')
        return;
    entity->line.curr_x = new_x;
    entity->line.curr_y = new_y;
    entity->line.screen[X] = new_x + 1;
    entity->line.screen[Y] = new_y;
}

static void	move_right(t_data *data, t_entity *entity, double cos, double sin)
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->line.screen[X] + (cos * PLAYER_SPEED);
    new_y = entity->line.screen[Y] - (sin * PLAYER_SPEED);
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
	(void)data;
    if (map_y < 0 || map_y >= data->max_y ||
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1')
        return;
    entity->line.curr_x = new_x;
    entity->line.curr_y = new_y;
    entity->line.screen[X] = new_x + 1;
    entity->line.screen[Y] = new_y;
}

static void	move_left(t_data *data, t_entity *entity, double cos, double sin)
{
    double	new_x;
    double	new_y;
    int		map_x;
    int		map_y;

    new_x = entity->line.screen[X] + (cos * PLAYER_SPEED);
    new_y = entity->line.screen[Y] - (sin * PLAYER_SPEED);
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
	(void)data;
    if (map_y < 0 || map_y >= data->max_y ||
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1')
        return;
    entity->line.curr_x = new_x;
    entity->line.curr_y = new_y;
    entity->line.screen[X] = new_x;
    entity->line.screen[Y] = new_y + 1;
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
	else
		return ;
}