/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txtr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/09 15:12:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	set_to_null(t_data *data);
static void	get_txtr2(t_data *data);
static void	fill_txtr(t_data *data, t_txtr *txtr, char *name, int size[2]);

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
	fill_txtr(data, &data->txtr[SCREEN], SCREEN_TXTR, size);
	get_txtr2(data);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->txtr[i].ptr)
			return (fd_printf(2, "%d\n", i), error(data, E_MLX_TEXTURE, NULL));
	}
}

static void	get_txtr2(t_data *data)
{
	int	size[2];

	size[X] = WIMG;
	size[Y] = HIMG;
	fill_txtr(data, &data->txtr[NORTH], data->txtr_north, size);
	fill_txtr(data, &data->txtr[EAST], data->txtr_east, size);
	fill_txtr(data, &data->txtr[SOUTH], data->txtr_south, size);
	fill_txtr(data, &data->txtr[WEST], data->txtr_west, size);
	fill_txtr(data, &data->txtr[PLAYER], PLAYER_TXTR, size);
	fill_txtr(data, &data->txtr[CROSSHAIR], CROSS_TXTR, size);
	size[X] = TXTR;
	size[Y] = 167;
	fill_txtr(data, &data->txtr[DOOR], DOOR_TXTR, size);
	size[X] = WIMG_MINIMAP;
	size[Y] = HIMG_MINIMAP;
	fill_txtr(data, &data->txtr[WALL], WALL_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_0], MINI_PLAYER_0_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_20], MINI_PLAYER_20_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_40], MINI_PLAYER_40_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_60], MINI_PLAYER_60_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_80], MINI_PLAYER_80_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_100], MINI_PLAYER_100_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_120], MINI_PLAYER_120_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_140], MINI_PLAYER_140_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_160], MINI_PLAYER_160_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_180], MINI_PLAYER_180_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_200], MINI_PLAYER_200_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_220], MINI_PLAYER_220_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_240], MINI_PLAYER_240_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_260], MINI_PLAYER_260_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_280], MINI_PLAYER_280_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_300], MINI_PLAYER_300_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_320], MINI_PLAYER_320_TXTR, size);
	fill_txtr(data, &data->txtr[M_PLAYER_340], MINI_PLAYER_340_TXTR, size);
}

static void	set_to_null(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
		data->txtr[i] = (t_txtr){0};
}

static void	fill_txtr(t_data *data, t_txtr *txtr, char *name, int size[2])
{
	char	*line;
	char	*height;
	int		fd;
	int		counter;

	txtr->ptr = mlx_xpm_file_to_image(data->mlx, name, &size[X], &size[Y]);
	if (!txtr->ptr)
		return ;
	txtr->xpm = mlx_get_data_addr(txtr->ptr, &txtr->bpp, &txtr->size[X], &txtr->endian);
	txtr->shade = 1;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	return (error(data, E_OPEN, name));
	counter = 5;
	line = NULL;
	while (--counter)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	height = line + sub_strlen(line, " ", EXCLUDE) + 1;
	txtr->size[Y] = ft_atoi(height);
	txtr->total_size = txtr->size[X] * txtr->size[Y];
	free(line);
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
	if (!data->txtr)
		return ;
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (data->txtr[i].ptr)
			mlx_destroy_image(data->mlx, data->txtr[i].ptr);
	}
}