/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/13 14:54:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_texture(t_data *data)
{
	int		x;
	int		y;
	int		i;
	void	*p;

	x = 42;
	y = 42;
	p = data->textures[NORTH];
	p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_north, &x, &y);
	p = data->textures[EAST];
	p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_east, &x, &y);
	p = data->textures[SOUTH];
	p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_south, &x, &y);
	p = data->textures[WEST];
	p = mlx_xpm_file_to_image(data->mlx_connection, data->txtr_south, &x, &y);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->textures[i])
			error(data, E_MLX_TEXTURE, NULL);
	}
}

void	free_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (data->textures[i])
		{
			mlx_destroy_image(data->mlx_connection, data->textures[i]);
			free(data->textures[i]);
		}
	}
}