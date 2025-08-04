/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/04 14:23:47 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	init_player(t_data *data)
{
	data->player.screen[X] = data->player.map[X] * WIMG;
	data->player.screen[Y] = data->player.map[Y] * HIMG;
	data->player.curr_x = data->player.screen[X];
	data->player.curr_y = data->player.screen[Y];
	data->player.speed = 5;
	if (data->player.type == 'E')
		data->player.pov[X] = RADIANT * (0);
	else if (data->player.type == 'N')
		data->player.pov[X] = RADIANT * (90);
	else if (data->player.type == 'W')
		data->player.pov[X] = RADIANT * (180);
	else if (data->player.type == 'S')
		data->player.pov[X] = RADIANT * (270);
}

void	init_doors(t_data *data, int n_doors)
{
	int		y;
	int		x;
	int		curr_door;

	data->doors = malloc((n_doors + 1) * sizeof(t_entity));
	if (!data->doors)
		error(data, E_MALLOC, NULL);
	data->doors[n_doors] = (t_entity){0};
	curr_door = 0;
	y = -1;
	while (data->map && data->map[++y])
	{
		x = -1;
		while (data->map && data->map[y][++x])
		{
			if (data->map[y][x] == 'D')
			{
				data->doors[curr_door] = (t_entity){0};
				data->doors[curr_door].map[X] = x;
				data->doors[curr_door].map[Y] = y;
				data->doors[curr_door].screen[X] = y * WIMG;
				data->doors[curr_door].screen[Y] = x * HIMG;
				data->doors[curr_door].type = DOOR_CLOSED;
				curr_door++;
			}
		}
	}
	curr_door = 0;
	while (curr_door != n_doors)
	{
		printf("entity %d:map\t%d\t%d\t\n", curr_door, data->doors[curr_door].map[X], data->doors[curr_door].map[Y]);
		printf("screen:\t%d\t%d\n", data->doors[curr_door].screen[X], data->doors[curr_door].screen[Y]);
		++curr_door;
	}
}
