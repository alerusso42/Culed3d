/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 15:42:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	render_one(t_data *data, t_entity *entity);
static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double ent_h);
static int	entity_height(t_data *data, double x, double y);

void	render_entity(t_data *data)
{
	int	i;

	i = 0;
	while (data->renderer[i])
	{
		render_one(data, &data->doors[i]);
		++i;
	}
}

static void	render_one(t_data *data, t_entity *entity)
{
	double	ent_h;
	int		pos[2];
	t_txtr	*txtr;

	entity->contact_first[X] *= WIMG;
	entity->contact_first[Y] *= HIMG;
	txtr = texture_finder(data, entity->ray_angle, \
entity->contact_first[X], entity->contact_first[Y]);
	ent_h = entity_height(data, entity->contact_first[X], \
entity->contact_first[Y]);
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

static void	put_entity(t_data *data, t_txtr *txtr, int pos[2], double ent_h)
{
	int		screen_x;
	double	scaler_x;

	screen_x = 0;
	txtr->offset = 0;
	scaler_x = txtr->size[X] / TXTR;
	while (screen_x < TXTR - ent_h)
	{
		data->column = pos[X] + screen_x;
		render_column(data, txtr, ent_h);
		txtr->offset += scaler_x;
		++screen_x;
	}
}

void	reset_renderer(t_data *data)
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
	while (data->renderer[++i])
		data->renderer[i] = NULL;
}
