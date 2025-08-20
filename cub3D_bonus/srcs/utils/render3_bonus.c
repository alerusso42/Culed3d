/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/20 09:15:55 by alerusso         ###   ########.fr       */
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

static void	render_one(t_data *data, t_entity *entity)
{
	double	ent_h;
	int		pos[2];
	t_txtr	*txtr;

	txtr = &data->txtr[DOOR];
	// txtr = &data->txtr[entity->frames[entity->f_curr]];
	ent_h = wall_height(data, entity->contact_first[X], \
		entity->contact_first[Y], entity->ray_angle);
	printf("x:%d\ty:%d\n", entity->contact_first[X], entity->contact_first[Y]);
	txtr->scaler[Y] = (txtr->size[Y] / ent_h) / 2;
	txtr->scaler[X] = 1;
	pos[X] = entity->ray_num;
	pos[Y] = HSCREEN / 2 + ent_h;
	put_entity(data, txtr, pos, ent_h);
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
	int	screen_x = 0;
	double	scaler_x;

	txtr->offset = 0;
	scaler_x = txtr->size[X] / TXTR; 
	while (screen_x < TXTR)
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
