/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:39:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 17:29:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static int	check_file(char *texture_name);
bool		check_colors(char *texture, int rgb[3]);

/*REVIEW
Funzione che controlla che i path passati per i file
delle texture siano davvero esistenti, nel caso 
terminiamo gnl con finish him perche' leo non sa scrivere bene i 
programmi e poi restituiamo errore sullo standard error
*/
void	check_textures(t_data *data, int fd)
{
	data->txtr_north[ft_strlen(data->txtr_north) - 1] = '\0';
	data->txtr_south[ft_strlen(data->txtr_south) - 1] = '\0';
	data->txtr_east[ft_strlen(data->txtr_east) - 1] = '\0';
	data->txtr_west[ft_strlen(data->txtr_west) - 1] = '\0';
	data->txtr_floor[ft_strlen(data->txtr_floor) - 1] = '\0';
	data->txtr_ceiling[ft_strlen(data->txtr_ceiling) - 1] = '\0';
	if (check_file(data->txtr_north) == false || \
check_file(data->txtr_south) == false || \
check_file(data->txtr_east) == false || \
check_file(data->txtr_west) == false || \
check_colors(data->txtr_floor, data->floor) == false || \
check_colors(data->txtr_ceiling, data->ceiling) == false)
	{
		finish_him(fd);
		error(data, E_TEXTURE, NULL);
	}
}

static int	check_file(char *texture_name)
{
	int	fd;

	fd = open(texture_name, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	check_colors(char *texture, int rgb[3])
{
	int				i;
	long long int	atoi_result;

	i = -1;
	while (++i != 3)
	{
		if (*texture == ',')
			++texture;
		if (!*texture)
			return (false);
		atoi_result = ft_atoi(texture);
		if (atoi_result == LLONG_MAX)
			return (false);
		if (atoi_result < 0 || atoi_result > 255)
			return (false);
		rgb[i] = (int)atoi_result;
		texture += sub_strlen(texture, ",", EXCLUDE);
	}
	return (true);
}
