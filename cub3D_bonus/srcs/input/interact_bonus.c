/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:48:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/06 08:45:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void door_line(t_data *data, t_entity *entity, double angle);
static int	the_entity_checker(t_entity *entity, t_data *data);

void	interact(t_data *data)
{
	int		door_n;
	int		x;
	int		y;
	double	angle;

	angle = data->player.pov[X];
	door_line(data, &data->player, angle);
	x = data->player.curr_x / WIMG;
	y = data->player.curr_y / HIMG;
	printf("x:%d, y:%d:", x, y);
	if (data->map[y][x] != 'D')
		return ;
	door_n = which_entity(data, x, y, ENTITY_DOOR);
	if (door_n == ENTITY_NOT_FOUND)
		return ;
	if (data->doors[door_n].type == DOOR_CLOSED && ray_lenght(data, data->player.curr_x, data->player.curr_y) < 50)
		data->doors[door_n].type = DOOR_OPENED, printf("muro %d aperto!\n", door_n);
	else if (data->doors[door_n].type == DOOR_OPENED  && ray_lenght(data, data->player.curr_x, data->player.curr_y) < 50)
		data->doors[door_n].type = DOOR_CLOSED, printf("muro %d chiuso!\n", door_n);
}

static void door_line(t_data *data, t_entity *entity, double angle)
{
    double x;
    double y;
    float cos_angle;
    float sin_angle;

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
	l_printf("x:%d, y:%d:\n", x, y);
	l_printf("x:%d, y:%d:\n", data->player.map[X], data->player.map[Y]);
	if (data->player.map[X] == x && data->player.map[Y] == y)
		return (false);
	if (data->map[y][x] == 'D' || data->map[y][x] == '1')
	{
		return (true);
	}
	return (false);
}
