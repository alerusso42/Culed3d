/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:09:12 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/12 11:05:19 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
https://www.youtube.com/watch?v=U06jlgpMtQs
*/
void	spread_democracy(t_data *data)
{
	free(data->texture_north);
	data->texture_north = NULL;
	free(data->texture_south);
	data->texture_south = NULL;
	free(data->texture_east);
	data->texture_east = NULL;
	free(data->texture_west);
	data->texture_west = NULL;
	free(data->texture_floor);
	data->texture_floor = NULL;
	free(data->texture_ceiling);
	data->texture_ceiling = NULL;
	free_matrix(data->map);
	data->map = NULL;
	return ;
}
