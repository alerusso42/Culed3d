/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:13:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/02 12:45:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	move(t_data *data, t_drawline *entity, int keycode)
{
	int	degree;

	degree = 0;
	if (keycode == UP)
		degree = 0;
	else if (keycode == LEFT)
		degree = 90;
	else if (keycode == DOWN)
		degree = 180;
	else if (keycode == RIGHT)
		degree = 270;
	update_delta(entity->pov[X], &entity->delta_x, &entity->delta_y);
	entity->curr_x += 1 * entity->delta_x; 
	entity->curr_y += 1 * entity->delta_y;
	printf("coords vecchie x: %d\ty: %d\n", entity->screen[X], entity->screen[Y]);
	entity->screen[X] = (int)entity->curr_x;
	entity->screen[Y] = (int)entity->curr_y;
	printf("coords aggiornate x: %d\ty: %d\n", entity->screen[X], entity->screen[Y]);
}