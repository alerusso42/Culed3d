/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:54:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 17:51:23 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	stop_audio(t_data *data)
{
	if (data->audio_play && data->audio_pid > 0)
	{
		kill(data->audio_pid, SIGTERM);
		data->audio_pid = 0;
		data->audio_play = false;
	}
}

void	play_audio(char *audio_path, t_data *data)
{
	FILE	*fd;
	char	command[256];

	stop_audio(data);
	snprintf(command, sizeof(command), "paplay %s > /dev/null 2>&1 & echo $!", audio_path);
	fd = popen(command, "r");
	if (fd)
	{
		fscanf(fd, "%d", &data->audio_pid);
		pclose(fd);
		data->audio_play = true;
	}
}
