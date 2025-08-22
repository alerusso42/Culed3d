/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:01:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 17:29:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

int	which_p(t_data *data)
{
	double	pov;
	int		i;

	pov = fabs(data->player.pov[X]);
	if (pov > ANGLE_360 - ANGLE_1 > 0 || pov < ANGLE_1)
	{
		return (M_PLAYER_0);
	}
	i = 1;
	while (i < 18)
	{
		if (pov < ANGLE_20 * i)
			return (M_PLAYER_0 + i);
		++i;
	}
	return (M_PLAYER_340);
}
