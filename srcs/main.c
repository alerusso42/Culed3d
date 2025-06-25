/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:39:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/25 12:11:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_cross_close(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	data = (t_data){0};
	parsing(&data, argc, argv);
	lets_start_the_party(&data);
	//mlx_key_hook(data.mlx_connection, GRANDE_CAZZO, &data);
	mlx_hook(data.mlx_window, 17, 1, ft_cross_close, &data);
	// mlx_hook(data.mlx_window, 2, 1L << 0, map_start, &data);
	map_start(&data);
	mlx_loop(data.mlx_connection);
	spread_democracy(&data);
	return (0);
}

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}