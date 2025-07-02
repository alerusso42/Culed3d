/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:18:02 by lparolis          #+#    #+#             */
/*   Updated: 2025/07/02 18:07:37 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_image_to_image(t_data *data, int which, int y, int x);

int	map_start(t_data *data)
{
	// (void)data;
	int i;
	int j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[WALL], i * 48, j * 48);
			else if (ft_strchr("NSEW", data->map[i][j]))
				mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[PLAYER], i * 48, j * 48);
		}
	}
	return (0);
}

int	game_loop(t_data *data)
{
	double	pov[2];
	int i;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		clear_window(data);
		// map_start(data);
		data->color = 0xff000d;
		pov[X] = data->player.pov[X];
		pov[Y] = 0;
		i = -1;
		while (++i < FOV)
			draw_line(data, pov[X] - (RADIANT * FOV / 2) + (RADIANT * i));
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[SCREEN], 0, 0);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

// int	game_loop(t_data *data)
// {
// 	int			i;
// 	int			colors[3] = {0xFF, 0XFF, 0XFF};

// 	if (elapsed_time(data->start) > FRAME_TIME)
// 	{
// 		i = 0;
// 		mlx_clear_window(data->mlx_connection, data->mlx_window);
// 		data->screen = mlx_get_data_addr(data->textures[PLAYER], &data->bpp, &data->size_line, &data->endian);
// 		while (i != data->size_line * HIMG)
// 		{
// 			put_pixel(data, i, 0, colors[i % 3]);
// 			++i;
// 		}
// 		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[PLAYER], 0, 0);
// 		gettimeofday(&data->start, NULL);
// 	}
// 	return (0);
// }

void put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0)
		return;
	index = y * data->size_line + x * data->bpp / 8;
	data->screen[index] = color & 0xFF;
	data->screen[index + 1] = (color >> 8) & 0xFF;
	data->screen[index + 2] = (color >> 16) & 0xFF;
}

void	clear_window(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HSCREEN)
	{
		x = -1;
		while (++x < WSCREEN)
		{
			put_pixel(data, x, y, 0x000000);
		}
	}
}

void	put_image_to_image(t_data *data, int which, int y, int x)
{
	char	*txtr_data;
	int		stuff[3];
	int		color;
	int		i;
	int		j;

	txtr_data = mlx_get_data_addr(data->textures[which], &stuff[0], &stuff[1], &stuff[2]);
	if (!txtr_data)
		return ;
	i = 0;
	while (i != HIMG)
	{
		j = 0;
		while (j != WIMG)
		{
			color = txtr_data[y * stuff[1] + x * stuff[0] / 8];
			color = txtr_data[(y * stuff[1] + x * stuff[0] / 8) >> 8];
			color = txtr_data[(y * stuff[1] + x * stuff[0] / 8) >> 16];
			put_pixel(data, x + j, y + i, color);
			++j;
		}
		i++;
	}
}
