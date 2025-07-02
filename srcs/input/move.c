/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/02 17:54:10 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	move(t_data *data, t_drawline *entity, int keycode)
{
	double	degree;

	(void)data;
	// (void)keycode;
	degree = 0;
	printf("cos(pov): %f\n", cos(entity->pov[X]));
	printf("sin(pov): %f\n", sin(entity->pov[X]));
	if (keycode == UP)
		degree = RADIANT * (0 * 20);
	if (keycode == LEFT)
		degree = RADIANT * (90 * 20);
	if (keycode == DOWN)
		degree = RADIANT * (180 * 20);
	if (keycode == RIGHT)
		degree = RADIANT * (270 * 20);
	update_delta(entity->pov[X] + degree, &entity->delta_x, &entity->delta_y);
	entity->curr_x += (SPEED + entity->speed) * entity->delta_x; 
	entity->curr_y += (SPEED + entity->speed) * entity->delta_y;
	entity->screen[X] = (int)entity->curr_x;
	entity->screen[Y] = (int)entity->curr_y;
	return (0);
}

void	rotate(t_data *data, t_drawline *entity, int dir)
{
	(void)data;
	if (dir == R_LEFT)
		entity->pov[X] += RADIANT * (1* 20);
	else if (dir == R_RIGHT)
		entity->pov[X] += RADIANT * (-1 * 20);
	else
		return ;
}