/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/02 15:43:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player(t_data *data)
{
	data->player.line.screen[X] = data->player.line.map[X] * WIMG;
	data->player.line.screen[Y] = data->player.line.map[Y] * HIMG;
	data->player.line.curr_x = data->player.line.screen[X];
	data->player.line.curr_y = data->player.line.screen[Y];
	data->player.speed = 5;
	if (data->player.type == 'E')
		data->player.line.pov[X] = RADIANT * (0);
	else if (data->player.type == 'N')
		data->player.line.pov[X] = RADIANT * (90);
	else if (data->player.type == 'W')
		data->player.line.pov[X] = RADIANT * (180);
	else if (data->player.type == 'S')
		data->player.line.pov[X] = RADIANT * (270);
}
