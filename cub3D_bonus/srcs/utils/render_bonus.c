/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 08:25:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/20 15:16:04 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	pix(t_data *data)
{
		mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
		mlx_do_sync(data->mlx);
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
	data->screen[index] = color & 255;
	data->screen[index] &= 255;
	data->screen[index + 1] = (color >> 8) & 255;
	data->screen[index + 1] &= 255;
	data->screen[index + 2] = (color >> 16) & 255;
	data->screen[index + 2] &= 255;
}

int	get_pixel_color(t_txtr *txtr, int i)
{
	int	r;
	int	g;
	int	b;
	int	rgb;

	if (i > txtr->total_size)
		return (0);
	r = (txtr->xpm[i] & 255) * txtr->shade;
	g = ((txtr->xpm[i + 1] & 255) * txtr->shade);
	b = ((txtr->xpm[i + 2] & 255) * txtr->shade);
	if (txtr->filters & FILTER_ON)
		txtr_filters(txtr, &r, &g, &b);
	rgb = r | (g << 8) | (b << 16);
	return (rgb);
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

/*
	Put an image to the screen texture.
*/
void	put_image_to_image(t_data *data, int which, int pos[2], int size[2])
{
	t_txtr		*txtr;
	int			color;
	int			index;
	int			y;
	int			x;

	txtr = &data->txtr[which];
	if (!txtr->ptr)
		return ;
	y = 0;
	while (y != size[Y])
	{
		x = 0;
		while (x != size[X])
		{
			index = y * txtr->size[X] + x * (txtr->bpp / 8);
			if (index > txtr->total_size - 1)
				return ;
			color = txtr->xpm[index] & 0xFF;
			color = color | ((txtr->xpm[index + 1] & 0xFF) << 8);
			color = color | ((txtr->xpm[index + 2] & 0xFF) << 16);
			put_pixel(data, pos[X] + x, pos[Y] + y, color);
			++x;
		}
		y++;
	}
}

