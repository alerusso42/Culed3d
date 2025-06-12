/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:17:46 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/12 12:13:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	is_it_zero(t_data *data);

// printf("char invalido(cioe che non puo camminare): [%c]", data->map[j][i]);
/* REVIEW
Controllo che non ci siano caratteri invalidi all'interno della mappa 
Controllo che il carattere del player non sia ripetuto
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
			if (data->map[i][j] == '0')
				is_it_zero(data);
		}
	}
}

static void	is_it_zero(t_data *data)
{
	(void)data;
	return ;
}