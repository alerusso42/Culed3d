/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txtr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/24 10:38:27 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	set_to_null(t_data *data);
static void	fill_txtr(void **p, char *filename, void *connect, int size[2]);

/*
//REVIEW	get_txtr

	data->texture is an array of texture of size TEXTURE_NUM + 1.
	we use this to get texture to print.
	
	If one texture is missing, we call error.
*/
void	get_txtr(t_data *data)
{
	int		size[2];
	int		i;

	size[X] = WSCREEN;
	size[Y] = HSCREEN;
	set_to_null(data);
	fill_txtr(&data->textures[SCREEN], SCREEN_TXTR, data->mlx, size);
	size[X] = WIMG;
	size[Y] = HIMG;
	fill_txtr(&data->textures[NORTH], data->txtr_north, data->mlx, size);
	fill_txtr(&data->textures[EAST], data->txtr_east, data->mlx, size);
	fill_txtr(&data->textures[SOUTH], data->txtr_south, data->mlx, size);
	fill_txtr(&data->textures[WEST], data->txtr_west, data->mlx, size);
	fill_txtr(&data->textures[PLAYER], PLAYER_TXTR, data->mlx, size);
	fill_txtr(&data->textures[WALL], WALL_TXTR, data->mlx, size);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->textures[i])
			return (fd_printf(2, "%d\n", i), error(data, E_MLX_TEXTURE, NULL));
	}
}

static void	set_to_null(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
		data->textures[i] = NULL;
}

static void	fill_txtr(void **p, char *filename, void *connect, int size[2])
{
	*p = mlx_xpm_file_to_image(connect, filename, &size[X], &size[Y]);
}

void	free_texture(t_data *data)
{
	int	i;

	delete((void**)&data->txtr_east);
	delete((void**)&data->txtr_west);
	delete((void**)&data->txtr_north);
	delete((void**)&data->txtr_south);
	delete((void**)&data->txtr_floor);
	delete((void**)&data->txtr_ceiling);
	if (!data->textures)
		return ;
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (data->textures[i])
			mlx_destroy_image(data->mlx, data->textures[i]);
	}
}
