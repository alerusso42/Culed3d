/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:07:11 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/10 01:28:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"



void	parse_xpm(t_data *data, t_txtr *txtr, int name)
{
	int	i;
	int	colors;
	int	chars_per_color;
	t_map	map;

	i = 10;	
	txtr->size[X] = ft_atoi(&g_textures[name][i]) * 4;
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE);
	txtr->size[Y] = ft_atoi(&g_textures[name][i]);
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE);
	colors = ft_atoi(&g_textures[name][i]);
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE);
	chars_per_color = ft_atoi(&g_textures[name][i]);
	txtr->total_size = txtr->size[X] * txtr->size[Y];
	while (colors)
	{

	}
}
