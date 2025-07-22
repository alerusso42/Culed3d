/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/22 10:43:26 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	check_north_collision(t_data *data, t_drawline *line);
	
int	wall_face(t_data * data, t_drawline *line, double angle)
{
	char	face;

	face = 0;
	if ((((int)line->curr_y % (HIMG) == 0) || \
		((int)line->curr_y % (HIMG - 1) == 0)) \
			&& check_north_collision(data, line))
		face |= (NO | SO);
	else
		face |= (WE | EA);
	if (face & (NO | SO))
	{
		if (angle >= 0 && angle < PI)
			return (NORTH);
		else
			return (SOUTH);
	}
	else
	{
		if (angle < PI / 2 || angle >= (PI / 2) * 3)
			return (EAST);
		else
			return (WEST);
	}
}

static bool	check_north_collision(t_data *data, t_drawline *line)
{
	int	x[3];
	int	y[3];

	x[0] = (int)(line->curr_x) / WIMG;
	y[0] = (int)(line->curr_y) / HIMG;
	x[1] = (int)(line->curr_x - 1) / WIMG;
	y[1] = (int)(line->curr_y) / HIMG;
	x[2] = (int)(line->curr_x + 1) / WIMG;
	y[2] = (int)(line->curr_y) / HIMG;
	if (data->map[y[0]][x[0]] == '1' && \
		(data->map[y[1]][x[1]] == '1') && \
		(data->map[y[2]][x[2]] == '1'))
	{
		return (true);
	}
	return (false);
}
