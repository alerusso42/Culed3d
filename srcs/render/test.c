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
								data->textures[DEBUG_WALL], j * HIMG, i * WIMG);
			else if (ft_strchr("NSEW", data->map[i][j]))
				mlx_put_image_to_window(data->mlx_connection, data->mlx_window, \
								data->textures[PLAYER], j * HIMG, i * WIMG);
		}
	}
	return (0);
}
