/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:17:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/12 21:01:05 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	is_it_valid(t_data *data, int i, int j);

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

	i = -1;
	player_count = 0;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i][++j])
		{
			if (ft_strchr(VALID_CHARS, data->map[i][j]) == NULL)
				error(data, E_CHAR, NULL);
			player_count += ft_strchr("NSWE", data->map[i][j]) != NULL;
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
			if (data->map[i][j] == '0' || \
				ft_strchr(CONTENT_CHARS, data->map[i][j]))
				is_it_valid(data, i, j);
		}
	}
}

static void	is_it_valid(t_data *data, int i, int j)
{
	if (i == 0 || i == data->max_y || j == 0 || j == data->max_x)
		error(data, E_INVALID_MAP, NULL);
	if (data->map[i + 1][j] == ' ' || \
		data->map[i - 1][j] == ' ' || \
		data->map[i][j + 1] == ' ' || \
		data->map[i][j - 1] == ' ')
		error(data, E_INVALID_MAP, NULL);
}
