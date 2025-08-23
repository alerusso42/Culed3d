/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:07:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/23 13:32:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	parse_xpm(t_data *data, t_txtr *txtr, char *name)
{
	char	*line;
	char	*height;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (error(data, E_OPEN, name));
	line = get_next_line(fd);
	while (line && *line != '\"')
		line = ft_restr(line, get_next_line(fd));
	close(fd);
	if (!line)
		return (error(data, E_MLX_TEXTURE, name));
	height = line + sub_strlen(line, " ", EXCLUDE) + 1;
	txtr->size[X] = ft_atoi(line + 1) * (txtr->bpp / 8);
	txtr->size[Y] = ft_atoi(height);
	txtr->total_size = txtr->size[X] * txtr->size[Y];
	free(line);
	gnl_statik(fd, true);
}
