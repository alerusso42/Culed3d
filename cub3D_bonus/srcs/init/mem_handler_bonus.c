/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/08/25 16:28:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	free_entities(t_entity *entity);
static void	init_entities(t_data *data);

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	delete((void **)&data->renderer);
	delete((void **)&data->player.frames);
	free_entities(data->enemies);
	free_entities(data->doors);
	free_entities(data->items);
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
	init_player(data);
	init_entities(data);
	data->renderer = ft_calloc(data->ent_num + 2, sizeof(t_entity *));
	if (!data->renderer)
		error(data, E_MALLOC, NULL);
	init_matrix((void **)data->renderer, data->ent_num + 2);
	data->screen = mlx_get_data_addr(data->txtr[SCREEN].ptr, &data->bpp, \
&data->size_line, &data->endian);
}

void	init_entities(t_data *data)
{
	int		door_count;
	int		enemies_count;
	int		item_count;

	door_count = 0;
	enemies_count = 0;
	item_count = 0;
	count_chars(data, &door_count, "D");
	count_chars(data, &enemies_count, "F");
	count_chars(data, &item_count, "C");
	if (door_count)
		init_entity(data, &data->doors, door_count, 'D');
	if (enemies_count)
		init_entity(data, &data->enemies, enemies_count, 'F');
	if (item_count)
		init_entity(data, &data->items, item_count, 'C');
	data->ent_num = 1 + door_count + enemies_count + item_count;
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
