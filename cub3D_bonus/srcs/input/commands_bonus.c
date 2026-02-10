/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/10 14:01:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}

void	execute_input(t_data *data, const char *input)
{
	while (*input)
	{
		switch (*input)
		{
			case ('w'):case ('W'):
				data->player.input ^= UP;
				break ;
			case ('d'):case ('D'):
				data->player.input ^= RIGHT;
				break ;
			case ('a'):case ('A'):
				data->player.input ^= LEFT;
				break ;
			case ('s'):case ('S'):
				data->player.input ^= DOWN;
				break ;
			case ('l'):case ('L'):
				data->player.input ^= R_LEFT;
				break ;
			case ('r'):case ('R'):
				data->player.input ^= R_RIGHT;
				break ;
			case ('z'):case ('Z'):
				data->player.speed += 3;
				break ;
			case (' '):
				interact(data);
				break ;
			case ('1'):case ('2'):case ('3'):case ('4'):case ('5'):\
			case ('6'):case ('7'):case ('8'):case ('9'):case ('0'):
				data->button = *input - '0';
				break ;
			case ('x'):case ('X'):
				ft_cross_close(data);
		}
		++input;
	}
}

/*

//	The or operator | adds a bit in a byte.
int	commands_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_cross_close(data);
	if (data->battle)
		battle_commands(data, keycode);
	if (data->menu)
		return (0);
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
		data->player.speed += 3;
	if (keycode == XK_e)
		interact(data);
	return (0);
}

//	The xor operator ^ removes a bit in a byte.
int	commands_release(int keycode, t_data *data)
{
	if (data->menu)
		return (0);
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
		data->player.speed -= 3;
	return (0);
}
*/

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x, (void)y;
	if (data->menu && button == MOUSE_LEFT)
	{
		if (data->button & PLAY)
		{
			//play_audio(SFX_GAME, data);
			data->menu = false;
			data->button = 0;
		}
		else if (data->button & EXIT)
			data->menu = -1;
	}
	if (data->menu)
		return (0);
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
