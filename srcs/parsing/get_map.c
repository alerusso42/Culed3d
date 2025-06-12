/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:32:38 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/12 21:00:49 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	resize_map(t_data *data);

/* REVIEW
Nella parte iniziale mergiamo tutte le chiamate di gnl in una
singola stringa per poi chiamarci split con \n come carattere separatore
 */

void	get_map(t_data *data, int fd)
{
	char	*pre_split;
	char	*line;

	pre_split = NULL;
	line = get_next_line(fd);
	while (line)
	{
		pre_split = ft_rejoin(pre_split, line, true, true);
		line = get_next_line(fd);
	}
	data->map = ft_split(pre_split, '\n');
	free(pre_split);
	resize_map(data);
}

void	parse_map(t_data *data)
{
	check_chars(data);
	check_walls(data);
	check_map_access(data);
}

static void	resize_map(t_data *data)
{
	char	**resized_map;
	char	*tmp;
	size_t	max_size;
	size_t	remaining_size;
	int		i;

	i = -1;
	tmp = NULL;
	max_size = matrix_longest_line(data->map);
	resized_map = safe_malloc(sizeof(char *) * (matrix_len(data->map) + 1));
	while (data->map[++i])
	{
		remaining_size = max_size - ft_strlen(data->map[i]);
		tmp = safe_malloc(sizeof(char) * remaining_size + 1);
		tmp = (char *)ft_memset((void *)tmp, ' ', remaining_size);
		tmp[remaining_size] = '\0';
		resized_map[i] = ft_strjoin(data->map[i], tmp);
		free(tmp);
	}
	resized_map[i] = NULL;
	data->map = ft_rematrix(data->map, resized_map);
}



