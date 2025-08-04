/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/02 15:43:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}

int	commands_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_cross_close(data);
	if (keycode == XK_w)
		data->player.input |= UP;
	if (keycode == XK_d)
		data->player.input |= RIGHT;
	if (keycode == XK_a)
		data->player.input |= LEFT;
	if (keycode == XK_s)
		data->player.input |= DOWN;
	if (keycode == XK_Left)
		data->player.input |= R_LEFT;
	if (keycode == XK_Right)
		data->player.input |= R_RIGHT;
	if (keycode == XK_Shift_L)
		data->player.speed = 7;
	return (0);
}

int	commands_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->player.input ^= UP;
	if (keycode == XK_d)
		data->player.input ^= RIGHT;
	if (keycode == XK_a)
		data->player.input ^= LEFT;
	if (keycode == XK_s)
		data->player.input ^= DOWN;
	if (keycode == XK_Left)
		data->player.input ^= R_LEFT;
	if (keycode == XK_Right)
		data->player.input ^= R_RIGHT;
	if (keycode == XK_Shift_L)
		data->player.speed = 5;
	return (0);
}

int	move_player(t_data *data)
{
	if (data->player.input & MOVEMENT)
		move(data, &data->player, (double [2]){0, 0});
	if (data->player.input & ROTATION)
		rotate(data, &data->player);
	return (0);
}
