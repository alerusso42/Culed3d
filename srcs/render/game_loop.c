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
		//mlx_clear_window(data->mlx_connection, data->mlx_window);         
		pov[X] = RADIANT * (225 * 20);
		pov[Y] = 0;
		i = -1;
		data->color = 0xff000d;
		while (++i < 100)
		{
			data->color = 0xff000d;
			put_pixel(data, i, i, 0xFFFFFF);
			draw_line(data, RADIANT * i, 0);
		}
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[SCREEN], 0, 0);
		gettimeofday(&data->start, NULL);
	}
	return (0);
}

// int	game_loop(t_data *data)
// {
// 	int			i;
// 	int			colors[3] = {0xFF, 0XFF, 0XFF};

// 	if (elapsed_time(data->start) > FRAME_TIME)
// 	{
// 		i = 0;
// 		mlx_clear_window(data->mlx_connection, data->mlx_window);
// 		data->screen = mlx_get_data_addr(data->textures[PLAYER], &data->bpp, &data->size_line, &data->endian);
// 		while (i != data->size_line * HIMG)
// 		{
// 			put_pixel(data, i, 0, colors[i % 3]);
// 			++i;
// 		}
// 		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->textures[PLAYER], 0, 0);
// 		gettimeofday(&data->start, NULL);
// 	}
// 	return (0);
// }

void put_pixel(t_data *data, int x, int y, int color)
{
    if(x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0)
        return;
    int index = y * data->size_line + x * data->bpp / 8;
    data->screen[index] = color & 0xFF;
    data->screen[index + 1] = (color >> 8) & 0xFF;
    data->screen[index + 2] = (color >> 16) & 0xFF;
}
