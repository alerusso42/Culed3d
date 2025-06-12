/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:39:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 10:18:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_file(char *texture_name);
static void	finish_him(int fd);

/*REVIEW
Funzione che controlla che i path passati per i file
delle texture siano davvero esistenti, nel caso 
terminiamo gnl con finish him perche' leo non sa scrivere bene i 
programmi e poi restituiamo errore sullo standard error
*/
void	check_textures(t_data *data, int fd)
{
	if (check_file(data->texture_north) == false || \
		check_file(data->texture_south) == false || \
		check_file(data->texture_east) == false || \
		check_file(data->texture_west) == false || \
		check_file(data->texture_floor) == false || \
		check_file(data->texture_ceiling) == false)
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

/*
	KILL GNL BUFFER
*/
static void	finish_him(int fd)
{
	char	*line;

	fd_printf(2, RED"FINISH HIM!.\n"RST);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_sleep(1e6);
	fd_printf(2, ".");
	ft_sleep(1e6);
	fd_printf(2, ".");
	ft_sleep(1e6);
	fd_printf(2, ".");
	fd_printf(2, RED"  FATALITY.\n"RST);
}
