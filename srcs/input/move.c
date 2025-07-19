/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/18 10:32:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	update_all_this_shit(t_data *data, t_drawline *line, double degree);

/*
	In our game, every entity (player, enemies, objects that moves?) is a
	vector.
	When moving, your are just updating your vector data, and moving
	according to those data.
*/
int	move(t_data *data, t_entity *entity)
{
	t_drawline	*line;

	(void)data;
	line = &entity->line;
	if (entity->input & UP)
		update_all_this_shit(data, line, RADIANT * (0 * LINE_ACCURACY));
	if (entity->input & LEFT)
		update_all_this_shit(data, line, RADIANT * (90 * LINE_ACCURACY));
	if (entity->input & DOWN)
		update_all_this_shit(data, line, RADIANT * (180 * LINE_ACCURACY));
	if (entity->input & RIGHT)
		update_all_this_shit(data, line, RADIANT * (270 * LINE_ACCURACY));
	return (0);
}

/*
	Rotate has LINE_ACCURACY sensibility.
	If LINE_ACCURACY is one, sensibility is 1 grade.
*/
void	rotate(t_data *data, t_entity *entity)
{
	(void)data;
	if (entity->input & R_LEFT)
		entity->line.pov[X] += RADIANT * (1 * LINE_ACCURACY) + (30 * RADIANT);
	if (entity->input & R_RIGHT)
		entity->line.pov[X] += RADIANT * (-1 * LINE_ACCURACY) + (-30 * RADIANT);
	else
		return ;
}

static void	update_all_this_shit(t_data *data, t_drawline *line, double degree)
{
	double	temp_delta_x;
	double	temp_delta_y;
	// line->speed = TANTA;
	update_delta(line->pov[X] + degree, &temp_delta_x, &temp_delta_y);
	line->curr_x += SPEED * temp_delta_x;
	line->curr_y += SPEED * temp_delta_y;
	if (data->map[(int)line->curr_y / HIMG][(int)line->curr_x / WIMG] == '1')
	{
		line->curr_x -= SPEED * temp_delta_x;
		line->curr_y -= SPEED * temp_delta_y;
		return ;
	}
	line->delta_x = temp_delta_x;
	line->delta_y = temp_delta_y;
	//printf("BEFORE_MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
	line->screen[X] = (int)line->curr_x;
	line->screen[Y] = (int)line->curr_y;
	line->map[X] = (int)line->curr_x / WIMG;
	line->map[Y] = (int)line->curr_y / HIMG;
	//printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
	if (DEBUG == true)
	{
		// printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
		// printf("map_val: %d\n", data->map[(int)line->curr_y / HIMG][(int)line->curr_x / WIMG]);
	}
}