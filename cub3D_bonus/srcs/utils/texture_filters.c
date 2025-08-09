/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_filters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 10:32:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/09 10:48:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

void	txtr_filters(t_texture *txtr, int *r, int *g, int *b)
{
	int	rgb;

	rgb = 0;
	if (txtr->filters == FILTER_BLACK_WHITE)
	{
		rgb = bigger(*r, *b, *g, INT_MIN);
		rgb += (bigger(*r, *b, *g, INT_MIN) << 8);
		rgb += (bigger(*r, *b, *g, INT_MIN) << 16); 
	}
	*r = rgb & 255;
	*g = (rgb >> 8) & 255;
	*b = (rgb >> 16) & 255;
}
