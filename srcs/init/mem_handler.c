/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/07/02 15:40:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	free_texture(data);
	free_matrix(data->map);
	data->map = NULL;
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	data->mlx_window = NULL;
	if (data->mlx_connection)
		free(data->mlx_connection);
	data->mlx_connection = NULL;
	return ;
}

void	lets_start_the_party(t_data *data)
{
	data->mlx_connection = mlx_init();
	if (!data->mlx_connection)
		error(data, 0, NULL);
	data->mlx_window = mlx_new_window(data->mlx_connection, WSCREEN, HSCREEN, "GABIBBO");
	if (!data->mlx_window)
		error(data, 0, NULL);
	data->textures = ft_calloc(TEXTURES_NUM, sizeof(void *));
	if (!data->textures)
		error(data, E_MALLOC, NULL);
	get_texture(data);
	data->player.screen[X] = data->player.map[X] * WIMG;
	data->player.screen[Y] = data->player.map[Y] * HIMG;
	data->player.curr_x = data->player.screen[X];
	data->player.curr_y = data->player.screen[Y];
	if (data->player.type == 'E')
		data->player.pov[X] = RADIANT * (0 * 20);
	else if (data->player.type == 'N')
		data->player.pov[X] = RADIANT * (90 * 20);
	else if (data->player.type == 'W')
		data->player.pov[X] = RADIANT * (180 * 20);
	else if (data->player.type == 'S')
		data->player.pov[X] = RADIANT * (270 * 20);
	data->player.pov[X] = RADIANT * 225 * 20;
	data->screen = mlx_get_data_addr(data->textures[SCREEN], &data->bpp, &data->size_line, &data->endian);
}


