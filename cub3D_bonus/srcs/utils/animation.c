/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:59:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 14:35:04 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	update_animation(t_entity *entity);

void	animation(t_data *data, t_entity *entity)
{
	int	pos[2];
	int	size[2];

	if (entity->type == 'N' && entity->input & MOVEMENT)
		update_animation(entity);
	size[X] = data->txtr[entity->frames[entity->f_curr]].size[X] / 4;
	size[Y] = data->txtr[entity->frames[entity->f_curr]].size[Y];
	pos[X] = 300;
	pos[Y] = 700;
	put_image_to_image(data, entity->frames[entity->f_curr], pos, size);
	mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
}

static void	update_animation(t_entity *entity)
{
	if (entity->frames[entity->f_curr] == -1)
	{
		entity->f_curr = 0;
		entity->f_elapsed = 0;
		return ;
	}
	if (entity->f_elapsed >= entity->f_time)
	{
		entity->f_curr += 1;
		entity->f_elapsed = 0;
	}
	if (entity->frames[entity->f_curr] == -1)
	{
		entity->f_curr = 0;
		entity->f_elapsed = 0;
		return ;
	}
	entity->f_elapsed += 1;
}
