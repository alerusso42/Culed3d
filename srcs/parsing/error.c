/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:10:26 by lparolis          #+#    #+#             */
/*   Updated: 2025/06/11 12:22:56 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	error(t_data *data, int err)
{
	spread_democracy(data);
	l_printf("Error\n");
	l_printf("No error set.\n");
	exit(err);
}
