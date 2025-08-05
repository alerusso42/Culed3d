/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/05 14:43:30 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

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
	// put_image_to_image(data, CROSSHAIR, (HSCREEN / 2) + 32, (WSCREEN / 2) - 64);
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
        put_pixel(data, (int)x, (int)y, 0xFF0000);
        x += cos_angle;
        y += sin_angle;
        entity->curr_x = x;
        entity->curr_y = y;
    }
	// wall(data, entity->curr_x, data->textures[wall_face(data, line, angle)]);
	// test_wall3D(data, (int)entity->curr_x, (int)entity->curr_y, angle);
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
// 	image_ptr = DATA_ADDR(txtr, &image[BPP], &image[SIZE], &image[ENDIAN]);
// 	if (!image_ptr)
// 		return ;
// 	i = pixel * (image[BPP] / 8) + (image[SIZE] * TXTR);
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
// 	image_ptr = mlx_get_data_addr(txtr, &image[BPP], &image[SIZE], &image[ENDIAN]);
// 	if (!image_ptr)
// 		return ;
// 	i = pixel * (image[SIZE]);
// 	printf("y:\t%d\tsize:%d\n", i, (image[SIZE]));
// 	color = image_ptr[i + 2] | (image_ptr[i + 1] << 8) | (image_ptr[i] << 16);
// 	put_pixel(data, (int)x, 50, color);
// }
