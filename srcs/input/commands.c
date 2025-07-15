/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:49:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/15 14:41:32 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_cross_close(t_data *data)
{
	spread_democracy(data);
	exit(0);
}

int	commands(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_cross_close(data);
	else if (keycode == XK_w || keycode == XK_s || \
			keycode == XK_a || keycode == XK_d)
		move(data, &data->player, keycode);
	else if (keycode == XK_Left || keycode == XK_Right)
		rotate(data, &data->player, keycode);
	return (0);
}
