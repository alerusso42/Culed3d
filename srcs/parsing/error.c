/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:10:26 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/12 10:13:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*REVIEW
Funzione personalizzata per la stampa piu chiara
degli errori
*/
void	error(t_data *data, int err, char *file)
{
	spread_democracy(data);
	fd_printf(2, "Error\n");
	if (err == E_MALLOC)
		fd_printf(2, "Malloc_failure.\n");
	else if (err == E_OPEN)
		fd_printf(2, "Open_failure.\n");
	if (err == E_ARGC)
		fd_printf(2, "Bad_agrumi.\n");
	if (err == E_EXT)
		fd_printf(2, "Belin l'estensione di %s.\n", file);
	if (err == E_TYPE)
		fd_printf(2, "Belin il type.\n");
	exit(err);
}
