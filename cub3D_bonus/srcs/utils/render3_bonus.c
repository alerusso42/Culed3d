/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/19 16:28:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"
#define FABIO fabs

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
	while (data->entities[i])
	{
		render_one(data, &data->doors[i]);
		++i;
	}
}

static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double wall_h);

static void	render_one(t_data *data, t_entity *entity)
{
	double	wall_h;
	int		pos[2];
	t_txtr	*txtr;

	txtr = &data->txtr[DOOR];
	// txtr = &data->txtr[entity->frames[entity->f_curr]];
	wall_h = wall_height(data, entity->contact_first[X], \
		entity->contact_first[Y], entity->ray_angle);
	printf("x:%d\ty:%d\n", entity->contact_first[X], entity->contact_first[Y]);
	txtr->scaler[Y] = (txtr->size[Y] / wall_h) / 2;
	txtr->scaler[X] = 1;
	pos[X] = entity->ray_num;
	pos[Y] = HSCREEN / 2 + wall_h;
	put_entity(data, txtr, pos, wall_h);
}

static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double wall_h)
{
	int			color;
	int			index;
	int			y;
	int			x;
	int			k;

	y = 0;
	k = HSCREEN / 2 + wall_h;
	while (k >= txtr->size[Y] - (wall_h * 2) && y <= txtr->size[Y])
	{
		x = 0;
		while (x < txtr->size[X]  / 4)
		{
			index = y * txtr->size[X] + x * (txtr->bpp / 8);
			if (index > txtr->total_size - 1 || index < 0)
				return ;
			color = get_pixel_color(txtr, index);
			put_pixel(data, pos[X] + x, pos[Y] + y, color);
			x += txtr->scaler[X];
		}
		y += txtr->scaler[Y];
		k--;
	}
}


void	reset_entities(t_data *data)
{
	int	i;

	i = -1;
	while (data->doors && data->doors[++i].type != ENTITY_END)
	{
		data->doors[i].contact = false;
		data->doors[i].contact_first[X] = -1;
		data->doors[i].contact_first[Y] = -1;
		data->doors[i].contact_last[X] = -1;
		data->doors[i].contact_last[Y] = -1;
	}
	i = -1;
	while (data->entities && ++i != data->ent_num + 1)
	{
		data->entities[i] = NULL;
	}
}
