/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/17 17:50:24 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	update_all_this_shit(t_drawline *line, double degree);

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
		update_all_this_shit(line, RADIANT * (0 * LINE_ACCURACY));
	if (entity->input & LEFT)
		update_all_this_shit(line, RADIANT * (90 * LINE_ACCURACY));
	if (entity->input & DOWN)
		update_all_this_shit(line, RADIANT * (180 * LINE_ACCURACY));
	if (entity->input & RIGHT)
		update_all_this_shit(line, RADIANT * (270 * LINE_ACCURACY));
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

static void	update_all_this_shit(t_drawline *line, double degree)
{
	// line->speed = TANTA;
	update_delta(line->pov[X] + degree, &line->delta_x, &line->delta_y);
	line->curr_x += SPEED * line->delta_x;
	line->curr_y += SPEED * line->delta_y;
	//printf("BEFORE_MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
	line->screen[X] = (int)line->curr_x;
	line->screen[Y] = (int)line->curr_y;
	line->map[X] = (int)line->curr_x / WIMG;
	line->map[Y] = (int)line->curr_y / HIMG;
	//printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
	if (DEBUG == true)
	{
		//printf("MOD|\tx:\t%d\ty:%d\t\n", line->screen[X], line->screen[Y]);
		//printf("sin(pov): %f\n", sin(line->pov[X]));
	}
}