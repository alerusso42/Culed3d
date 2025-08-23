/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 14:43:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	default_settings(t_entity *entity, int x, int y);

/*
	set player struct data.
	screen:		the position in the mini map, with pixel precision
	curr_x/y:	a temp variable used in raycasting to check pixels
	speed:		the amount of movement for every frame
	pov:		the direction, in radiant, which the player points to

	init_animation saves in player an array of two integer.
	those integer are the texture index used for every animation frame.
*/
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
	init_animation(data, &data->player, 2, ARMS1);
	data->player.type = 'N';
}

//	doors are allocated in an array of doors.
//	the data struct is the same as the player (t_entity).
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
				default_settings(&data->doors[curr_door], x, y);
				data->doors[curr_door].type = DOOR_CLOSE;
				curr_door++;
			}
		}
	}
}

//	default settings for every entity.
static void	default_settings(t_entity *entity, int x, int y)
{
	entity->map[X] = x;
	entity->map[Y] = y;
	entity->screen[X] = y * WIMG;
	entity->screen[Y] = x * HIMG;
}
