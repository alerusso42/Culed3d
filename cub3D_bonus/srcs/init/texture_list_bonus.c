/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:27:55 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/10 14:33:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

//static void	battle_txtr(t_data *data, int *size);

/*
void	txtr_list(t_data *data)
{
	int	i;

	i = 0;
	while (i != TEXTURE_NUM)
	{
		fill_txtr(data, i, (int [2]){0, 0});
		++i;
	}
}*/

/*	
//	data->txtr is an array of textures.
	the array stores everything mlx returns, and other info (like img height).

//	data->txtr[NORTH].path are the names taken from the parsing of the .cub

//	size is the expected size of the img
*/

/*
void	txtr_list(t_data *data)
{
	int	size[2];

	fill_array(WIMG, HIMG, size);
	fill_txtr(data, NORTH, size);
	fill_txtr(data, EAST, size);
	fill_txtr(data, SOUTH, size);
	fill_txtr(data, WEST, size);
	fill_txtr(data, PLAYER, size);
	fill_txtr(data, CROSSHAIR, size);
	fill_array(TXTR, TXTR, size);
	fill_txtr(data, DOOR_CLOSE, size);
	fill_txtr(data, DOOR_OPEN, size);
	fill_txtr(data, BAGUETTE, size);
	fill_txtr(data, COIN, size);
	txtr_list2(data);
	fill_array(700, 300, size);
	fill_txtr(data, ARMS1, size);
	fill_txtr(data, ARMS2, size);
	fill_array(300, 667, size);
	foe_txtr_list(data, size);
	battle_txtr(data, size);
}

void	txtr_list2(t_data *data)
{
	int	size[2];

	fill_array(WSCREEN, HSCREEN, size);
	fill_txtr(data, SCREEN, size);
	if (DEBUG == false)
		fill_txtr(data, BATTLE_FRAME, size);
	else
		fill_txtr(data, BATTLE_FRAME, size);
	fill_array(HIMG_MINIMAP, size);
	fill_txtr(data, WALL, WALL_TXTR, size);
	mini_player_txtr_list(data, size);
	fill_txtr(data, M_DOOR, size);
	fill_txtr(data, M_COIN, size);
	fill_txtr(data, M_FOE, size);
	fill_array(408, 408, size);
	fill_txtr(data, M_BACKGROUND, size);
	fill_array(500, 150, size);
	fill_txtr(data, EXIT_BUTTON, size);
	fill_txtr(data, EXIT_BUTTON, size);
	fill_array(1920, 1077, size);
	if (DEBUG == true)
		fill_txtr(data, MENU_FRAME,size);
	else
		fill_txtr(data, MENU_FRAME, size);
}

void	mini_player_txtr_list(t_data *data, int *size)
{
	fill_txtr(data, M_PLAYER_0, size);
	fill_txtr(data, M_PLAYER_20, size);
	fill_txtr(data, M_PLAYER_40, size);
	fill_txtr(data, M_PLAYER_60, size);
	fill_txtr(data, M_PLAYER_80, size);
	fill_txtr(data, M_PLAYER_100, size);
	fill_txtr(data, M_PLAYER_120, size);
	fill_txtr(data, M_PLAYER_140, size);
	fill_txtr(data, M_PLAYER_160, size);
	fill_txtr(data, M_PLAYER_180, size);
	fill_txtr(data, M_PLAYER_200, size);
	fill_txtr(data, M_PLAYER_220, size);
	fill_txtr(data, M_PLAYER_240, size);
	fill_txtr(data, M_PLAYER_260, size);
	fill_txtr(data, M_PLAYER_280, size);
	fill_txtr(data, M_PLAYER_300, size);
	fill_txtr(data, M_PLAYER_320, size);
	fill_txtr(data, M_PLAYER_340, size);
}

void	foe_txtr_list(t_data *data, int *size)
{
	fill_txtr(data, FOE1, size);
	fill_txtr(data, FOE2, size);
	fill_txtr(data, FOE3, size);
	fill_txtr(data, FOE4, size);
	fill_txtr(data, FOE5, size);
	fill_txtr(data, FOE6, size);
	fill_txtr(data, FOE7, size);
	fill_txtr(data, FOE8, size);
	fill_txtr(data, FOE9, size);
	fill_txtr(data, FOE10, size);
	fill_txtr(data, FOE11, size);
	fill_txtr(data, FOE12, size);
	fill_array(300, 300, size);
	fill_txtr(data, FOE_BIT1, size);
	fill_txtr(data, FOE_BIT2, size);
	fill_txtr(data, FOE_BIT3, size);
	fill_txtr(data, FOE_BIT4, size);
	fill_array(500, 150, size);
	fill_txtr(data, PLAY_BUTTON, size);
	fill_txtr(data, EXIT_BUTTON, size);
	fill_txtr(data, LOSS_MSG, size);
	fill_txtr(data, DRAW_MSG, size);
	fill_txtr(data, WIN_MSG, size);
}

static void	battle_txtr(t_data *data, int *size)
{
	fill_array(450, 450, size);
	fill_txtr(data, BARBARIAN_CHILL, size);
	fill_txtr(data, BARBARIAN_ROCK, size);
	fill_txtr(data, BARBARIAN_PAPER, size);
	fill_txtr(data, BARBARIAN_SCISSOR, size);
	fill_txtr(data, BARBARIAN_SCARED, size);
	fill_array(300, 450, size);
	fill_txtr(data, PHILIP_CHILL, size);
	fill_txtr(data, PHILIP_ROCK, size);
	fill_txtr(data, PHILIP_PAPER, size);
	fill_txtr(data, PHILIP_SCISSOR, size);
	fill_txtr(data, PHILIP_LOOK, size);
	fill_array(1920, 1080, size);
	fill_txtr(data, DEATH1, size);
	fill_txtr(data, DEATH2, size);
	fill_txtr(data, DEATH3, size);
	fill_txtr(data, DEATH4, size);
	fill_txtr(data, DEATH5, size);
	fill_txtr(data, DEATH6, size);
	fill_txtr(data, DEATH7, size);
	fill_txtr(data, ROCK, size);
	fill_txtr(data, PAPER, size);
	fill_txtr(data, SCISSORS, size);
}*/

