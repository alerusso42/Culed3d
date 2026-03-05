/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2026/03/05 01:40:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	main(int ac, char **av);

int	ft_cross_close(t_data *data)
{
	fd_printf(2, "Cub3D: spread democracy\n");
	fd_printf(2, "Cub3D: restarting...\n");
	aspettanding(-1, -1);
	spread_democracy(data);
	return (main(0, NULL));
}

void	execute_input(t_data *data, const char *input)
{
	while (*input && *input != '%' && *input != '&')
	{
		switch (*input)
		{
			case ('w'):
				data->player.input &= (~UP);
				break ;
			case ('W'):
				data->player.input |= UP;
				break ;
			case ('d'):
				data->player.input &= (~RIGHT);
				break ;
			case ('D'):
				data->player.input |= RIGHT;
				break ;
			case ('a'):
				data->player.input &= (~LEFT);
				break ;
			case ('A'):
				data->player.input |= LEFT;
				break ;
			case ('s'):
				data->player.input &= (~DOWN);
				break ;
			case ('S'):
				data->player.input |= DOWN;
				break ;
			case ('j'):
				data->player.input &= (~R_LEFT);
				break ;
			case ('J'):
				data->player.input |= R_LEFT;
				break ;
			case ('l'):
				data->player.input &= (~R_RIGHT);
				break ;
			case ('L'):
				data->player.input |= R_RIGHT;
				break ;
			case ('k'):
				data->player.speed -= PLAYER_SPEED;
				break ;
			case ('K'):
				data->player.speed += PLAYER_SPEED;
				break ;
			case ('e'):case ('E'):
				interact(data);
				break ;
			case ('1'):case ('2'):case ('3'):case ('4'):case ('5'):\
			case ('6'):case ('7'):case ('8'):case ('9'):case ('0'):
				data->button = *input - '0';
				break ;
			case ('x'):
				break ;
			case ('X'):
				ft_cross_close(data);
		}
		++input;
	}
}

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
		fd_printf(2, "pov y not implemented.\n");
	else if (button == MOUSE_DOWN)
		fd_printf(2, "pov y not implemented.\n");
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
		interact(data);
	fd_printf(2, "button:%d\n", button);
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
