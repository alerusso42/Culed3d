/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:28:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/04 10:50:57 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_bonus.h"

/*
	Returns the result of a division between doubles.
	Assures no division for 0 is made, avoiding floating point exception.
*/
double	safe_division(double delta, double sum)
{
	if (sum == 0 || delta == 0)
		return (0);
	return (delta / sum);
}

/*
	Returns the value in radiant of a grade value.
	Notice: 180 d are PI radiant.
			Therefore, dividing PI and multipling for grad gives back radiant.
*/
double	grad2rad(double grad)
{
	return (grad * (PI / 180));
}

/*
	Returns the value in grades of a radiant value.
	Notice: 180 d are PI radiant.
			Therefore, dividing PI and multipling for grad gives back radiant.
*/
double	rad2deg(double rad)
{
	return (rad / (PI / 180));
}

/*
	Round a double value.
	Used because math.h round often fails.
*/
double	round_rad(double rad)
{
	if (rad > 0 && rad < 0.0001)
		return (0);
	else if (rad > 0 && rad > 0.9999)
		return (1);
	else if (rad < 0 && rad > -0.0001)
		return (0);
	else if (rad < 0 && rad < -0.9999)
		return (-1);
	return (rad);
}

/*
//REVIEW
	pov:	represent the 
*/
void	update_delta(double pov, double *delta_x, double *delta_y)
{
	*delta_x = round_rad(cos(pov));
	*delta_y = round_rad(sin(pov)) * -1;
}
