/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:41:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/10 14:41:16 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../cub3d.h"

// int	map_start(t_data *data)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (data->map[++i])
// 	{
// 		j = -1;
// 		while (data->map[i][++j])
// 		{
// 			if (data->map[i][j] == '1')
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 								data->textures[WALL], j * HIMG, i * WIMG);
// 			else if (ft_strchr("NSEW", data->map[i][j]))
// 				mlx_put_image_to_window(data->mlx, data->win, \
// 								data->textures[PLAYER], j * HIMG, i * WIMG);
// 		}
// 	}
// 	return (0);
// }

// int	game_loop(t_data *data)
// {
// 	int	x;		//line_data->curr_x = (int)line_data->curr_x;
// 	int	y;

// 	if (elapsed_time(data->start) > FRAME_TIME)
// 	{
// 		mlx_clear_window(data->mlx, data->win);
// 		map_start(data);
// 		mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
// 		// x = data->player.map[X] * WIMG;
// 		// y = (data->player.map[X] + 360) * WIMG;
// 		// mlx_mouse_move(data->mlx, data->win, x, y);
// 		// move_view(&x, &y);
// 		// printf("X:%d\tY:%d\n", x, y);
// 		draw_line(data, x, y);
// 		gettimeofday(&data->start, NULL);
// 	}
// 	return (0);
// }
