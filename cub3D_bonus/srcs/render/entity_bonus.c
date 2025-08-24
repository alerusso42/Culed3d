/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/24 17:47:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void		render_one(t_data *data, t_entity *entity);
static double	entity_scaler_x(t_entity *entity, t_txtr *txtr, double h);
static void	draw_one(t_data *data, t_txtr *txtr, double scaler_x, double h);

void	render_entity(t_data *data)
{
	int	i;

	i = 0;
	while (data->renderer[i])
	{
		if (data->renderer[i]->frames)
			render_one(data, data->renderer[i]);
		++i;
	}
}

static void	render_one(t_data *data, t_entity *entity)
{
	double	scaler_x;
	t_txtr	*txtr;
	double	h;

	txtr = entity->frames[entity->f_curr];
	h = wall_height(data, entity->screen[X], entity->screen[Y], \
entity->first_ray);
	scaler_x = entity_scaler_x(entity, txtr, h);
	data->column = entity->contact_column;
	txtr->shade = h / (SHADE_INTENSITY / 2);
	if (txtr->shade > 1)
		txtr->shade = 1;
	draw_one(data, txtr, scaler_x, h);
	entity->contact_num = 0;
	entity->contact = false;
	txtr->offset = 0;
}

static void	draw_one(t_data *data, t_txtr *txtr, double scaler_x, double h)
{
	double	offset;

	offset = 0;
	while (txtr->offset < txtr->size[X])
	{
		render_column(data, txtr, h);
		++data->column;
		offset += scaler_x;
		txtr->offset = (int)offset;
		while (txtr->offset % (txtr->bpp / 8))
			--txtr->offset;
	}
}

static double		entity_scaler_x(t_entity *entity, t_txtr *txtr, double h)
{
	int		i;
	double	scaler;
	double	wide;

	wide = h / ENTITY_WIDTH;
	i = entity->contact_num;
	scaler = (WSCREEN / (double)i);
	scaler /= wide;
	scaler = scaler * (txtr->bpp / 8);
	scaler *= txtr->scaler[X];
	return (scaler);
}

void	reset_renderer(t_data *data)
{
	int	i;

	i = -1;
	while (data->renderer[++i])
		data->renderer[i] = NULL;
}
