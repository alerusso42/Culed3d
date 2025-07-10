/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 14:17:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player(t_data *data)
{
	data->player.screen[X] = data->player.map[X] * WIMG;
	data->player.screen[Y] = data->player.map[Y] * HIMG;
	data->player.curr_x = data->player.screen[X];
	data->player.curr_y = data->player.screen[Y];
	if (data->player.type == 'E')
		data->player.pov[X] = RADIANT * (0 * 20);
	else if (data->player.type == 'N')
		data->player.pov[X] = RADIANT * (90 * 20);
	else if (data->player.type == 'W')
		data->player.pov[X] = RADIANT * (180 * 20);
	else if (data->player.type == 'S')
		data->player.pov[X] = RADIANT * (270 * 20);
	//data->player.pov[X] = RADIANT * 225 * 20;
}
