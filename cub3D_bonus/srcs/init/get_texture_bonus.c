/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:30:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/09 11:04:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	set_to_null(t_data *data);
static void	fill_txtr(t_data *data, t_texture *txtr, char *name, int size[2]);

/*
//REVIEW	get_texture

	data->texture is an array of texture of size TEXTURE_NUM + 1.
	we use this to get texture to print.
	
	If one texture is missing, we call error.
*/
void	get_texture(t_data *data)
{
	int		size[2];
	int		i;

	size[X] = WSCREEN;
	size[Y] = HSCREEN;
	set_to_null(data);
	fill_txtr(data, &data->txtr[SCREEN], SCREEN_TXTR, size);
	size[X] = WIMG;
	size[Y] = HIMG;
	fill_txtr(data, &data->txtr[NORTH], data->txtr_north, size);
	fill_txtr(data, &data->txtr[EAST], data->txtr_east, size);
	fill_txtr(data, &data->txtr[SOUTH], data->txtr_south, size);
	fill_txtr(data, &data->txtr[WEST], data->txtr_west, size);
	fill_txtr(data, &data->txtr[PLAYER], PLAYER_TXTR, size);
	fill_txtr(data, &data->txtr[CROSSHAIR], CROSS_TXTR, size);
	size[X] = TXTR;
	size[Y] = TXTR;
	fill_txtr(data, &data->txtr[WALL], WALL_TXTR, size);
	fill_txtr(data, &data->txtr[DOOR], DOOR_TXTR, size);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->txtr[i].ptr)
			return (fd_printf(2, "%d\n", i), error(data, E_MLX_TEXTURE, NULL));
	}
}

static void	set_to_null(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEXTURES_NUM)
		data->txtr[i] = (t_texture){0};
}

static void	fill_txtr(t_data *data, t_texture *txtr, char *name, int size[2])
{
	char	*line;
	char	*height;
	int		fd;
	int		counter;

	txtr->ptr = mlx_xpm_file_to_image(data->mlx, name, &size[X], &size[Y]);
	if (!txtr->ptr)
		return ;
	txtr->xpm = mlx_get_data_addr(txtr->ptr, &txtr->bpp, &txtr->size[X], &txtr->endian);
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
	height = line + sub_strlen(line, " ", EXCLUDE);
	height += 1;
	txtr->size[Y] = ft_atoi(height);
	// txtr->filters += FILTER_BLACK_WHITE;
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