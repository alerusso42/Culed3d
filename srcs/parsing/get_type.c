/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:31:35 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/11 19:43:08 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static bool	assign_type(t_data *data, char *line);
static bool	cub3d_substr(t_data *data, char *line, int type);

void	get_type(t_data *data, int fd)
{
	int		count_types;
	char	*line;

	count_types = 0;
	line = get_next_line(fd);
	while (count_types != 6 && line)
	{
		line += sub_strlen(line, " ", INCLUDE);
		if (*line == '\0')
			return (free(line), close(fd), error(data, E_TYPE, NULL));
		else if (*line == '\n')
		{
			line = ft_restr(line, get_next_line(fd));
			continue ;
		}
		if (assign_type(data, line) == false)
			return (free(line), close(fd), error(data, E_TYPE, NULL));
		++count_types;
		line = ft_restr(line, get_next_line(fd));
	}
	if (count_types != 6)
		return (free(line), close(fd), error(data, E_TYPE, NULL));
}

static bool	assign_type(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 2) == 0)
		return (cub3d_substr(data, line + 3, NO));
	else if (ft_strncmp(line, "SO ", 2 == 0))
		return (cub3d_substr(data, line + 3, SO));
	else if (ft_strncmp(line, "WE ", 2 == 0))
		return (cub3d_substr(data, line + 3, WE));
	else if (ft_strncmp(line, "EA ", 2 == 0))
		return (cub3d_substr(data, line + 3, EA));
	else if (ft_strncmp(line, "F ", 1) == 0)
		return (cub3d_substr(data, line + 2, F));
	else if (ft_strncmp(line, "C ", 1) == 0)
		return (cub3d_substr(data, line + 2, C));
	return (false);
}

static bool	cub3d_substr(t_data *data, char *line, int type)
{
	while (ft_isspace(line[0]))
		line += 1;
	if (type == NO && data->texture_north == NULL)
		data->texture_north = ft_strdup(line);
	else if (type == SO && data->texture_south == NULL)
		data->texture_south = ft_strdup(line);
	else if (type == WE && data->texture_west == NULL)
		data->texture_west = ft_strdup(line);
	else if (type == EA && data->texture_east == NULL)
		data->texture_east = ft_strdup(line);
	else if (type == F && data->texture_floor == NULL)
		data->texture_floor = ft_strdup(line);
	else if (type == C && data->texture_ceiling == NULL)
		data->texture_ceiling = ft_strdup(line);
	else
		return (false);
	return (true);
}
