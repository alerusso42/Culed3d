/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/22 09:01:33 by alerusso         ###   ########.fr       */
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

void line(t_data *data, t_drawline *line, double angle);

void	frame_render(t_data *data)
{
	double	pov[2];
	double	angle;
	int		i;

	// data->column = -1;
	clear_window(data);
	// backgrounder(data);
	map_start(data);
	data->color = 0xff000d;
	pov[X] = data->player.line.pov[X] - (RADIANT * (FOV / 2));
	pov[Y] = 0;
	i = WSCREEN;
	while (--i >= 0)
	{
		// angle = RADIANT * (i / WSCREEN) * (FOV);
		angle = ((RADIANT * i) / WSCREEN) * (FOV);
		line(data, &data->player.line, pov[X] + angle);
	}
	put_image_to_image(data, PLAYER, data->player.line.screen[X], data->player.line.screen[Y]);
	mlx_put_image_to_window(data->mlx, data->win, data->textures[SCREEN], 0, 0);
	data->column = -1;
}

// Passaggio per passaggio:
// Espressione	Risultato	Significato
// txtr_data[idx]			0x000000AA	Blue, LSB
// txtr_data[idx+1] << 8)	0x0000BB00	Green
// txtr_data[idx+2] << 16)	0x00CC0000	Red

int	piedi(t_drawline *line, double angle);

void line(t_data *data, t_drawline *line, double angle)
{
    double x;
    double y;
    float cos_angle;
    float sin_angle;
	
	x = line->screen[X];
	y = line->screen[Y];
    line->curr_x = x;
    line->curr_y = y;
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
    while (!the_wall_checker(line, data))
    {
        put_pixel(data, (int)x, (int)y, 0xFF0000);
        x += cos_angle;
        y += sin_angle;
        line->curr_x = x;
        line->curr_y = y;
    }
	piedi(line, angle);
	// test_wall3D(data, (int)line->curr_x, (int)line->curr_y, angle);
}

int	piedi(t_drawline *line, double angle)
{
	bool	nord;
	bool	sud;
	bool	east;
	bool	west;

	nord = false;
	sud = false;
	east = false;
	west = false;
	if ((int)line->curr_y % (HIMG - 1) == 0)
	{
		printf("N/S:\t%d\t", (int)line->curr_y);
		nord = true;
		sud = true;
	}
	else
	{
		printf("W/E:\t%d\t", (int)line->curr_x);
		west = true;
		east = true;
	}
	if (nord == true)
	{
		if (angle >= 0 && angle < PI)
			sud = false;
		else
			nord = false;
	}
	else
	{
		if (angle < PI / 2 || angle >= (PI / 2) * 3)
			west = false;
		else
			east = false;
	}
	if (nord)
		printf("nord:\t%f\n", angle);
	else if (sud)
		printf("sud:\t%f\n", angle);
	else if (east)
		printf("east:\t%f\n", angle);
	else
		printf("west:\t%f\n", angle);
	return (INT_MAX);
}
