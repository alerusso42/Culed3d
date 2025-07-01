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

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		mlx_clear_window(data->mlx_connection, data->mlx_window);
		map_start(data);
		//mlx_mouse_get_pos(data->mlx_connection, data->mlx_window, &x, &y);
		pov[X] = 0.25 * PI;
		pov[Y] = 0;
		// printf("X:%d\tY:%d\n", x, y);
		//move_view
		draw_line(data, pov[X], pov[Y]);
		mlx_do_sync(data->mlx_connection);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

