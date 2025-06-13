/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:40:26 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/13 13:20:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		ft_putstr_fd("Memory allocation error", 2);
	return (ret);
}

/*
	KILL GNL BUFFER
*/
void	finish_him(int fd)
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