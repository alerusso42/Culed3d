/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:55:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 11:52:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

//	given x, y and an entity type, it returns the index of the entity
//	in its array.
void	*which_entity(t_data *data, int x, int y)
{
	t_entity	*entity;
	int			i;
	int			type;

	type = entity_type(data, x, y);
	if (type == ENTITY_DOOR)
		entity = data->doors;
	else if (type == ENTITY_ENEMY)
		entity = data->enemies;
	else
		return (NULL);
	i = 0;
	while (entity[i].type != ENTITY_END)
	{
		if (entity[i].map[X] == x && entity[i].map[Y] == y)
			break ;
		++i;
	}
	if (entity[i].type == ENTITY_END)
		return (NULL);
	return ((void *)&entity[i]);
}

bool	collision_entity(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (data->doors[++i].type != ENTITY_END)
	{
		if (data->doors[i].map[X] == x && data->doors[i].map[Y] == y)
		{
			if (data->doors[i].type == DOOR_OPEN)
				return (false);
			return (true);
		}
	}
	return (false);
}

bool	all_collision(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (data->doors[++i].type != ENTITY_END)
	{
		if (data->doors[i].map[X] == x && data->doors[i].map[Y] == y)
		{
			return (true);
		}
	}
	return (false);
}

int	entity_type(t_data *data, int x, int y)
{
	if (ft_strchr(PLAYER_CHARS, data->map[y][x]))
		return (data->player.type);
	if (data->map[y][x] == 'D')
		return (ENTITY_DOOR);
	if (data->map[y][x] == 'F')
		return (ENTITY_ENEMY);
	return (ENTITY_NOT_FOUND);
}
