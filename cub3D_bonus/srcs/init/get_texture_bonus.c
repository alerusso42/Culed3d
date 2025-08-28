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

/*
//REVIEW	get_txtr

	data->texture is an array of texture of size TEXTURE_NUM + 1.
	we use this to get texture to print.
	
	If one texture is missing, we call error.
*/
void	get_txtr(t_data *data)
{
	int		i;

	set_to_null(data);
	txtr_list(data);
	i = -1;
	while (++i < TEXTURES_NUM)
	{
		if (!data->txtr[i].ptr)
			return (fd_printf(2, "%d\n", i), error(data, E_MLX_TEXTURE, NULL));
	}
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
void	fill_txtr(t_data *data, int index, char *name, int size[2])
{
	t_txtr	*txtr;

	txtr = &data->txtr[index];
	txtr->ptr = mlx_xpm_file_to_image(data->mlx, name, &size[X], &size[Y]);
	if (!txtr->ptr)
		return (error(data, E_MLX_TEXTURE, name));
	txtr->xpm = mlx_get_data_addr(txtr->ptr, &txtr->bpp, \
&txtr->size[X], &txtr->endian);
	parse_xpm(data, txtr, name);
	txtr->shade = 1;
	txtr->scaler[X] = (txtr->size[X] / (txtr->bpp / 8)) / TXTR;
	txtr->scaler[Y] = txtr->size[Y] / TXTR;
	txtr->i = index;
}
