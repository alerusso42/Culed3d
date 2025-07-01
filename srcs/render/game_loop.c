#include "../../cub3d.h"

int	map_start(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
								data->textures[WALL], j * HIMG, i * WIMG);
			else if (ft_strchr("NSEW", data->map[i][j]))
				mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
								data->textures[PLAYER], j * HIMG, i * WIMG);
		}
	}
	return (0);
}

int	game_loop(t_data *data)
{
	double	pov[2];
	int i;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		mlx_clear_window(data->mlx_connection, data->mlx_window);
		map_start(data);
		pov[X] = RADIANT * (225 * 20);
		pov[Y] = 0;
		i = -1;
		data->color = 0xff000d;
		while (++i < 1000)
		{
			data->color = 0xff000d;
			draw_line(data, RADIANT * i, 0);
		}
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

