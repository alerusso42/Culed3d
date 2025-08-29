/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/29 16:06:23 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	frame_render(t_data *data);

/*
	1)	to avoid full CPU speed, we set a time that needs to pass between 
		frames: FRAME_TIME (1 second / FPS).
		if it is not passed, the entire frame is skipped.
	2)	we check inputs and move/rotate player if needed;
	3)	we render the current frame on screen.
*/
int	game_loop(t_data *data)
{
	int		t1;
	int		t2;
	int		t_diff;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		t1 = elapsed_time(data->start);
		if (data->menu)
			main_menu(data);
		else if (data->battle || data->result == RESULT_DRAW)
			battle(data);
		else
		{
			move_player(data);
			mouse_input(data);
			frame_render(data);
		}
		t2 = elapsed_time(data->start);
		t_diff = (t2 - t1) / (int)1e3;
		if (t_diff <= 0)
			return (0);
		printf("~Time:%d ms~;\tFPS:%f\n", t_diff, (1e0 / t_diff) * 1e3);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

/*
	reset_renderer:	set the list of entity to render to zero.
	backgrounder:	put the background on the screen. It deletes last render.
	line:			cast a single ray, and render on the screen the result.
	render_entity:	during the raycasting phase, we save in a list the
					renderer we have seen. In render_entity, we draw them.
					
*/
void	frame_render(t_data *data)
{
	double	pov[2];
	double	angle;
	int		i;

	reset_renderer(data);
	backgrounder(data);
	data->column = 0;
	pov[X] = data->player.pov[X] - (RADIANT * (FOV / 2));
	pov[Y] = 0;
	i = WSCREEN;
	while (--i >= 0)
	{
		angle = ((RADIANT * i) / WSCREEN) * (FOV);
		line(data, &data->player, pov[X] + angle, '1');
		++data->column;
	}
	render_entity(data);
	update_all_animations(data);
	render_arms(data, &data->player);
	render_cross(data);
	map_start(data, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
}
