/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 14:31:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}

//	The or operator | adds a bit in a byte.
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
	if (keycode == XK_e)
		interact(data);
	return (0);
}

//	The xor operator ^ removes a bit in a byte.
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

int	mouse_hook(int button, int x, int y, void *data)
{
	(void)x, (void)y;
	if (button == MOUSE_UP)
		printf("pov y not implemented.\n");
	else if (button == MOUSE_DOWN)
		printf("pov y not implemented.\n");
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
		interact(data);
	printf("button:%d\n", button);
	return (0);
}

//	The and operator & checks if a bit is in a byte.
//	MOVEMENT is a bitmask of [00001111].
//	ROTATION is a bitmask of [11110000].
//	last four bytes represents left, right, up, down movement.
//	first four bytes represents the same, but for rotation.
int	move_player(t_data *data)
{
	if (data->player.input & MOVEMENT)
		move(data, &data->player, (double [2]){0, 0});
	if (data->player.input & ROTATION)
		rotate(data, &data->player);
	return (0);
}
