/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/08/21 11:47:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	delete((void**)&data->line);
	free_texture(data);
	free_matrix(data->map);
	data->map = NULL;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	delete((void**)&data->mlx);
}

void	lets_start_the_party(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error(data, 0, NULL);
	data->win = mlx_new_window(data->mlx, WSCREEN, HSCREEN, \
		"GABIBBO");
	if (!data->win)
		error(data, 0, NULL);
	data->textures = ft_calloc(TEXTURES_NUM, sizeof(void *));
	if (!data->textures)
		error(data, E_MALLOC, NULL);
	get_txtr(data);
	init_player(data);
	data->screen = mlx_get_data_addr(data->textures[SCREEN], &data->bpp, \
		&data->size_line, &data->endian);
}
