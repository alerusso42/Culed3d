/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:17:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/13 14:22:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	is_it_valid(t_data *data, int x, int y);

// printf("char invalido(cioe che non puo camminare): [%c]", data->map[j][i]);
/* REVIEW
Controllo che non ci siano caratteri invalidi all'interno della mappa 
Controllo che il carattere del player non sia ripetuto
Controllo che la mappa sia racchiusa all'interno di un perimetro di muri
Controllo che il player non sia messo ai bordi della mappa
 */
void	check_chars(t_data *data)
{
	int		i;
	int		j;
	int		player_count;

	print_matrix(data->map);
	i = -1;
	player_count = 0;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
		{
			if (ft_strchr(VALID_CHARS, data->map[i][j]) == NULL)
				error(data, E_CHAR, NULL);
			if (ft_strchr(CONTENT_CHARS, data->map[i][j]))
				player_count++;
		}
	}
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
				is_it_valid(data, j, i);
		}
	}
}

static void	is_it_valid(t_data *data, int x, int y)
{
	if (x == 0 || x == data->max_x || y == 0 || y == data->max_y)
		error(data, E_INVALID_MAP, NULL);
	if (data->map[y + 1][x] == ' ' || \
		data->map[y - 1][x] == ' ' || \
		data->map[y][x + 1] == ' ' || \
		data->map[y][x - 1] == ' ')
		error(data, E_INVALID_MAP, NULL);
}
