/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:29:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/29 09:45:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

static void	battle_result(t_data *data);
static void	put_textures(t_data *data);
static void	put_result_screen(t_data *data);

static void	main_battle(t_data *data);

void	battle(t_data *data)
{
	int	size[2];
	int	pos[2];

	fill_array(WSCREEN, HSCREEN, size);
	fill_array(0, 0, pos);
	if (DEBUG == false)
		put_image_to_image(data, BATTLE_FRAME, pos, size);
	else
		backgrounder(data);
	main_battle(data);
	mlx_put_image_to_window(data->mlx, data->win, data->txtr[SCREEN].ptr, 0, 0);
}

static void	put_textures(t_data *data)
{
	int	size[2];
	int	pos[2];
	int	philip;
	int	barbarian;

	philip = PHILIP + data->button;
	barbarian = FOE_BIT1 + data->enemy_choice;
	fill_array(200, TXTR, size);
	fill_array(300, 450, pos);
	put_image_to_image(data, philip, pos, size);
	fill_array(TXTR, TXTR, size);
	fill_array(1350, 450, pos);
	put_image_to_image(data, barbarian, pos, size);
}

static void	main_battle(t_data *data)
{
	if (!data->button || aspettanding(10, 0) == false)
		return (put_textures(data));
	if (!data->result)
		battle_result(data);
	if (aspettanding(30, 1) == false)
		return (put_textures(data));
	put_result_screen(data);
	if (aspettanding(30, 2) == false)
		return ;
	if (data->result == RESULT_WIN)
	{
		data->map[data->foe->map[Y]][data->foe->map[X]] = '0';
		data->foe = NULL;
	}
	if (data->result == RESULT_LOSS)
		ft_cross_close(data);
	data->battle = false;
	data->enemy_choice = 0;
	data->button = 0;
	data->result = 0;
	aspettanding(-1, -1);
}

static void	battle_result(t_data *data)
{
	int	barbarian;

	if (!data->enemy_choice)
		data->enemy_choice = get_rand(CHOICES) + 1;
	barbarian = data->enemy_choice;
	if (data->button == barbarian)
	{
		data->result = RESULT_DRAW;
	}
	else if ((data->button == CHOICE_ROCK && barbarian == CHOICE_PAPER) || \
(data->button == CHOICE_PAPER && barbarian == CHOICE_SCISSOR) || \
(data->button == CHOICE_SCISSOR && barbarian == CHOICE_ROCK))
	{
		data->result = RESULT_LOSS;
	}
	else
		data->result = RESULT_WIN;
}

static void	put_result_screen(t_data *data)
{
	int	size[2];
	int	pos[2];
	int	which;

	if (data->result == RESULT_DRAW)
		which = BAGUETTE;
	else if (data->result == RESULT_WIN)
		which = DOOR_CLOSE;
	else if (data->result == RESULT_LOSS)
		which = COIN;
	else
		which = MENU_FRAME;
	fill_array(0, 0, pos);
	size[X] = data->txtr[which].size[X] / (data->txtr[which].bpp / 8);
	size[Y] = data->txtr[which].size[Y];
	put_image_to_image(data, which, pos, size);
}
