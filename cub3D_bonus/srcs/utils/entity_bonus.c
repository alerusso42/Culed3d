/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:55:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/06 11:52:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

//	given x, y and an entity type, it returns the index of the entity
//	in its array.
int	which_entity(t_data *data, int x, int y, int entity_type)
{
	t_entity	*entity;
	int			i;

	if (entity_type == ENTITY_DOOR)
		entity = data->doors;
	else if (entity_type == ENTITY_ENEMY)
		return (l_printf("not implemented\n"));
	else
		return (l_printf("Unknown entity type\n"));
	i = 0;
	while (entity[i].type != ENTITY_END)
	{
		if (entity[i].map[X] == x && entity[i].map[Y] == y)
			break ;
		++i;
	}
	if (entity[i].type == ENTITY_END)
		return (ENTITY_NOT_FOUND);
	return (i);
}

bool	collision_entity(t_data *data, int x, int y)
{
	int	i;

	i = -1;
	while (data->doors[++i].type != ENTITY_END)
	{
		if (data->doors[i].map[X] == x && data->doors[i].map[Y] == y)
		{
			if (data->doors[i].type == DOOR_OPENED)
				return (false);
			return (true);
		}
	}
	return (false);
}

int	entity_type(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	if (ft_strchr(PLAYER_CHARS, data->map[y][x]))
		return (data->player.type);
	i = which_entity(data, x, y, ENTITY_DOOR);
	if (i == ENTITY_NOT_FOUND)
		return (ENTITY_NOT_FOUND);
	return (data->doors[i].type);
}
