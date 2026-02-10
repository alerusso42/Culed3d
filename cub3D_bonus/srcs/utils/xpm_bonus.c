/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:07:11 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/10 17:04:59 by alerusso         ###   ########.fr       */
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
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->size[Y] = ft_atoi(&g_textures[name][i]);
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->colors = ft_atoi(&g_textures[name][i]);
	i += sub_strlen(&g_textures[name][i], " ", EXCLUDE) + 1;
	txtr->cpp = ft_atoi(&g_textures[name][i]);
	i += sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
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
	static int count;
	printf("xpm %d\n", count++);
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
	//i += sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
	while (colors--)
	{
		i += sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
		ft_strlcpy(key, &g_textures[name][i], txtr->cpp + 1);
		i += txtr->cpp;
		i += sub_strlen(&g_textures[name][i], "c", EXCLUDE) + 2;
		switch (g_textures[name][i])
		{
			case ('#'):
				create_color_brga(&g_textures[name][++i], val);
				break ;
			case ('B'):case ('b'):
				ft_memcpy(val, ((char []){0, 0, 0, 255, 0}), 5);
				break ;
			case ('G'):case ('g'):
				ft_memcpy(val, ((char []){98, 98, 98, 255, 0}), 5);
				break ;
			case ('N'):case ('n'):
				ft_memcpy(val, "\0\0\0\0\0", 5);
				break ;
			default :
				free(key);
				//error(data, E_MLX_TEXTURE, "invalid color");
				error(data, E_MLX_TEXTURE, ft_substr(g_textures[name], i, 50));
		}
		i += sub_strlen(&g_textures[name][i], "\"", EXCLUDE) + 1;
		if (map_add(map, key, val) != 0)
			{free(key); error(data, E_MALLOC, NULL);}
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
						['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,\
						['a'] = 10, ['b'] = 11,\
						['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15,};

	j = 2;
	for (int i = 0; i != 3; i++)
	{
		val[j] = 0;
		val[j] += ((hex[(int)rgba[i]]) << 4);
		val[j] += (hex[(int)rgba[i + 1]]);
		j--;
	}
	val[3] = 0;
	val[4] = 0;
}

typedef struct s_cache
{
	char	*buf[256][256][256];
}	Cache;

inline static int	cache_get(Cache *cache, const unsigned char *key, char **val, int cpp)
{
	*val = NULL;
	switch (cpp)
	{
	case 1:
		*val = cache->buf[(int)key[0]][0][0];
		break;
	case 2:
		*val = cache->buf[(int)key[0]][(int)key[1]][0];
		break;
	case 3:
		*val = cache->buf[(int)key[0]][(int)key[1]][(int)key[2]];
		break;
	default:
		break;
	}
	return (*val == NULL);
}

inline static void	cache_set(Cache *cache, const unsigned char *key, char *val, int cpp)
{
	switch (cpp)
	{
	case 1:
		cache->buf[(int)key[0]][0][0] = val;
		break;
	case 2:
		cache->buf[(int)key[0]][(int)key[1]][0] = val;
		break;
	case 3:
		cache->buf[(int)key[0]][(int)key[1]][(int)key[2]] = val;
		break;
	default:
		break;
	}
}

static void	xpm_put_colors(t_data *data, t_txtr *txtr, t_map *map, int name)
{
	int		i;
	int		j;
	char	*val;
	char	key[64];
	static Cache	*cache;

	free(cache);
	cache = ft_calloc(1, sizeof(Cache));
	i = txtr->i;
	j = 0;
	if (ft_strncmp(&g_textures[name][i], "/* pixels */", 12) == 0)
		i += 12;
	i += 1;
	while (g_textures[name][i])
	{
		if (ft_strncmp(&g_textures[name][i], "\",\"", 3) == 0)
			i += 3;
		else if (ft_strncmp(&g_textures[name][i], "\"};", 3) == 0)
			break ;
		ft_strlcpy(key, &g_textures[name][i], txtr->cpp + 1);
		i += txtr->cpp;
		if (cache_get(cache, (unsigned char*)key, &val, txtr->cpp) != 0)
		{
			val = map_get(map, key);
			cache_set(cache, (unsigned char*)key, val, txtr->cpp);
		}
		if (!val)
			error(data, E_MLX_TEXTURE, ft_substr(g_textures[name], i, 50));
		txtr->xpm[j++] = val[0];
		txtr->xpm[j++] = val[1];
		txtr->xpm[j++] = val[2];
		txtr->xpm[j++] = val[3];
	}
}
