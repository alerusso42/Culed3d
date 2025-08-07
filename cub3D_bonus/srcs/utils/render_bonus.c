/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:25:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/07 09:15:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	minimap_print(t_data *data, int offset[2], int pos[2]);

int	map_start(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

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

static void	minimap_print(t_data *data, int offset[2], int pos[2])
{
	int	i;
	int	j;

	i = offset[X] * WIMG_MINIMAP;
	j = offset[Y] * HIMG_MINIMAP;
	if (data->map[pos[Y]][pos[X]] == '1')
		put_image_to_image(data, WALL, offset, (int [2]){WIMG_MINIMAP, HIMG_MINIMAP});
	else if (ft_strchr(PLAYER_CHARS, data->map[pos[Y]][pos[X]]))
		put_image_to_image(data, PLAYER, offset, (int [2]){WIMG_MINIMAP, HIMG_MINIMAP});
	else if (data->map[pos[Y]][pos[X]] == 'D')
	{
		if (entity_type(data, pos[X], pos[Y]) == DOOR_CLOSED)
			put_image_to_image(data, DOOR, offset, (int [2]){WIMG_MINIMAP, HIMG_MINIMAP});
		else
			put_image_to_image(data, CROSSHAIR, offset, (int [2]){WIMG_MINIMAP, HIMG_MINIMAP});
	}
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
void	put_image_to_image(t_data *data, int which, int pos[2], int size[2])
{
	t_texture	*txtr;
	int			color;
	int			index;
	int			i;
	int			j;

	txtr = &data->txtr[which];
	if (!txtr->ptr)
		return ;
	i = 0;
	pos[X] *= size[X];
	pos[Y] *= size[Y];
	while (i != size[Y])
	{
		j = 0;
		while (j != size[X])
		{
			index = i * txtr->size[X] + j * (txtr->bpp / 8);
			color = txtr->xpm[index] & 0xFF;
			color = color | ((txtr->xpm[index + 1] & 0xFF) << 8);
			color = color | ((txtr->xpm[index + 2] & 0xFF) << 16);
			put_pixel(data, pos[X] + j, pos[Y] + i, color);
			++j;
		}
		i++;
	}
}
