/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/08/09 15:48:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
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
	data->win = mlx_new_window(data->mlx, WSCREEN, HSCREEN, \
		"GABIBBO");
	if (!data->win)
		error(data, 0, NULL);
	data->txtr = ft_calloc(TEXTURES_NUM + 1, sizeof(t_txtr));
	if (!data->txtr)
		error(data, E_MALLOC, NULL);
	get_txtr(data);
	init_player(data);
	data->screen = mlx_get_data_addr(data->txtr[SCREEN].ptr, &data->bpp, \
		&data->size_line, &data->endian);
}
