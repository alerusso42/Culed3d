/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/19 13:38:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	default_settings(t_entity *entity, int x, int y);
static void	init_animation(t_data *data, t_entity *entity, int n, int *frames);

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
	init_animation(data, &data->player, 2, (int [2])\
	{NORTH, EAST});
	data->player.type = 'N';
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
				default_settings(&data->doors[curr_door], x, y);
				data->doors[curr_door].type = DOOR_CLOSED;
				curr_door++;
			}
		}
	}
}

static void	default_settings(t_entity *entity, int x, int y)
{
	entity->map[X] = x;
	entity->map[Y] = y;
	entity->screen[X] = y * WIMG;
	entity->screen[Y] = x * HIMG;
}

static void	init_animation(t_data *data, t_entity *entity, int n, int *frames)
{
	int	i;

	entity->f_time = ANIMATION_SPEED;
	entity->frames = ft_calloc((n + 1), sizeof(int));
	if (!entity->frames)
		return (error(data, E_MALLOC, NULL));
	i = 0;
	while (i < n)
	{
		entity->frames[i] = frames[i];
		++i;
	}
	entity->frames[i] = -1;
}
