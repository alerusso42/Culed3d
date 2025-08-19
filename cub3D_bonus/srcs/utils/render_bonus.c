/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:25:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/19 15:06:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	minimap_print(t_data *data, int offset[2], int pos[2]);
static void	background(t_data *data);

int	map_start(t_data *data, int i, int j)
{
	int	x;
	int	y;

	background(data);
	y = data->player.map[Y] - ((MINIMAP / 2));
	j = 1;
	if (y < 0)
		y = 0;
	while (j < MINIMAP + 1 && y <= data->max_y) 
	{
		i = 1;
		x = data->player.map[X] - ((MINIMAP / 2));
		if (x < 0)
			x = 0;
		while (i < MINIMAP + 1 && data->map[y][x] != ' ' && x <= data->max_x)
		{
			minimap_print(data, (int [2]){i, j}, (int [2]){x, y});
			++x;
			++i;
		}
		++j;
		++y;
	}
	return (0);
}

static void	background(t_data *data)
{
	int	x;
	int	y;
	int	color;
	
	x = ((MINIMAP + 2) * 24);
	y = (MINIMAP * 24);
	color = (200 << 16) | (120 << 8) | 170;
	while (x > 0)
	{
		y = (MINIMAP * 24);
		while (y > 0)
		{
			put_pixel(data, x, y, color);
			y--;
		}
		x--;
	}
}

static void	minimap_print(t_data *data, int offset[2], int pos[2])
{
	int	i;
	int	j;
	int	size_minimap[2];

	size_minimap[X] = WIMG_MINIMAP;
	size_minimap[Y] = HIMG_MINIMAP;
	i = offset[X] * WIMG_MINIMAP;
	j = offset[Y] * HIMG_MINIMAP;
	if (data->map[pos[Y]][pos[X]] == '1')
		put_image_resize(data, WALL, offset, size_minimap);
	else if (ft_strchr(PLAYER_CHARS, data->map[pos[Y]][pos[X]]))
	{
		put_image_resize(data, which_p(data), offset, size_minimap);
	}
	else if (data->map[pos[Y]][pos[X]] == 'D')
	{
		if (entity_type(data, pos[X], pos[Y]) == DOOR_CLOSED)
			put_image_resize(data, DOOR, offset, size_minimap);
	}
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= WSCREEN || x < 0)
		return ;
	if (y >= HSCREEN || y < 0)
		return ;
	if (!color)
		return ;
	// if (x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0 || !color)
	// 	return ;
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

