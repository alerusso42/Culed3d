/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 12:51:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	the_wall_checker(t_entity *entity, t_data *data)
{
	int	x;
	int	y;

	x = (int)entity->curr_x / WIMG;
	y = (int)entity->curr_y / HIMG;
	if (data->map[y][x] == '1' || data->map[y][x] == ' ')
	{
		return (true);
	}
	return (false);
}

double	ray_lenght(t_data *data, int rx, int ry)
{
	double	ray;
	int		px;
	int		py;

	px = data->player.screen[X];
	py = data->player.screen[Y];
	rx = abs(rx);
	ry = abs(ry);
	ray = sqrt(pow((double)(rx - px), 2) + pow((double)(ry - py), 2));
	return (ray);
}
