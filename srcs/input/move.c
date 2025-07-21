/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/21 10:02:10 by alerusso         ###   ########.fr       */
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
// int	move(t_data *data, t_entity *entity)
// {
// 	t_drawline	*line;

// 	(void)data;
// 	line = &entity->line;
// 	if (entity->input & UP)
// 	{
// 		entity->line.curr_y -= PLAYER_SPEED;
// 		entity->line.screen[Y] -= PLAYER_SPEED;
// 	}
// 	if (entity->input & LEFT)
// 	{
// 		entity->line.curr_x -= PLAYER_SPEED;
// 		entity->line.screen[X] -= PLAYER_SPEED;	
// 	}
// 	if (entity->input & DOWN)
// 	{
// 		entity->line.curr_y += PLAYER_SPEED;
// 		entity->line.screen[Y] += PLAYER_SPEED;
// 	}
// 	if (entity->input & RIGHT)
// 	{
// 		entity->line.curr_x += PLAYER_SPEED;
// 		entity->line.screen[X] += PLAYER_SPEED;
// 	}
// 	return (0);
// }

int	move(t_data *data, t_entity *entity)
{
	t_drawline	*line;
	double		cos_angle;
	double		sin_angle;

	cos_angle = 0;
	sin_angle = 0;
	(void)data;
	line = &entity->line;
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
// 	cos_angle = round_rad(cos(entity->line.pov[X]));
// 	sin_angle = round_rad(sin(entity->line.pov[X])) * -1;
// 	if (data->map[(int)(entity->line.curr_y + PLAYER_SPEED * cos_angle) / HIMG][(int)(entity->line.curr_x + PLAYER_SPEED * sin_angle) / HIMG] == '1')
// 	{
// 		printf("dati mappa: %c\n", data->map[(int)(entity->line.curr_y + PLAYER_SPEED * cos_angle) / 48][(int)(entity->line.curr_x + PLAYER_SPEED * sin_angle) / 48]);
// 		printf("curr_x: %d\tcurr_y: %d\n", (int)(entity->line.curr_x + PLAYER_SPEED * cos_angle) / 48, (int)(entity->line.curr_y + PLAYER_SPEED * sin_angle) / 48);
// 		return ;
// 	}
// 	entity->line.curr_x += PLAYER_SPEED * cos_angle;
// 	entity->line.curr_y += PLAYER_SPEED * sin_angle;
// 	entity->line.screen[X] += PLAYER_SPEED * cos_angle;
// 	entity->line.screen[Y] += PLAYER_SPEED * sin_angle;
// }

static void	move_entity(t_data *data, t_entity *entity, double angle)
{
    double	cos_angle;
    double	sin_angle;
    double	new_x, new_y;
    int		map_x, map_y;

    cos_angle = round_rad(cos(entity->line.pov[X] + angle));
    sin_angle = round_rad(sin(entity->line.pov[X] + angle)) * -1;
    new_x = entity->line.screen[X] + PLAYER_SPEED * cos_angle;
    new_y = entity->line.screen[Y] + PLAYER_SPEED * sin_angle;
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
    entity->line.screen[X] += PLAYER_SPEED * cos_angle;
    entity->line.screen[Y] += PLAYER_SPEED * sin_angle;
}
/*
	Rotate has LINE_ACCURACY sensibility.
	If LINE_ACCURACY is one, sensibility is 1 grade.
*/
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

// static void	move_up(t_data *data, t_drawline *line)
// {
// 	double	cos_angle;
// 	double	sin_angle;
	
// 	cos_angle = round_rad(cos(data->player.line.pov[X]));
// 	sin_angle = round_rad(sin(data->player.line.pov[X]));
// 	line->curr_x += SPEED * cos_angle;
// 	line->curr_y += SPEED * sin_angle;
// 	if (data->map[(int)line->curr_y / HIMG][(int)line->curr_x / WIMG] == '1')
// 	{
// 		line->curr_x += SPEED * cos_angle;
// 		line->curr_y += SPEED * sin_angle;
// 		return ;
// 	}
// 	line->screen[X] = (int)line->curr_x;
// 	line->screen[Y] = (int)line->curr_y;
// 	line->map[X] = (int)line->curr_x / WIMG;
// 	line->map[Y] = (int)line->curr_y / HIMG;
// }

// static void	update_all_this_shit(t_data *data, t_drawline *line, double degree)
// {
// 	double	temp_delta_x;
// 	double	temp_delta_y;
// 	// line->speed = TANTA;
// 	update_delta(line->pov[X] + degree, &temp_delta_x, &temp_delta_y);
// 	line->curr_x += SPEED * temp_delta_x;
// 	line->curr_y += SPEED * temp_delta_y;
// 	if (data->map[(int)line->curr_y / HIMG][(int)line->curr_x / WIMG] == '1')
// 	{
// 		line->curr_x -= SPEED * temp_delta_x;
// 		line->curr_y -= SPEED * temp_delta_y;
// 		return ;
// 	}
// 	line->delta_x = temp_delta_x;
// 	line->delta_y = temp_delta_y;
// 	//printf("BEFORE_MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
// 	line->screen[X] = (int)line->curr_x;
// 	line->screen[Y] = (int)line->curr_y;
// 	line->map[X] = (int)line->curr_x / WIMG;
// 	line->map[Y] = (int)line->curr_y / HIMG;
// 	//printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
// 	if (DEBUG == true)
// 	{
// 		// printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
// 		// printf("map_val: %d\n", data->map[(int)line->curr_y / HIMG][(int)line->curr_x / WIMG]);
// 	}
// }