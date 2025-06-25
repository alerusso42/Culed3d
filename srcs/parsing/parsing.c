/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:12:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/25 10:48:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_file_extension(char *file);
static void	parse_cub(t_data *data, int fd);

/* REVIEW
1)	Controllo numero di argomenti
2)	Controllo estensione del file passato come argomento
3)	Controllo che l'argomento esista
4)	Assegnazione dei vari type identifiers e della mappa 

	Type identifiers = SO, NO, WE, EA, F, C.
*/

void	parsing(t_data *data, int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error(data, E_ARGC, NULL);
	else if (check_file_extension(argv[1]))
		error(data, E_EXT, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(data, E_OPEN, argv[1]);
	parse_cub(data, fd);
}

static int	check_file_extension(char *file)
{
	file = ft_strrchr(file, '.');
	if (file)
		if (ft_strncmp(file, ".ber", 4) == 0)
			return (true);
	return (false);
}

static void	parse_cub(t_data *data, int fd)
{
	get_type(data, fd);
	check_textures(data, fd);
	get_map(data, fd);
	parse_map(data);
	// print_matrix(data->map);
	//	rifondare_impero_romano(data);
}
