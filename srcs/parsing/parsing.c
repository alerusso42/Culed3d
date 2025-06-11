/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:12:16 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/11 19:25:28 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_file_extension(char *file);
static void	parse_cub(t_data *data, int fd);

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
	//get_map(data, fd);
}
