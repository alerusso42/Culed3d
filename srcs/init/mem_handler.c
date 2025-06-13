/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/13 16:38:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	free(data->txtr_north);
	data->txtr_north = NULL;
	free(data->txtr_south);
	data->txtr_south = NULL;
	free(data->txtr_east);
	data->txtr_east = NULL;
	free(data->txtr_west);
	data->txtr_west = NULL;
	free(data->txtr_floor);
	data->txtr_floor = NULL;
	free(data->txtr_ceiling);
	data->txtr_ceiling = NULL;
	free(data->textures);
	data->textures = NULL;
	free_matrix(data->map);
	data->map = NULL;
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	data->mlx_window = NULL;
	if (data->mlx_connection)
		free(data->mlx_connection);
	data->mlx_connection = NULL;
	free_texture(data);
	return ;
}

void	lets_start_the_party(t_data *data)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		error(data, 0, NULL);
	data->mlx_window = mlx_new_window(data->mlx_connection, 0, 0, "INSERT A NAME");
	if (!data->mlx_window)
		error(data, 0, NULL);
	data->textures = ft_calloc(TEXTURES_NUM, sizeof(void *));
	if (!data->textures)
		error(data, E_MALLOC, NULL);
}


