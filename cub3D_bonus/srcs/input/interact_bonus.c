/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:48:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/24 12:25:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static	void	door_line(t_data *data, t_entity *entity, double angle);
static	int	the_entity_checker(t_entity *entity, t_data *data);

void	interact(t_data *data)
{
	t_entity	*entity;
	int			x;
	int			y;
	double		angle;

	angle = data->player.pov[X];
	door_line(data, &data->player, angle);
	x = data->player.curr_x / WIMG;
	y = data->player.curr_y / HIMG;
	if (data->map[y][x] != 'D')
		return ;
	entity = which_entity(data, x, y);
	if (!entity)
		return ;
	if (ray_lenght(data, data->player.curr_x, data->player.curr_y) >= 150)
		return ;
	if (entity->type == DOOR_CLOSE)
	{
		entity->type = DOOR_OPEN;
		entity->frames[0] = &data->txtr[DOOR_OPEN];
	}
	else if (entity->type == DOOR_OPEN)
	{
		entity->type = DOOR_CLOSE;
		entity->frames[0] = &data->txtr[DOOR_CLOSE];
	}
}

static	void	door_line(t_data *data, t_entity *entity, double angle)
{
	double	x;
	double	y;
	float	cos_angle;
	float	sin_angle;

	x = entity->screen[X];
	y = entity->screen[Y];
	entity->curr_x = x;
	entity->curr_y = y;
	if (angle > (2 * PI))
		angle -= (2 * PI);
	else if (angle < 0)
		angle += (2 * PI);
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
	while (!the_entity_checker(entity, data))
	{
		x += cos_angle;
		y += sin_angle;
		entity->curr_x = x;
		entity->curr_y = y;
	}
}

static int	the_entity_checker(t_entity *entity, t_data *data)
{
	int	x;
	int	y;

	x = (int)entity->curr_x / WIMG;
	y = (int)entity->curr_y / HIMG;
	if (data->player.map[X] == x && data->player.map[Y] == y)
		return (false);
	if (data->map[y][x] == 'D' || data->map[y][x] == '1')
	{
		return (true);
	}
	return (false);
}
