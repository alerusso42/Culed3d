/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/02 12:10:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}

int	commands(int keycode, t_data *data)
{
	//move_player(data);
	if (keycode == 65307)
	{
		ft_cross_close(data);
	}
	else if (keycode == XK_w)
		printf("Front\n");
	else if (keycode == XK_s)
		printf("Back\n");
	else if (keycode == XK_a)
		printf("Left\n");
	else if (keycode == XK_d)
		printf("Right\n");
	else if (keycode == XK_Left)
		printf("Rotate left\n");
	else if (keycode == XK_Right)
		printf("Rotate right\n");
	//if (data->map[data->player.map[X][Y]] == 'F')
	//	ft_cross_close(data);
	return (0);
}