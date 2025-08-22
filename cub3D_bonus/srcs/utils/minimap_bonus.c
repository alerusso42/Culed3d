/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 08:45:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 16:43:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	minimap_print(t_data *data, int offset[2], int pos[2]);
static void	background(t_data *data);

int	map_start(t_data *data, int i, int j)
{
	int	x;
	int	y;

	background(data);
	y = data->player.map[Y] - ((MINIMAP / 2));
	j = 1;
	if (y < 0)
		y = 0;
	while (j < MINIMAP + 1 && y <= data->max_y)
	{
		i = 1;
		x = data->player.map[X] - ((MINIMAP / 2));
		if (x < 0)
			x = 0;
		while (i < MINIMAP + 1 && data->map[y][x] != ' ' && x <= data->max_x)
		{
			minimap_print(data, (int [2]){i, j}, (int [2]){x, y});
			++x;
			++i;
		}
		++j;
		++y;
	}
	return (0);
}

static void	background(t_data *data)
{
	int			x;
	int			y;
	static int	color;

	if (!color)
		color = rgb(data->ceiling[0] * 0.90, data->ceiling[1] * 0.90, \
data->ceiling[2] * 0.90);
	x = ((MINIMAP + 2) * 24);
	y = (MINIMAP * 24);
	while (x > 0)
	{
		y = (MINIMAP * 24);
		while (y > 0)
		{
			put_pixel(data, x, y, color);
			y--;
		}
		x--;
	}
}

static void	minimap_print(t_data *data, int offset[2], int pos[2])
{
	int	i;
	int	j;
	int	size_minimap[2];

	size_minimap[X] = WIMG_MINIMAP;
	size_minimap[Y] = HIMG_MINIMAP;
	i = offset[X] * WIMG_MINIMAP;
	j = offset[Y] * HIMG_MINIMAP;
	if (data->map[pos[Y]][pos[X]] == '1')
		put_image_resize(data, WALL, offset, size_minimap);
	else if (ft_strchr(PLAYER_CHARS, data->map[pos[Y]][pos[X]]))
	{
		put_image_resize(data, which_p(data), offset, size_minimap);
	}
	else if (data->map[pos[Y]][pos[X]] == 'D')
	{
		if (entity_type(data, pos[X], pos[Y]) == DOOR_CLOSED)
			put_image_resize(data, M_DOOR, offset, size_minimap);
	}
}
