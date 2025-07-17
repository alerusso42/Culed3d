/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:27:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/17 15:25:51 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_player(t_data *data)
{
	data->player.line.screen[X] = data->player.line.map[X] * WIMG;
	data->player.line.screen[Y] = data->player.line.map[Y] * HIMG;
	data->player.line.curr_x = data->player.line.screen[X];
	data->player.line.curr_y = data->player.line.screen[Y];
	if (data->player.line.type == 'E')
		data->player.line.pov[X] = RADIANT * (0 * LINE_ACCURACY);
	else if (data->player.line.type == 'N')
		data->player.line.pov[X] = RADIANT * (90 * LINE_ACCURACY);
	else if (data->player.line.type == 'W')
		data->player.line.pov[X] = RADIANT * (180 * LINE_ACCURACY);
	else if (data->player.line.type == 'S')
		data->player.line.pov[X] = RADIANT * (270 * LINE_ACCURACY);
}
