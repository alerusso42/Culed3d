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
static void	txtr_list(t_data *data);
static void	txtr_list2(t_data *data);
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
	txtr_list(data);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->txtr[i].ptr)
			return (fd_printf(2, "%d\n", i), error(data, E_MLX_TEXTURE, NULL));
	}
}

/*	
//	data->txtr is an array of textures.
	the array stores everything mlx returns, and other info (like img height).

//	data->txtr_north are the names taken from the parsing of the .cub

//	size is the expected size of the img
*/

static void	txtr_list(t_data *data)
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
	txtr_list2(data);
	size[X] = 700;
	size[Y] = 300;
	fill_txtr(data, &data->txtr[ARMS1], ARMS1_TXTR, size);
	fill_txtr(data, &data->txtr[ARMS2], ARMS2_TXTR, size);
}

static void	txtr_list2(t_data *data)
{
	int	size[2];

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
	fill_txtr(data, &data->txtr[M_DOOR], MINI_DOOR_TXTR, size);
}

//	set all the txtr array to NULL
static void	set_to_null(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
		data->txtr[i] = (t_txtr){0};
}

/*
//	This function saves the info for the txtr. If something is messed up,
	the program is closed safely.

	1)	the img is parsed by mlx. The char array is stored in the txtr struct;
	2)	we read the img height reading the raw xpm file.
	3)	we save the size of the xpm char * array given by mlx, calculating
		it by taking the size of the xpm.
*/
static void	fill_txtr(t_data *data, t_txtr *txtr, char *name, int size[2])
{
	char	*line;
	char	*height;
	int		fd;
	int		counter;

	txtr->ptr = mlx_xpm_file_to_image(data->mlx, name, &size[X], &size[Y]);
	if (!txtr->ptr)
		return (error(data, E_MLX_TEXTURE, name));
	txtr->xpm = mlx_get_data_addr(txtr->ptr, &txtr->bpp, \
		&txtr->size[X], &txtr->endian);
	txtr->shade = 1;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (error(data, E_OPEN, name));
	counter = 5;
	line = NULL;
	while (--counter)
		line = ft_restr(line, get_next_line(fd));
	close(fd);
	if (!line)
		return (error(data, E_MLX_TEXTURE, name));
	height = line + sub_strlen(line, " ", EXCLUDE) + 1;
	txtr->size[Y] = ft_atoi(height);
	txtr->total_size = txtr->size[X] * txtr->size[Y];
	free(line);
}
