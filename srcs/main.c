/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:39:28 by lparolis          #+#    #+#             */
/*   Updated: 2025/07/15 14:46:37 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	parsing(&data, argc, argv);
	lets_start_the_party(&data);
	mlx_hook(data.win, 17, 1, ft_cross_close, &data);
	mlx_hook(data.win, 2, 1L << 0, commands, &data);
	gettimeofday(&data.start, NULL);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	spread_democracy(&data);
	return (0);
}

// i movimenti posso essere resi piu fluidi creando due hook, uno per il press e uno
// per il release, quando vengono schiacciati i tasti del movimento delle variabili booleane associate ai
// tasti vengono settate true e quando rilasciati settate a false
// Per la renderizzazione del movimento invece basta mettere nel loop del gioco delle funzioni che
// fintanto che le variabili del movimento sono settate a false allora non si muove il giocatore
// quanto settate a true il giocatore si muove