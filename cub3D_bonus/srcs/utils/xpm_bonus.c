/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:07:11 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/10 10:51:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	xpm_get_colors(t_data *data, t_txtr *txtr, t_map *map, int name);
static void	create_color_brga(char *rgba, char *val);
static void	xpm_put_colors(t_data *data, t_txtr *txtr, t_map *map, int name);

void	parse_xpm(t_data *data, t_txtr *txtr, t_map *map, int name)
{
	int	i;

	i = 10;	
	txtr->size[X] = ft_atoi(&g_textures[name][i]) * 4;
	i = sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->size[Y] = ft_atoi(&g_textures[name][i]);
	i = sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->colors = ft_atoi(&g_textures[name][i]);
	i = sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->cpp = ft_atoi(&g_textures[name][i]);
	i = sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
	txtr->total_size = txtr->size[X] * txtr->size[Y];
	txtr->bpp = 32;
	txtr->xpm = ft_calloc((txtr->total_size + 1) * txtr->cpp, sizeof(char));
	txtr->i = i;
	if (!txtr->xpm)
		error(data, E_MALLOC, NULL);
	if (name != SCREEN)
	{
		xpm_get_colors(data, txtr, map, name);
		xpm_put_colors(data, txtr, map, name);
	}
}

static void	xpm_get_colors(t_data *data, t_txtr *txtr, t_map *map, int name)
{
	char	*key;
	char	val[5];
	int		colors;
	int		i;

	key = ft_calloc(txtr->cpp + 1, sizeof(char));
	if (!key)
		error(data, E_MALLOC, NULL);
	colors = txtr->colors;
	i = txtr->i;
	i = sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
	while (colors--)
	{
		i = sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
		ft_strlcpy(key, &g_textures[name][i], txtr->cpp + 1);
		i += txtr->cpp + 3;
		switch (g_textures[name][i])
		{
			case ('#'):
				create_color_brga(&g_textures[name][++i], val);
				break ;
			case ('B'):
				ft_memcpy(val, ((char []){0, 0, 0, 255, 0}), 5);
			case ('N'):
				ft_memcpy(val, "\0\0\0\0\0", 5);
				break ;
			default :
				free(key);
				error(data, E_MLX_TEXTURE, "invalid color");
		}
		i = sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
		if (map_add(map, key, val) != 0)
			free(key); error(data, E_MALLOC, NULL);
	}
	free(key);
	txtr->i = i + 1;
}

static void	create_color_brga(char *rgba, char *val)
{
	int			j;
	static char	hex[] = {['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3,\
						['4'] = 4, ['5'] = 5, ['6'] = 6, ['7'] = 7,\
						['8'] = 8, ['9'] = 9, ['A'] = 10, ['B'] = 11,\
						['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,};

	j = 2;
	for (int i = 0; i != 3; i++)
	{
		val[j] += (hex[rgba[i]] << 4);
		val[j] += (hex[rgba[i + 1]]);
		j--;
	}
	val[3] = 0;
	val[4] = 0;
}

static void	xpm_put_colors(t_data *data, t_txtr *txtr, t_map *map, int name)
{
	int		i;
	int		j;
	char	*val;
	char	key[64];

	i = txtr->i;
	j = 0;
	if (ft_strncmp(g_textures[name][i], "/* pixels */", 12) != 0)
		error(data, E_MLX_TEXTURE, "no /* pixels */ found");
	while (g_textures[name][i])
	{
		ft_strlcpy(key, &g_textures[name][i], txtr->cpp + 1);
		i += txtr->cpp;
		val = map_get(map, key);
		if (!val)
			error(data, E_MLX_TEXTURE, "invalid char in xpm");
		txtr->xpm[j++] = val[0];
		txtr->xpm[j++] = val[1];
		txtr->xpm[j++] = val[2];
		txtr->xpm[j++] = val[3];
	}
}
