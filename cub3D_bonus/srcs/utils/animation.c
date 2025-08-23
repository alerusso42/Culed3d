/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:59:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 15:18:17 by alerusso         ###   ########.fr       */
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
	size[X] = entity->frames[entity->f_curr]->size[X] / 4;
	size[Y] = entity->frames[entity->f_curr]->size[Y];
	pos[X] = 300;
	pos[Y] = 700;
	put_image_to_image(data, entity->frames[entity->f_curr]->i, pos, size);
}

static void	update_animation(t_entity *entity)
{
	entity->f_time = ANIMATION_SPEED / entity->speed;
	if (!entity->frames[entity->f_curr])
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
	if (entity->frames[entity->f_curr] == NULL)
	{
		entity->f_curr = 0;
		entity->f_elapsed = 0;
		return ;
	}
	entity->f_elapsed += 1;
}

void	init_animation(t_data *data, t_entity *entity, int n, int first)
{
	int	i;

	entity->f_time = ANIMATION_SPEED;
	entity->frames = ft_calloc((n + 1), sizeof(t_txtr));
	if (!entity->frames)
		return (error(data, E_MALLOC, NULL));
	i = 0;
	while (i < n)
	{
		entity->frames[i] = &data->txtr[first + i];
		++i;
	}
	entity->frames[i] = NULL;
}
