/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/19 08:49:57 by alerusso         ###   ########.fr       */
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

static void	render_one(t_data *data, t_entity *entity);

void	render_entity(t_data *data)
{
	int	i;

	i = 0;
	while (data->doors[i].type != ENTITY_END)
	{
		if (data->doors[i].render == true)
			render_one(data, &data->doors[i]);
		++i;
	}
}

static void	render_one(t_data *data, t_entity *entity)
{
	double	x, y;

	x = data->player.screen[X] - entity->screen[X];
	y = data->player.screen[Y] - entity->screen[Y]; 
	x = fabs(x);
	y = fabs(y);
	printf("Atan: %f\n", atan2(y, x));	
}
