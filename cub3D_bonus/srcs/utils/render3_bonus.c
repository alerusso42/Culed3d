/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:39:23 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/22 09:39:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	render_cross(t_data *data)
{
	int	pos[2];

	pos[X] = (WSCREEN / 2) - 64;
	pos[Y] = (HSCREEN / 2) + 32;
	put_image_to_image(data, CROSSHAIR, pos, (int [2]){WIMG, HIMG});
}
