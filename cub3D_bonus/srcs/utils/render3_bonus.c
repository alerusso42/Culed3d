/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 13:35:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	render_cross(t_data *data)
{
	int	pos[2];

	pos[X] = (WSCREEN / 2) - data->txtr[CROSSHAIR].size[X] / 8;
	pos[Y] = (HSCREEN / 2) - data->txtr[CROSSHAIR].size[Y] / 2;
	put_image_to_image(data, CROSSHAIR, pos, (int [2]){WIMG, HIMG});
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

void	put_image_resize(t_data *data, int which, int pos[2], int size[2])
{
	pos[X] *= size[X];
	pos[Y] *= size[Y];
	put_image_to_image(data, which, pos, size);
}
