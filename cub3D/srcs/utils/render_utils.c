/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:44:14 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 12:50:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_start(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
				put_image_to_image(data, WALL, y * HIMG, x * WIMG);
		}
	}
	return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0 || !color)
		return ;
	index = y * data->size_line + (x * (data->bpp / 8));
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
*/
void	put_image_to_image(t_data *data, int which, int y, int x)
{
	char	*txtr_data;
	int		stuff[3];
	int		color;
	int		index;
	int		x_y[2];

	txtr_data = mlx_get_data_addr(data->textures[which], \
&stuff[0], &stuff[1], &stuff[2]);
	if (!txtr_data)
		return ;
	x_y[X] = 0;
	while (x_y[X] != HIMG)
	{
		x_y[Y] = 0;
		while (x_y[Y] != WIMG)
		{
			index = x_y[X] * stuff[1] + x_y[Y] * (stuff[0] / 8);
			color = txtr_data[index];
			color = color | (txtr_data[index + 1] << 8);
			color = color | (txtr_data[index + 2] << 16);
			put_pixel(data, x_y[Y] + x_y[Y], x_y[X] + x_y[X], color);
			++x_y[Y];
		}
		x_y[X]++;
	}
}

void	backgrounder(t_data *data)
{
	int	ceiling;
	int	floor;
	int	i;
	int	j;

	ceiling = (data->ceiling_rgb[0] << 16) | \
(data->ceiling_rgb[1] << 8) | \
data->ceiling_rgb[2];
	floor = (data->floor_rgb[0] << 16) | \
(data->floor_rgb[1] << 8) | \
data->floor_rgb[2];
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
