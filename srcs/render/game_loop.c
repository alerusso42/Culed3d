/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/24 16:21:27 by alerusso         ###   ########.fr       */
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
		//printf("~Time:%d ms~\n", (t2 - t1) /(int)1e3);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

void line(t_data *data, t_entity *entity, double angle);

void	frame_render(t_data *data)
{
	double	pov[2];
	double	angle;
	int		i;

	// backgrounder(data);
	clear_window(data);
	map_start(data);
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
	put_image_to_image(data, PLAYER, data->player.screen[X], data->player.screen[Y]);
	mlx_put_image_to_window(data->mlx, data->win, data->textures[SCREEN], 0, 0);
}

// Passaggio per passaggio:
// Espressione	Risultato	Significato
// txtr_data[idx]			0x000000AA	Blue, LSB
// txtr_data[idx+1] << 8)	0x0000BB00	Green
// txtr_data[idx+2] << 16)	0x00CC0000	Red

void line(t_data *data, t_entity *entity, double angle)
{
    double x;
    double y;
    float cos_angle;
    float sin_angle;
	
	x = entity->screen[X];
	y = entity->screen[Y];
    entity->curr[X] = x;
    entity->curr[Y] = y;
	if (angle > (2 * PI))
		angle -= (2 * PI);
	else if (angle < 0)
		angle += (2 * PI);
	cos_angle = round_rad(cos(angle));
	sin_angle = round_rad(sin(angle)) * -1;
    while (!the_wall_checker(entity, data))
    {
        put_pixel(data, (int)x, (int)y, 0xFF0000);
        x += cos_angle;
        y += sin_angle;
        entity->curr[X] = x;
        entity->curr[Y] = y;
    }
	// wall(data, entity->curr[X], data->textures[wall_face(data, line, angle)]);
	test_wall3D(data, (int)entity->curr[X], (int)entity->curr[Y], angle);
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
// 	image_ptr = DATA_ADDR(txtr, &image[screen_data[BPP]], &image[SIZE], &image[screen_data[ENDIAN]]);
// 	if (!image_ptr)
// 		return ;
// 	i = pixel * (image[screen_data[BPP]] / 8) + (image[SIZE] * TXTR);
// 	printf("x:\t%d\n", i);
// 	color = image_ptr[i + 2] | (image_ptr[i + 1] << 8) | (image_ptr[i] << 16);
// 	put_pixel(data, (int)x, 200, color);
// }

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
// 	image_ptr = mlx_get_data_addr(txtr, &image[screen_data[BPP]], &image[SIZE], &image[screen_data[ENDIAN]]);
// 	if (!image_ptr)
// 		return ;
// 	i = pixel * (image[SIZE]);
// 	printf("y:\t%d\tsize:%d\n", i, (image[SIZE]));
// 	color = image_ptr[i + 2] | (image_ptr[i + 1] << 8) | (image_ptr[i] << 16);
// 	put_pixel(data, (int)x, 50, color);
// }
