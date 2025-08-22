/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:17:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/08/22 14:36:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	is_it_valid(t_data *data, int x, int y, int flag);
static void	count_chars(t_data *data, int *p_count, int *d_count);

static void	count_chars(t_data *data, int *p_count, int *d_count)
{
	int	i;
	int	j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
		{
			if (ft_strchr(VALID_CHARS, data->map[i][j]) == NULL)
				error(data, E_CHAR, NULL);
			if (ft_strchr(PLAYER_CHARS, data->map[i][j]))
				(*p_count)++;
			if (data->map[i][j] == 'D')
			{
				(*d_count)++;
			}
		}
	}
}

// printf("char invalido(cioe che non puo camminare): [%c]", data->map[j][i]);
/* REVIEW
Controllo che non ci siano caratteri invalidi all'interno della mappa 
Controllo che il carattere del player non sia ripetuto
Controllo che la mappa sia racchiusa all'interno di un perimetro di muri
Controllo che il player non sia messo ai bordi della mappa
 */
void	check_chars(t_data *data)
{
	int		player_count;
	int		door_count;

	if (DEBUG == true)
		print_matrix(data->map);
	player_count = 0;
	door_count = 0;
	count_chars(data, &player_count, &door_count);
	init_doors(data, door_count);
	data->entities = ft_calloc(door_count + 2, sizeof(t_entity *));
	if (!data->entities)
		error(data, E_MALLOC, NULL);
	data->ent_num = door_count;
	if (player_count == 0)
		error(data, E_NO_PLAYER, NULL);
	else if (player_count > 1)
		error(data, E_MULTIPLAYER, NULL);
}

void	check_walls(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
		{
			if (ft_strchr(FFILL_CHARS, data->map[i][j]))
				is_it_valid(data, j, i, E_INVALID_MAP);
		}
	}
}

void	check_doors(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
		{
			if (data->map[i][j] == 'D')
				is_it_valid(data, j, i, E_INVALID_DOOR);
		}
	}
}

static void	is_it_valid(t_data *data, int x, int y, int flag)
{
	if (x == 0 || x == data->max_x || y == 0 || y == data->max_y)
		error(data, flag, NULL);
	if (data->map[y + 1][x] == ' ' || \
data->map[y - 1][x] == ' ' || \
data->map[y][x + 1] == ' ' || \
data->map[y][x - 1] == ' ')
		error(data, flag, NULL);
}
