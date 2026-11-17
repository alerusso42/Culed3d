/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:39:28 by lparolis          #+#    #+#             */
/*   Updated: 2026/11/17 12:14:27 by alerusso42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*
	FUNCTION NAME			DESCRIPTION
_________________________________________________________
	Parsing:				get and validate map;
	lets_start_the_party:	initialize mlx/texture data;
	mlx_hooks:				initialize keyboard;
	map_start:				prints map for the first time;
	game_loop:				the game main loop;
	spread_democracy:		free everything and exit.
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	data = (t_data){0};
	set_txtr_null(&data);
	parsing(&data, argc, argv);
	lets_start_the_party(&data);
	mlx_hook(data.win, 17, 1, (void *)ft_cross_close, &data);
	mlx_hook(data.win, 2, 1L << 0, (void *)commands_press, &data);
	mlx_hook(data.win, 3, 1L << 1, (void *)commands_release, &data);
	mlx_mouse_hook(data.win, (void *)mouse_hook, &data);
	gettimeofday(&data.start, NULL);
	play_audio(SFX_OP, &data);
	mlx_loop_hook(data.mlx, (void *)game_loop, &data);
	mlx_loop(data.mlx);
	spread_democracy(&data);
	return (0);
}
