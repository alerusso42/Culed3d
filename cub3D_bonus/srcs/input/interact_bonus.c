/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:48:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	interact(t_data *data)
{
	int		door_n;
	int		x;
	int		y;
	double	angle;

	angle = data->player.pov[X];
	line(data, &data->player, angle);
	x = data->player.curr_x / WIMG;
	y = data->player.curr_y / HIMG;
	printf("x:%d, y:%d:", x, y);
	if (data->map[y][x] != 'D')
		return ;
	door_n = which_entity(data, x, y, ENTITY_DOOR);
	if (door_n == ENTITY_NOT_FOUND)
		return ;
	if (data->doors[door_n].type == DOOR_CLOSED)
		data->doors[door_n].type = DOOR_OPENED, printf("muro %d aperto!\n", door_n);
	else if (data->doors[door_n].type == DOOR_OPENED)
		data->doors[door_n].type = DOOR_CLOSED, printf("muro %d chiuso!\n", door_n);
}
