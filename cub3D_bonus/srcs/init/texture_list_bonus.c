/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:27:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/29 10:03:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

/*	
//	data->txtr is an array of textures.
	the array stores everything mlx returns, and other info (like img height).

//	data->txtr[NORTH].path are the names taken from the parsing of the .cub

//	size is the expected size of the img
*/
void	txtr_list(t_data *data)
{
	int	size[2];

	fill_array(WIMG, HIMG, size);
	fill_txtr(data, NORTH, data->txtr[NORTH].path, size);
	fill_txtr(data, EAST, data->txtr[EAST].path, size);
	fill_txtr(data, SOUTH, data->txtr[SOUTH].path, size);
	fill_txtr(data, WEST, data->txtr[WEST].path, size);
	fill_txtr(data, PLAYER, PLAYER_TXTR, size);
	fill_txtr(data, CROSSHAIR, CROSS_TXTR, size);
	fill_array(TXTR, TXTR, size);
	fill_txtr(data, DOOR_CLOSE, DOOR_CLOSE_TXTR, size);
	fill_txtr(data, DOOR_OPEN, DOOR_OPEN_TXTR, size);
	fill_txtr(data, BAGUETTE, BAGUETTE_TXTR, size);
	fill_txtr(data, COIN, COIN_TXTR, size);
	txtr_list2(data);
	fill_array(700, 300, size);
	fill_txtr(data, ARMS1, ARMS1_TXTR, size);
	fill_txtr(data, ARMS2, ARMS2_TXTR, size);
	fill_array(300, 667, size);
	foe_txtr_list(data, size);
	fill_array(200, 300, size);
	fill_txtr(data, PHILIP, PHILIP_TXTR, size);
}

void	txtr_list2(t_data *data)
{
	int	size[2];

	fill_array(WSCREEN, HSCREEN, size);
	fill_txtr(data, SCREEN, SCREEN_TXTR, size);
	if (DEBUG == false)
		fill_txtr(data, BATTLE_FRAME, BATTLE_FRAME_TXTR, size);
	else
		fill_txtr(data, BATTLE_FRAME, SCREEN_TXTR, size);
	fill_array(HIMG_MINIMAP, WIMG_MINIMAP, size);
	fill_txtr(data, WALL, WALL_TXTR, size);
	mini_player_txtr_list(data, size);
	fill_txtr(data, M_DOOR, MINI_DOOR_TXTR, size);
	fill_txtr(data, M_COIN, MINI_COIN_TXTR, size);
	fill_txtr(data, M_FOE, MINI_FOE_TXTR, size);
	fill_array(408, 408, size);
	fill_txtr(data, M_BACKGROUND, MINI_BACKGROUND_TXTR, size);
	fill_array(500, 150, size);
	fill_txtr(data, PLAY_BUTTON, MENU_PLAY_TXTR, size);
	fill_txtr(data, EXIT_BUTTON, MENU_EXIT_TXTR, size);
	fill_array(1920, 1077, size);
	if (DEBUG == true)
		fill_txtr(data, MENU_FRAME, SCREEN_TXTR, size);
	else
		fill_txtr(data, MENU_FRAME, MENU_FRAME_TXTR, size);
}

void	mini_player_txtr_list(t_data *data, int *size)
{
	fill_txtr(data, M_PLAYER_0, MINI_PLAYER_0_TXTR, size);
	fill_txtr(data, M_PLAYER_20, MINI_PLAYER_20_TXTR, size);
	fill_txtr(data, M_PLAYER_40, MINI_PLAYER_40_TXTR, size);
	fill_txtr(data, M_PLAYER_60, MINI_PLAYER_60_TXTR, size);
	fill_txtr(data, M_PLAYER_80, MINI_PLAYER_80_TXTR, size);
	fill_txtr(data, M_PLAYER_100, MINI_PLAYER_100_TXTR, size);
	fill_txtr(data, M_PLAYER_120, MINI_PLAYER_120_TXTR, size);
	fill_txtr(data, M_PLAYER_140, MINI_PLAYER_140_TXTR, size);
	fill_txtr(data, M_PLAYER_160, MINI_PLAYER_160_TXTR, size);
	fill_txtr(data, M_PLAYER_180, MINI_PLAYER_180_TXTR, size);
	fill_txtr(data, M_PLAYER_200, MINI_PLAYER_200_TXTR, size);
	fill_txtr(data, M_PLAYER_220, MINI_PLAYER_220_TXTR, size);
	fill_txtr(data, M_PLAYER_240, MINI_PLAYER_240_TXTR, size);
	fill_txtr(data, M_PLAYER_260, MINI_PLAYER_260_TXTR, size);
	fill_txtr(data, M_PLAYER_280, MINI_PLAYER_280_TXTR, size);
	fill_txtr(data, M_PLAYER_300, MINI_PLAYER_300_TXTR, size);
	fill_txtr(data, M_PLAYER_320, MINI_PLAYER_320_TXTR, size);
	fill_txtr(data, M_PLAYER_340, MINI_PLAYER_340_TXTR, size);
}

void	foe_txtr_list(t_data *data, int *size)
{
	fill_txtr(data, FOE1, FOE1_TXTR, size);
	fill_txtr(data, FOE2, FOE2_TXTR, size);
	fill_txtr(data, FOE3, FOE3_TXTR, size);
	fill_txtr(data, FOE4, FOE4_TXTR, size);
	fill_txtr(data, FOE5, FOE5_TXTR, size);
	fill_txtr(data, FOE6, FOE6_TXTR, size);
	fill_txtr(data, FOE7, FOE7_TXTR, size);
	fill_txtr(data, FOE8, FOE8_TXTR, size);
	fill_txtr(data, FOE9, FOE9_TXTR, size);
	fill_txtr(data, FOE10, FOE10_TXTR, size);
	fill_txtr(data, FOE11, FOE11_TXTR, size);
	fill_txtr(data, FOE12, FOE12_TXTR, size);
	fill_array(300, 300, size);
	fill_txtr(data, FOE_BIT1, FOE_BIT1_TXTR, size);
	fill_txtr(data, FOE_BIT2, FOE_BIT2_TXTR, size);
	fill_txtr(data, FOE_BIT3, FOE_BIT3_TXTR, size);
	fill_txtr(data, FOE_BIT4, FOE_BIT4_TXTR, size);
}