char *g_textures[TEXTURES_NUM] = {
	[SCREEN] = SCREEN_data,
	[NORTH] = NORTH_data,
	[EAST] = EAST_data,
	[SOUTH] = SOUTH_data,
	[WEST] = WEST_data,
	[CROSSHAIR] = CROSSHAIR_data,
	[PLAYER] = BARBARIAN_CHILL_data,
	[WALL] = DEBUG_WALL_data,
	[DOOR_OPEN] = DOOR_OPEN_data,
	[DOOR_CLOSE] = DOOR_CLOSED_data,
	[M_BACKGROUND] = MINI_BACKGROUND_data,
	[M_PLAYER_0] = MINI_PLAYER_0_data,
	[M_PLAYER_20] = MINI_PLAYER_20_data,
	[M_PLAYER_40] = MINI_PLAYER_40_data,
	[M_PLAYER_60] = MINI_PLAYER_60_data,
	[M_PLAYER_80] = MINI_PLAYER_80_data,
	[M_PLAYER_100] = MINI_PLAYER_100_data,
	[M_PLAYER_120] = MINI_PLAYER_120_data,
	[M_PLAYER_140] = MINI_PLAYER_140_data,
	[M_PLAYER_160] = MINI_PLAYER_160_data,
	[M_PLAYER_180] = MINI_PLAYER_180_data,
	[M_PLAYER_200] = MINI_PLAYER_200_data,
	[M_PLAYER_220] = MINI_PLAYER_220_data,
	[M_PLAYER_240] = MINI_PLAYER_240_data,
	[M_PLAYER_260] = MINI_PLAYER_260_data,
	[M_PLAYER_280] = MINI_PLAYER_280_data,
	[M_PLAYER_300] = MINI_PLAYER_300_data,
	[M_PLAYER_320] = MINI_PLAYER_320_data,
	[M_PLAYER_340] = MINI_PLAYER_340_data,
	[M_DOOR] = MINI_DOOR_data,
	[M_COIN] = MINI_COIN_data,
	[M_FOE] = MINI_FOE_data,
	[FOE1] = FOE_1_data,
	[FOE2] = FOE_2_data,
	[FOE3] = FOE_3_data,
	[FOE4] = FOE_4_data,
	[FOE5] = FOE_5_data,
	[FOE6] = FOE_6_data,
	[FOE7] = FOE_7_data,
	[FOE8] = FOE_8_data,
	[FOE9] = FOE_9_data,
	[FOE10] = FOE_10_data,
	[FOE11] = FOE_11_data,
	[FOE12] = FOE_12_data,
	[FOE_BIT1] = DEATH1_data,
	[FOE_BIT2] = DEATH2_data,
	[FOE_BIT3] = DEATH3_data,
	[FOE_BIT4] = DEATH4_data,
	[BARBARIAN_CHILL] = BARBARIAN_CHILL_data,
	[BARBARIAN_ROCK] = BARBARIAN_ROCK_data,
	[BARBARIAN_PAPER] = BARBARIAN_PAPER_data,
	[BARBARIAN_SCISSOR] = BARBARIAN_SCISSORS_data,
	[BARBARIAN_SCARED] = BARBARIAN_SCARED_data,
	[PHILIP_CHILL] = PHILIP_CHILL_data,
	[PHILIP_ROCK] = PHILIP_ROCK_data,
	[PHILIP_PAPER] = PHILIP_PAPER_data,
	[PHILIP_SCISSOR] = PHILIP_SCISSORS_data,
	[PHILIP_LOOK] = PHILIP_LOOK_data,
	[COIN] = COIN_data,
	[ARMS1] = BARBARIAN_1LEFT_data,
	[ARMS2] = BARBARIAN_1RIGHT_data,
	[BAGUETTE] = BAGUETTE_data,
	[MENU_FRAME] = MENU_IL_DESTINO_data,
	[PLAY_BUTTON] = PLAY_BUTTON_data,
	[EXIT_BUTTON] = EXIT_BUTTON_data,
	[BATTLE_FRAME] = HOLY_FIGHT_SCENARIO_data,
	[LOSS_MSG] = LOSS_MSG_data,
	[WIN_MSG] = WIN_MSG_data,
	[DRAW_MSG] = DRAW_MSG_data,
	[DEATH1] = DEATH1_data,
	[DEATH2] = DEATH2_data,
	[DEATH3] = DEATH3_data,
	[DEATH4] = DEATH4_data,
	[DEATH5] = DEATH5_data,
	[DEATH6] = DEATH6_data,
	[DEATH7] = DEATH7_data,
	[ROCK] = ROCK_data,
	[PAPER] = PAPER_data,
	[SCISSORS] = SCISSORS_data
};
