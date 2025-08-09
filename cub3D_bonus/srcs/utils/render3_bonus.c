/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/09 17:06:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

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
	t_txtr	*txtr;
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
