/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:55:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 10:50:51 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static long long	get_time(t_timecode timecode);


void	ft_sleep(long long microsecond)
{
	long long	start;
	long long	current;

	start = get_time(MICROSECONDS);
	current = start;
	while (current - start < microsecond)
	{
		current = get_time(MICROSECONDS);
	}
}

static long long	get_time(t_timecode timecode)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		fd_printf(2, "gettimeofday failed \n");
	if (timecode == SECONDS)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (timecode == MILLISECONDS)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (timecode == MICROSECONDS)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		fd_printf(2, "Bad get_time call\n");
	return (123456);
}