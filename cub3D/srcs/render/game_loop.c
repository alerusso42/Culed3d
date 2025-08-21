/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 12:54:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
	prints minimap on screen.
	//FIXME	we need to resize it. And to center it.
*/

void	frame_render(t_data *data);

/*
	//NOTE	update this comment when game_loop will be finished.
*/
int	game_loop(t_data *data)
{
	int	t1;
	int	t2;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		t1 = elapsed_time(data->start);
		move_player(data);
		frame_render(data);
		t2 = elapsed_time(data->start);
		printf("~Time:%d ms~\n", (t2 - t1) / (int)1e3);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

void	line(t_data *data, t_entity *entity, double angle);

void	frame_render(t_data *data)
{
	double	pov[2];
	double	angle;
	int		i;

	backgrounder(data);
	data->column = 0;
	data->color = 0xff000d;
	pov[X] = data->player.pov[X] - (RADIANT * (FOV / 2));
	pov[Y] = 0;
	i = WSCREEN;
	while (--i >= 0)
	{
		angle = ((RADIANT * i) / WSCREEN) * (FOV);
		line(data, &data->player, pov[X] + angle);
		++data->column;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->textures[SCREEN], 0, 0);
}

void line(t_data *data, t_entity *entity, double angle)
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
	while (!the_wall_checker(entity, data))
	{
		x += cos_angle;
		y += sin_angle;
		entity->curr_x = x;
		entity->curr_y = y;
	}
	test_wall3D(data, (int)entity->curr_x, (int)entity->curr_y, angle);
}
