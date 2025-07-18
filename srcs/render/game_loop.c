/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/18 13:08:39 by alerusso         ###   ########.fr       */
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
	int		t1, t2;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		t1 = elapsed_time(data->start);
		move_player(data);
		frame_render(data);
		t2 = elapsed_time(data->start);
		printf("~Time:%d ms~\n", (t2 - t1) /(int)1e3);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

void	frame_render(t_data *data)
{
	double	pov[2];
	double		i;

	data->column = -1;
	clear_window(data);
	backgrounder(data);
	data->color = 0xff000d;
	pov[X] = data->player.line.pov[X] - (RADIANT * WSCREEN / 2);
	pov[Y] = 0;
	i = RADIANT * WSCREEN;
	while (i >= 0)
	{
		compute_line(data, pov[X] + (RADIANT * i));
		i -= R_FOV;
	}
	put_image_to_image(data, PLAYER, data->player.line.screen[X], data->player.line.screen[Y]);
	mlx_put_image_to_window(data->mlx, data->win, data->textures[SCREEN], 0, 0);
}

// Passaggio per passaggio:
// Espressione	Risultato	Significato
// txtr_data[idx]			0x000000AA	Blue, LSB
// txtr_data[idx+1] << 8)	0x0000BB00	Green
// txtr_data[idx+2] << 16)	0x00CC0000	Red



#define FABIO fabs



