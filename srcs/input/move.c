/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/24 15:57:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	move_entity(t_data *data, t_entity *entity, double angle);

/*
	In our game, every entity (player, enemies, objects that moves?) is a
	vector.
	When moving, your are just updating your vector data, and moving
	according to those data.
*/
int	move(t_data *data, t_entity *entity)
{
	double		cos_angle;
	double		sin_angle;

	cos_angle = 0;
	sin_angle = 0;
	(void)data;
	if (entity->input & UP)
		move_entity(data, entity, ANGLE_0);
	if (entity->input & LEFT)
		move_entity(data, entity, ANGLE_90);
	if (entity->input & DOWN)
		move_entity(data, entity, ANGLE_180);
	if (entity->input & RIGHT)
		move_entity(data, entity, ANGLE_270);
	return (0);
}

// static void	move_up(t_data *data, t_entity *entity)
// {
// 	double	cos_angle;
// 	double	sin_angle;

// 	// (void)data;
// 	cos_angle = round_rad(cos(entity->pov[X]));
// 	sin_angle = round_rad(sin(entity->pov[X])) * -1;
// 	if (data->map[(int)(entity->curr[Y] + PLAYER_SPEED * cos_angle) / HIMG][(int)(entity->curr[X] + PLAYER_SPEED * sin_angle) / HIMG] == '1')
// 	{
// 		printf("dati mappa: %c\n", data->map[(int)(entity->curr[Y] + PLAYER_SPEED * cos_angle) / 48][(int)(entity->curr[X] + PLAYER_SPEED * sin_angle) / 48]);
// 		printf("curr[X]: %d\tcurr[Y]: %d\n", (int)(entity->curr[X] + PLAYER_SPEED * cos_angle) / 48, (int)(entity->curr[Y] + PLAYER_SPEED * sin_angle) / 48);
// 		return ;
// 	}
// 	entity->curr[X] += PLAYER_SPEED * cos_angle;
// 	entity->curr[Y] += PLAYER_SPEED * sin_angle;
// 	entity->screen[X] += PLAYER_SPEED * cos_angle;
// 	entity->screen[Y] += PLAYER_SPEED * sin_angle;
// }

static void	move_entity(t_data *data, t_entity *entity, double angle)
{
    double	cos_angle;
    double	sin_angle;
    double	new_x, new_y;
    int		map_x, map_y;

    cos_angle = round_rad(cos(entity->pov[X] + angle));
    sin_angle = round_rad(sin(entity->pov[X] + angle)) * -1;
    new_x = entity->screen[X] + (PLAYER_SPEED * cos_angle);
    new_y = entity->screen[Y] + (PLAYER_SPEED * sin_angle);
    map_x = (int)(new_x) / WIMG;
    map_y = (int)(new_y) / HIMG;
	(void)data;
    if (map_y < 0 || map_y >= data->max_y ||
        map_x < 0 || map_x >= data->max_x)
        return;
    if (data->map[map_y][map_x] == '1')
        return;
    entity->curr[X] = new_x;
    entity->curr[Y] = new_y;
    entity->screen[X] += PLAYER_SPEED * cos_angle;
    entity->screen[Y] += PLAYER_SPEED * sin_angle;
	printf("Total movement:%d[x]\t%d[y]\n", (int)(PLAYER_SPEED * cos_angle), (int)(PLAYER_SPEED * sin_angle));
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
	else
		return ;
}

// static void	move_up(t_data *data, t_entity *entity)
// {
// 	double	cos_angle;
// 	double	sin_angle;
	
// 	cos_angle = round_rad(cos(data->player.pov[X]));
// 	sin_angle = round_rad(sin(data->player.pov[X]));
// 	entity->curr[X] += SPEED * cos_angle;
// 	entity->curr[Y] += SPEED * sin_angle;
// 	if (data->map[(int)entity->curr[Y] / HIMG][(int)entity->curr[X] / WIMG] == '1')
// 	{
// 		entity->curr[X] += SPEED * cos_angle;
// 		entity->curr[Y] += SPEED * sin_angle;
// 		return ;
// 	}
// 	entity->screen[X] = (int)entity->curr[X];
// 	entity->screen[Y] = (int)entity->curr[Y];
// 	entity->map[X] = (int)entity->curr[X] / WIMG;
// 	entity->map[Y] = (int)entity->curr[Y] / HIMG;
// }

// static void	update_all_this_shit(t_data *data, t_entity *entity, double degree)
// {
// 	double	temp_delta_x;
// 	double	temp_delta_y;
// 	// entity->speed = TANTA;
// 	update_delta(entity->pov[X] + degree, &temp_delta_x, &temp_delta_y);
// 	entity->curr[X] += SPEED * temp_delta_x;
// 	entity->curr[Y] += SPEED * temp_delta_y;
// 	if (data->map[(int)entity->curr[Y] / HIMG][(int)entity->curr[X] / WIMG] == '1')
// 	{
// 		entity->curr[X] -= SPEED * temp_delta_x;
// 		entity->curr[Y] -= SPEED * temp_delta_y;
// 		return ;
// 	}
// 	entity->delta_x = temp_delta_x;
// 	entity->delta_y = temp_delta_y;
// 	//printf("BEFORE_MOD|\tx:\t%d\ty:%d\t\n", entity->screen[X], entity->screen[Y]);
// 	entity->screen[X] = (int)entity->curr[X];
// 	entity->screen[Y] = (int)entity->curr[Y];
// 	entity->map[X] = (int)entity->curr[X] / WIMG;
// 	entity->map[Y] = (int)entity->curr[Y] / HIMG;
// 	//printf("MOD|\tx:\t%d\ty:%d\t\n", entity->screen[X], entity->screen[Y]);
// 	if (DEBUG == true)
// 	{
// 		// printf("MOD|\tx:\t%d\ty:%d\t\n", entity->screen[X], entity->screen[Y]);
// 		// printf("map_val: %d\n", data->map[(int)entity->curr[Y] / HIMG][(int)entity->curr[X] / WIMG]);
// 	}
// }