/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:36:20 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/25 09:12:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int		game_loop(t_data *data);
void	execute_input(t_data *data, const char *input);
void	frame_render(t_data *data);

void	webserv_porting(t_data *data)
{
	char	input[(1 << 14)] = {0};
	int		bytes;

	while (1)
	{
		game_loop(data);
		write(1, data->events, sizeof(data->events));
		ft_memset(&data->events[14], 0, sizeof(data->events) - 3);
		bytes = write(1, bmp_header, sizeof(bmp_header));
		bytes += write(1, data->txtr[SCREEN].xpm, data->txtr[SCREEN].total_size);
		//fd_printf(2, "Cub3D output len: %d\n", sizeof(bmp_header) + data->txtr[SCREEN].total_size);
		bytes = read(0, input, sizeof(input) - 1);
		if (bytes == -1)
			error(data, E_INPUT, NULL);
		input[bytes] = 0;
		execute_input(data, input);
	}
}

/*
	1)	to avoid full CPU speed, we set a time that needs to pass between 
		frames: FRAME_TIME (1 second / FPS).
		if it is not passed, the entire frame is skipped.
	2)	we check inputs and move/rotate player if needed;
	3)	we render the current frame on screen.
*/
int	game_loop(t_data *data)
{
	if (data->menu)
		main_menu(data);
	else if (data->battle || data->result == RESULT_DRAW)
		battle(data);
	else
	{
		move_player(data);
		mouse_input(data);
		frame_render(data);
	}
	return (0);
}

/*
	reset_renderer:	set the list of entity to render to zero.
	backgrounder:	put the background on the screen. It deletes last render.
	line:			cast a single ray, and render on the screen the result.
	render_entity:	during the raycasting phase, we save in a list the
					renderer we have seen. In render_entity, we draw them.
					
*/
void	frame_render(t_data *data)
{
	double	pov[2];
	double	angle;
	int		i;

	reset_renderer(data);
	backgrounder(data);
	data->column = 0;
	pov[X] = data->player.pov[X] - (RADIANT * (FOV / 2));
	pov[Y] = 0;
	i = WSCREEN;
	while (--i >= 0)
	{
		angle = ((RADIANT * i) / WSCREEN) * (FOV);
		line(data, &data->player, pov[X] + angle, '1');
		++data->column;
	}
	render_entity(data);
	update_all_animations(data);
	render_arms(data, &data->player);
	render_cross(data);
	map_start(data, 0, 0);
}
