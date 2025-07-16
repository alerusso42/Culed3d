/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/16 12:46:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_image_to_image(t_data *data, int which, int y, int x);

/*
	prints minimap on screen.
	//FIXME	we need to resize it. And to center it.
*/
int	map_start(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				put_image_to_image(data, WALL, j * HIMG, i * WIMG);
		}
	}
	return (0);
}

/*
	//NOTE	update this comment when game_loop will be finished.
*/
int	game_loop(t_data *data)
{
	double	pov[2];
	int		i;
	double	diff;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		clear_window(data);
		// map_start(data);
		backgrounder(data);
		data->color = 0xff000d;
		pov[X] = data->player.pov[X] - RADIANT * (FOV / 2);
		pov[Y] = 0;
		i = FOV;
		while (--i >= FOV / 2)
		{
			diff = (double)((double)i / LINE_ACCURACY) - (double)(FOV / LINE_ACCURACY / 2);
			//printf("DIFF:%d\n", (i / LINE_ACCURACY) - (FOV / LINE_ACCURACY / 2));
			compute_line(data, pov[X] + (RADIANT * i), diff);
		}
		while (--i >= 0)
		{
			diff = (double)(FOV /LINE_ACCURACY / 2) - (double)((double)i / LINE_ACCURACY);
			//printf("DIFF:%d\n", (FOV /LINE_ACCURACY / 2) - (i / LINE_ACCURACY));
			compute_line(data, pov[X] + (RADIANT * i), diff);
		}
		(void)diff;
		put_image_to_image(data, PLAYER, data->player.screen[X], data->player.screen[Y]);
		mlx_put_image_to_window(data->mlx, data->win, \
			data->textures[SCREEN], 0, 0);
		test_wall3D(data, -69, -69, true, 0);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

/*
	Fill the screen texture stream data with the chosen color.
*/
void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0 || !color)
		return ;
	index = y * data->size_line + x * data->bpp / 8;
	data->screen[index] = color & 0xFF;
	data->screen[index + 1] = (color >> 8) & 0xFF;
	data->screen[index + 2] = (color >> 16) & 0xFF;
}

/*
	Fill the screen texture stream data with black.
*/
void	clear_window(t_data *data)
{
	int	y;
	int	x;
	int	index;

	y = -1;
	while (++y < HSCREEN)
	{
		x = -1;
		while (++x < WSCREEN)
		{
			index = y * data->size_line + x * data->bpp / 8;
			data->screen[index] = 0;
			data->screen[index + 1] = 0;
			data->screen[index + 2] = 0;
		}
	}
}

/*
	Put an image to the screen texture.
	//FIXME does not work for now.
*/
void	put_image_to_image(t_data *data, int which, int y, int x)
{
	char	*txtr_data;
	int		stuff[3];
	int		color;
	int		index;
	int		i;
	int		j;
	
	txtr_data = mlx_get_data_addr(data->textures[which], \
		&stuff[0], &stuff[1], &stuff[2]);
	if (!txtr_data)
		return ;
	i = 0;
	while (i != HIMG)
	{
		j = 0;
		while (j != WIMG)
		{
			index = i * stuff[1] + j * (stuff[0] / 8);
			color = txtr_data[index];
			color = color | (txtr_data[index + 1] << 8);
			color = color | (txtr_data[index + 2] << 16);
			put_pixel(data, y + j, x + i, color);
			++j;
		}
		i++;
	}
}

// Passaggio per passaggio:
// Espressione	Risultato	Significato
// txtr_data[idx]			0x000000AA	Blue, LSB
// txtr_data[idx+1] << 8)	0x0000BB00	Green
// txtr_data[idx+2] << 16)	0x00CC0000	Red

void	backgrounder(t_data *data)
{
	int	ceiling;
	int	floor;
	int	i;
	int	j;

	ceiling = (data->ceiling_rgb[0] << 16) | (data->ceiling_rgb[1] << 8) | data->ceiling_rgb[2];
	floor = (data->floor_rgb[0] << 16) | (data->floor_rgb[1] << 8) | data->floor_rgb[2];
	j = -1;
	while (++j < WSCREEN)
	{
		i = -1;
		while (++i <= HSCREEN / 2)
		{
			put_pixel(data, j, i, ceiling);
			put_pixel(data, j, i + (HSCREEN / 2), floor);
		}
	}
}

//	TEXTURE:*-> 0:(x + bpp % WIMG) 1:((x + bpp % WIMG) * (line_data * 1)) 2:((x + bpp % WIMG) * (line_data * 2)) N:((x + bpp % WIMG) * (line_data * N))... 

#define FABIO fabs

//	SCREEN:  
void	test_wall3D(t_data *data, int x, int y, bool STOP_PLEASE_STOP_AAAAAH, double pov_line)
{
	//double pov_diff;
	int	color;
	int	ray;
	int	i;
	//double	little_chunk;
	// int	k;
	static int	j = -1;

	if (STOP_PLEASE_STOP_AAAAAH == true)
	{
		j = -1;
		return ;
	}
	i = -1;
	//pov_diff = data->player.pov[X] - pov_line;
	//pov_diff = pov_line;
	// k = -1;
	//printf("REAL|\tx:\t%d\ty:%d\t\n", data->player.screen[X], data->player.screen[Y]);
	int	ray_l;
	ray_l = ray_lenght(data, x, y);
	ray_l = FABIO(ray_l * cos(pov_line));
	ray = safe_division((HSCREEN * 30), ray_l);
	printf("ray: %d\npov_line: %f\n", ray, pov_line);
	color = 255 << 16 | 0 << 8 | 255; //violet
	// printf("j:%d\n", j);
	if (++j < WSCREEN)
	{
		// k = -1;
		// while (++k < FOV_RATIO)
		// {
			i = (HSCREEN / 2) + (ray / 2);
			while (--i >= (HSCREEN / 2) - (ray / 2))
			{
				put_pixel(data, j/*  + k */, i, color);
			}
		// }
		// j += k;
		// mlx_put_image_to_window(data->mlx, data->win, \
		// 	data->textures[SCREEN], 0, 0);
		// mlx_do_sync(data->mlx);
	}
	else
		j = -1;
}

// draw.io integration
// void	test_wall3D(t_data *data, int x, int y)
// {
// 	static char	*wall_addr;
// 	int			color;
// 	int			index;

// 	x %= WIMG;
// 	y %= HIMG;
// 	if (!wall_addr)
// 		wall_addr =  mlx_get_data_addr(data->textures[WALL], &data->bpp, &data->size_line, &data->endian);
// 	else if (!wall_addr)
// 		return ;
// 	index = y * data->size_line + x * (data->bpp / 8);
// 	color = wall_addr[index];
// 	color = color | (wall_addr[index + 1] << 8);
// 	color = color | (wall_addr[index + 2] << 16);
// 	put_pixel(data, y, x, color);
// }