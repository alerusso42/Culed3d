/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:53:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/29 16:52:31 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

// static void	render_button(t_data *data);
static bool	check_mouse(t_data *data, int left_angle[2], int size[2]);
static void	toggle_button(t_data *data, int button, bool on);
static int	the_frame();

void	main_menu(t_data *data)
{
	int	pos[2];
	int	size[2];

	if (data->menu < 0)
	{
		hai_guardato(data);
		return ;
	}
	fill_array(0, 0, pos);
	fill_array(WSCREEN, HSCREEN, size);
	if (DEBUG == false)
		put_image_to_image(data, MENU_FRAME, pos, size);
	fill_array(700, 355, pos);
	fill_array(500, 150, size);
	toggle_button(data, PLAY_BUTTON, check_mouse(data, pos, size));
	put_image_to_image(data, PLAY_BUTTON, pos, size);
	fill_array(700, 600, pos);
	toggle_button(data, EXIT_BUTTON, check_mouse(data, pos, size));
	put_image_to_image(data, EXIT_BUTTON, pos, size);
	mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
}

static bool	check_mouse(t_data *data, int left_angle[2], int size[2])
{
	int	mouse_pos[2];
	int	right_angle[2];

	fill_array(left_angle[X] + size[X], left_angle[Y] + size[Y], right_angle);
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
		bitwise_xor(&data->txtr[button].filters, (char)FILTER_BUTTON_PRESSED);
		if (button == PLAY_BUTTON)
			bitwise_xor(&data->button, PLAY);
		else
			bitwise_xor(&data->button, EXIT);
	}
}

void	hai_guardato(t_data *data)
{
	int	death_frame;
	int	pos[2];
	int	size[2];

	if (data->menu == -1)
	{
		clear_window(data);
		play_audio(SFX_HAI_GUARDATO, data);
		data->menu = -2;
	}
	fill_array(0, 0, pos);
	fill_array(1920, 1080, size);
	death_frame = the_frame();
	if (death_frame == -1)
		ft_cross_close(data);
	if (death_frame <= DEATH7)
		put_image_to_image(data, death_frame, pos, size);
	else
		clear_window(data);
	mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
}

static int	the_frame()
{
	int	death_frame;

	death_frame = DEATH1;
	if (aspettanding(10, DEATH1) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(10, DEATH2) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(10, DEATH3) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(16, DEATH4) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(24, DEATH5) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(50, DEATH6) == false)
		return (death_frame);
	death_frame += 1;
	if (aspettanding(65, DEATH7) == false)
		return (death_frame);
	if (aspettanding(1, 0) == true)
		return (-1);
	return (death_frame);
}
