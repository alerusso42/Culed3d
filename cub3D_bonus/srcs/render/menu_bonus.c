/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:53:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/26 12:13:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

// static void	render_button(t_data *data);
static bool	check_mouse(t_data *data, int left_angle[2], int size[2]);
static void	toggle_button(t_data *data, int button, bool on);

void	main_menu(t_data *data)
{
	int	pos[2];
	int	size[2];

	fill_array(0, 0, pos);
	fill_array(WSCREEN, HSCREEN, size);
	put_image_to_image(data, MENU_FRAME, pos, size);
	fill_array(700, 355, pos);
	fill_array(500, 150, size);
	toggle_button(data, PLAY_BUTTON, check_mouse(data, pos, size));
	put_image_to_image(data, PLAY_BUTTON, pos, size);
	fill_array(700, 600, pos);
	toggle_button(data, EXIT_BUTTON, check_mouse(data, pos, size));
	put_image_to_image(data, EXIT_BUTTON, pos, size);
	clear_window(data);
}

static bool	check_mouse(t_data *data, int left_angle[2], int size[2])
{
	int	mouse_pos[2];
	int	right_angle[2];

	fill_array(left_angle[X] + size[X],  left_angle[Y] + size[Y], right_angle);
	mlx_mouse_get_pos(data->mlx, data->win, &mouse_pos[X], &mouse_pos[Y]);
	if (mouse_pos[X] < left_angle[X] || mouse_pos[X] > right_angle[X])
		return (false);
	if (mouse_pos[Y] < left_angle[Y] || mouse_pos[Y] > right_angle[Y])
		return (false);
	return (true);
}

static void	toggle_button(t_data *data, int button, bool on)
{
	if (on)
	{
		data->txtr[button].filters |= FILTER_BUTTON_PRESSED;
		if (button == PLAY_BUTTON)
			data->button |= PLAY;
		else
			data->button |= EXIT;
	}
	else
	{
		data->txtr[button].filters ^= FILTER_BUTTON_PRESSED;
		if (button == PLAY_BUTTON)
			data->button ^= PLAY;
		else
			data->button ^= EXIT;
	}
}
