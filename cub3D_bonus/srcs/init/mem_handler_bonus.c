/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/08/23 14:05:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	free_entities(t_entity *entity);

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	delete((void **)&data->renderer);
	delete((void **)&data->player.frames);
	free_entities(data->enemies);
	free_entities(data->doors);
	free_texture(data);
	free_matrix(data->map);
	free(data->doors);
	data->doors = NULL;
	data->map = NULL;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	if (data->mlx)
		free(data->mlx);
	data->mlx = NULL;
	return ;
}

void	lets_start_the_party(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error(data, 0, NULL);
	data->win = mlx_new_window(data->mlx, WSCREEN, HSCREEN, "BONUS");
	if (!data->win)
		error(data, 0, NULL);
	data->txtr = ft_calloc(TEXTURES_NUM + 1, sizeof(t_txtr));
	if (!data->txtr)
		error(data, E_MALLOC, NULL);
	get_txtr(data);
	data->renderer = ft_calloc(data->ent_num + 2, sizeof(t_entity *));
	if (!data->renderer)
		error(data, E_MALLOC, NULL);
	init_player(data);
	data->screen = mlx_get_data_addr(data->txtr[SCREEN].ptr, &data->bpp, \
&data->size_line, &data->endian);
}

/*
	free txtr data.
*/
void	free_texture(t_data *data)
{
	int	i;

	delete((void **)&data->txtr_east);
	delete((void **)&data->txtr_west);
	delete((void **)&data->txtr_north);
	delete((void **)&data->txtr_south);
	delete((void **)&data->txtr_floor);
	delete((void **)&data->txtr_ceiling);
	if (!data->txtr)
		return ;
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (data->txtr[i].ptr)
			mlx_destroy_image(data->mlx, data->txtr[i].ptr);
	}
	delete((void **)&data->txtr);
}

static void	free_entities(t_entity *entity)
{
	if (!entity)
		return ;
	while (entity->type != ENTITY_END)
	{
		delete((void **)&entity->frames);
		++entity;
	}
}
