/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:10:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 10:27:32 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	battle_commands(t_data *data, int keycode)
{
	if (keycode == XK_1)
		data->button = 1;
	else if (keycode == XK_2)
		data->button = 2;
	else if (keycode == XK_3)
		data->button = 3;
	else if (keycode == XK_4)
		data->button = 4;
}
