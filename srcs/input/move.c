/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 14:36:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
	In our game, every entity (player, enemies, objects that moves?) is a
	vector.
	When moving, your are just updating your vector data, and moving
	according to those data.
*/
int	move(t_data *data, t_drawline *entity, int keycode)
{
	double	degree;

	(void)data;
	(void)keycode;
	degree = 0;
	if (DEBUG == true)
	{
		printf("cos(pov): %f\n", cos(entity->pov[X]));
		printf("sin(pov): %f\n", sin(entity->pov[X]));
	}
	if (keycode == UP)
		degree = RADIANT * (0 * LINE_ACCURACY);
	if (keycode == LEFT)
		degree = RADIANT * (90 * LINE_ACCURACY);
	if (keycode == DOWN)
		degree = RADIANT * (180 * LINE_ACCURACY);
	if (keycode == RIGHT)
		degree = RADIANT * (270 * LINE_ACCURACY);
	update_delta(entity->pov[X] + degree, &entity->delta_x, &entity->delta_y);
	entity->curr_x += (SPEED + entity->speed) * entity->delta_x;
	entity->curr_y += (SPEED + entity->speed) * entity->delta_y;
	entity->screen[X] = (int)entity->curr_x;
	entity->screen[Y] = (int)entity->curr_y;
	return (0);
}

/*
	Rotate has LINE_ACCURACY sensibility.
	If LINE_ACCURACY is one, sensibility is 1 grade.
*/
void	rotate(t_data *data, t_drawline *entity, int dir)
{
	(void)data;
	if (dir == R_LEFT)
		entity->pov[X] += RADIANT * (1 * LINE_ACCURACY);
	else if (dir == R_RIGHT)
		entity->pov[X] += RADIANT * (-1 * LINE_ACCURACY);
	else
		return ;
}
