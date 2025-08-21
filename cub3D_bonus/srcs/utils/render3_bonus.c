/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/21 15:25:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"
#define FABIO fabs



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

static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double ent_h);
static int	entity_height(t_data *data, double x, double y);

static void	render_one(t_data *data, t_entity *entity)
{
	double	ent_h;
	int		pos[2];
	t_txtr	*txtr;

	txtr = &data->txtr[DOOR];
	entity->contact_first[X] *= WIMG;
	entity->contact_first[Y] *= HIMG;
	ent_h = entity_height(data, entity->contact_first[X], \
		entity->contact_first[Y]);
	printf("H: %f\n", ent_h);
	pos[X] = entity->ray_num;
	pos[X] = WSCREEN - TXTR - pos[X];
	pos[Y] = HSCREEN / 2 + ent_h;
	put_entity(data, txtr, pos, ent_h);
}

static int	entity_height(t_data *data, double x, double y)
{
	double	ray;
	double	height;

	ray = ray_lenght(data, x, y);
	ray = safe_division((HSCREEN * 10), ray);
	height = round(ray * 2.5);
	return ((int)height);
}

// static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double ent_h)
// {
// 	int			color;
// 	int			index;
// 	int			y;
// 	int			x;
// 	int			k;

// 	y = 0;
// 	k = HSCREEN / 2 + ent_h;
// 	while (k >= txtr->size[Y] - (ent_h * 2) && y <= txtr->size[Y])
// 	{
// 		x = 0;
// 		while (x < txtr->size[X]  / 4)
// 		{
// 			index = y * txtr->size[X] + x * (txtr->bpp / 8);
// 			if (index > txtr->total_size - 1 || index < 0)
// 				return ;
// 			color = get_pixel_color(txtr, index);
// 			put_pixel(data, pos[X] + x, pos[Y] + y, color);
// 			x += txtr->scaler[X];
// 		}
// 		y += txtr->scaler[Y];
// 		k--;
// 	}
// }

static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double ent_h)
{
	int		screen_x;
	double	scaler_x;

	screen_x = 0;
	txtr->offset = 0;
	scaler_x = txtr->size[X] / TXTR;
	printf("scaler:%f\n", scaler_x);
	while (screen_x < TXTR - ent_h)
	{
		data->column = pos[X] + screen_x;
		render_column(data, txtr, ent_h);
		txtr->offset += scaler_x;
		++screen_x;
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
