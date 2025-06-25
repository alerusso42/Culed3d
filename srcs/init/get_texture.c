/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/25 12:22:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	set_to_null(t_data *data);

void	get_texture(t_data *data)
{
	int		x;
	int		y;
	int		i;
	void	**p;

	x = 42;
	y = 42;
	set_to_null(data);
	p = &data->textures[NORTH];
	*p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_north, &x, &y);
	p = &data->textures[EAST];
	*p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_east, &x, &y);
	p = &data->textures[SOUTH];
	*p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_south, &x, &y);
	p = &data->textures[WEST];
	*p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_west, &x, &y);
	p = &data->textures[PLAYER];
	*p = mlx_xpm_file_to_image(data->mlx_connection, PLAYER_TXTR, &x, &y);
	p = &data->textures[DEBUG_WALL];
	*p = mlx_xpm_file_to_image(data->mlx_connection, DEBUG_WALL_TXTR, &x, &y);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->textures[i])
			error(data, E_MLX_TEXTURE, NULL);
	}
}

static void	set_to_null(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
		data->textures[i] = NULL;
}

void	free_texture(t_data *data)
{
	int	i;

	if (!data->textures)
		return ;
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (data->textures[i])
		{
			mlx_destroy_image(data->mlx_connection, data->textures[i]);
			// free(data->textures[i]);
		}
	}
}