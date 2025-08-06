/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:44:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/06 14:45:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	backgrounder(t_data *data)
{
	int	ceiling;
	int	floor;
	int	i;
	int	j;

	ceiling = (data->ceiling_rgb[0] << 16) | (data->ceiling_rgb[1] << 8) | data->ceiling_rgb[2];
	floor = (data->floor_rgb[0] << 16) | (data->floor_rgb[1] << 8) | data->floor_rgb[2];
	j = -1;
	while (++j < WSCREEN)
	{
		i = -1;
		while (++i <= HSCREEN / 2)
		{
			put_pixel(data, j, i, ceiling);
			put_pixel(data, j, i + (HSCREEN / 2), floor);
		}
	}
}
