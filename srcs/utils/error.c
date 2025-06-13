/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:10:26 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/13 11:29:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	three_dots(int fd, char *first, char *second);

/*REVIEW
Funzione personalizzata per la stampa piu chiara
degli errori
*/
void	error(t_data *data, int err, char *file)
{
	spread_democracy(data);
	fd_printf(2, "Error\n"RED);
	if (err == E_MALLOC)
		fd_printf(2, "Malloc_failure.\n");
	else if (err == E_OPEN)
		fd_printf(2, "Open_failure.\n");
	else if (err == E_ARGC)
		three_dots(2, "Bad_agruments", "volevo dire agrumi\n");
	else if (err == E_EXT)
		fd_printf(2, "Belin l'estensione di %s.\n", file);
	else if (err == E_TYPE)
		fd_printf(2, "Belin il type.\n");
	else if (err == E_FORMAT)
		fd_printf(2, "Bad .cub formatting.\n");
	else if (err == E_NO_MAP)
		fd_printf(2, "Mi sa manca qualcosa.\n");
	else if (err == E_TEXTURE)
		fd_printf(2, "Bro le texture.\n");
	else if (err == E_CHAR)
		fd_printf(2, "Invalid char in map.\n");
	else if (err == E_NO_PLAYER)
		fd_printf(2, "Wanna play with no hands?.\n");
	else if (err == E_MULTIPLAYER)
		three_dots(2, "This is not multiplayer", " yet😏\n");
	else if (err == E_INVALID_MAP)
		fd_printf(2, "This map looks suspicious\n");
	else if (err == E_INVALID_PATH)
		fd_printf(2, "Can't access the whole map\n");
	fd_printf(2, RST);
	exit(err);
}

static void	three_dots(int fd, char *first, char *second)
{
	fd_printf(fd, first);
	ft_sleep(1e6);
	fd_printf(fd, ".");
	ft_sleep(1e6);
	fd_printf(fd, ".");
	ft_sleep(1e6);
	fd_printf(fd, ".");
	ft_sleep(1e6);
	fd_printf(fd, second);
}
