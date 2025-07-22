/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/22 16:35:32 by alerusso         ###   ########.fr       */
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

	backgrounder(data);
	// map_start(data);
	data->color = 0xff000d;
	pov[X] = data->player.line.pov[X] - (RADIANT * (FOV / 2));
	pov[Y] = 0;
	i = WSCREEN;
	while (--i >= 0)
	{
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
	wall(data, line->curr_x, data->textures[wall_face(data, line, angle)]);
	// test_wall3D(data, (int)line->curr_x, (int)line->curr_y, angle);
}

# define DATA_ADDR mlx_get_data_addr

void	wall(t_data *data, double x, void *txtr)
{
	int		pixel;
	int		i;
	int		image[3];
	int		color;
	char	*image_ptr;

	(void)data, (void)txtr, (void)pixel;
	pixel = (int)(((x / WIMG) - (int)(x / WIMG)) * TXTR);
	printf("x :\t%f, temp :%d\t", x, pixel);
	image_ptr = DATA_ADDR(txtr, &image[BPP], &image[SIZE], &image[ENDIAN]);
	if (!image_ptr)
		return ;
	i = pixel * (image[BPP] / 8) + (image[SIZE] * TXTR);
	printf("x:\t%d\n", i);
	color = image_ptr[i + 2] | (image_ptr[i + 1] << 8) | (image_ptr[i] << 16);
	put_pixel(data, (int)x, 200, color);
}

// void	wall(t_data *data, double x, void *txtr)
// {
// 	int		pixel;
// 	int		i;
// 	int		image[3];
// 	int		color;
// 	char	*image_ptr;

// 	(void)data, (void)txtr, (void)pixel;
// 	pixel = (int)(((x / WIMG) - (int)(x / WIMG)) * TXTR);
// 	printf("x :\t%f, temp :%d\t", x, pixel);
// 	image_ptr = mlx_get_data_addr(txtr, &image[BPP], &image[SIZE], &image[ENDIAN]);
// 	if (!image_ptr)
// 		return ;
// 	i = pixel * (image[SIZE]);
// 	printf("y:\t%d\tsize:%d\n", i, (image[SIZE]));
// 	color = image_ptr[i + 2] | (image_ptr[i + 1] << 8) | (image_ptr[i] << 16);
// 	put_pixel(data, (int)x, 50, color);
// }
