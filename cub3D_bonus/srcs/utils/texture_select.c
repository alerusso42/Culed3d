/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:01:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/09 15:19:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

// int	which_p(t_data *data)
// {
// 	double	pov;

// 	pov = fabs(data->player.pov[X]);
// 	if (pov > ANGLE_360 - ANGLE_11 > 0 || pov < ANGLE_0 + ANGLE_11)
// 		return (M_PLAYER_0);
// 	else if (pov < ANGLE_90)
// 		return (M_PLAYER_45);
// 	else if (pov > ANGLE_90 - ANGLE_11 > 0 && pov < ANGLE_90 + ANGLE_11)
// 		return (M_PLAYER_90);
// 	else if (pov < ANGLE_180)
// 		return (M_PLAYER_135);
// 	else if (pov > ANGLE_180 - ANGLE_11 > 0 && pov < ANGLE_180 + ANGLE_11)
// 		return (M_PLAYER_180);
// 	else if (pov < ANGLE_270)
// 		return (M_PLAYER_225);
// 	else if (pov > ANGLE_270 - ANGLE_11 > 0 && pov < ANGLE_270 + ANGLE_11)
// 		return (M_PLAYER_270);
// 	else
// 		return (M_PLAYER_315);
// }

int	which_p(t_data *data)
{
	double	pov;
	int		i;

	pov = fabs(data->player.pov[X]);
	if (pov > ANGLE_360 - ANGLE_1 > 0 || pov < ANGLE_1)
	{
		printf("entrato: %f\n", pov);
		return (M_PLAYER_0);
	}
	// else if (pov > ANGLE_90 - ANGLE_1 > 0 && pov < ANGLE_90 + ANGLE_1)
	// 	return (M_PLAYER_90);
	// else if (pov > ANGLE_180 - ANGLE_1 > 0 && pov < ANGLE_180 + ANGLE_1)
	// 	return (M_PLAYER_180);
	// else if (pov > ANGLE_270 - ANGLE_1 > 0 && pov < ANGLE_270 + ANGLE_1)
	// 	return (M_PLAYER_270);
	i = 1;
	printf("angle:%f\n", pov);
	while (i < 18)
	{
		if (pov < ANGLE_20 * i)
			return (M_PLAYER_0 + i);
		++i;
	}
	return (M_PLAYER_340);
}
