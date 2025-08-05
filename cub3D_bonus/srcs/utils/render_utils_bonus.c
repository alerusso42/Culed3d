#include "../../cub3D_bonus.h"
#define MINIMAP_X 8
#define MINIMAP_Y 8

int	map_start(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = data->player.map[Y] - (MINIMAP_Y / 2);
	j = 0;
	if (y < 0)
	y = 0;
	while (j < MINIMAP_Y && y < data->max_y && y > 0) 
	{
		i = 0;
		x = data->player.map[X] - (MINIMAP_X / 2);
		if (x < 0)
			x = 0;
		while (i < MINIMAP_Y  && data->map[y][x] != ' ' && x < data->max_x)
		{
			if (data->map[y][x] == '1')
				put_image_to_image(data, WALL, j * HIMG, i * WIMG);
			if (data->map[y][x] == 'P')
				put_image_to_image(data, PLAYER, j * HIMG, i * WIMG), printf("a\n");
			// mlx_put_image_to_window(data->mlx, data->win, data->textures[SCREEN], 0, 0);
			// mlx_do_sync(data->mlx);
			l_printf("i:%d\tj:%d\n", i, j);
			l_printf("x:%d\ty:%d\n", x, y);
			++x;
			++i;
		}
		++j;
		--y;
	}
	return (0);
}
void	put_pixel(t_data *data, int x, int y, int color)
{
	int	index;

	if (x >= WSCREEN || y >= HSCREEN || x < 0 || y < 0 || !color)
		return ;
	index = y * data->size_line + (x * (data->bpp / 8));
	data->screen[index] = color & 0xFF;
	data->screen[index + 1] = (color >> 8) & 0xFF;
	data->screen[index + 2] = (color >> 16) & 0xFF;
}

/*
	Fill the screen texture stream data with black.
*/
void	clear_window(t_data *data)
{
	int	y;
	int	x;
	int	index;

	y = -1;
	while (++y < HSCREEN)
	{
		x = -1;
		while (++x < WSCREEN)
		{
			index = y * data->size_line + x * data->bpp / 8;
			data->screen[index] = 0;
			data->screen[index + 1] = 0;
			data->screen[index + 2] = 0;
		}
	}
}

/*
	Put an image to the screen texture.
*/
void	put_image_to_image(t_data *data, int which, int y, int x)
{
	char	*txtr_data;
	int		stuff[3];
	int		color;
	int		index;
	int		i;
	int		j;
	
	txtr_data = mlx_get_data_addr(data->textures[which], \
		&stuff[0], &stuff[1], &stuff[2]);
	if (!txtr_data)
		return ;
	i = 0;
	while (i != HIMG)
	{
		j = 0;
		while (j != WIMG)
		{
			index = i * stuff[1] + j * (stuff[0] / 8);
			color = txtr_data[index];
			color = color | (txtr_data[index + 1] << 8);
			color = color | (txtr_data[index + 2] << 16);
			put_pixel(data, y + j, x + i, color);
			++j;
		}
		i++;
	}
}

void	backgrounder(t_data *data)
{
	int	ceiling;
	int	floor;
	int	i;
	int	j;

	ceiling = (data->ceiling_rgb[0] << 16) | (data->ceiling_rgb[1] << 8) | data->ceiling_rgb[2];
	floor = (data->floor_rgb[0] << 16) | (data->floor_rgb[1] << 8) | data->floor_rgb[2];
	j = -1;
	while (++j < WSCREEN)
	{
		i = -1;
		while (++i <= HSCREEN / 2)
		{
			put_pixel(data, j, i, ceiling);
			put_pixel(data, j, i + (HSCREEN / 2), floor);
		}
	}
}

// i:0     j:0
// x:5     y:5
// i:1     j:0
// x:6     y:5
// i:2     j:0
// x:7     y:5
// i:3     j:0
// x:8     y:5
// i:4     j:0
// x:9     y:5
// i:5     j:0
// x:10    y:5
// i:6     j:0
// x:11    y:5
// i:7     j:0
// x:12    y:5
// i:0     j:1
// x:5     y:6
// i:1     j:1
// x:6     y:6
// i:2     j:1
// x:7     y:6
// i:3     j:1
// x:8     y:6
// i:4     j:1
// x:9     y:6
// i:5     j:1
// x:10    y:6
// i:6     j:1
// x:11    y:6
// i:7     j:1
// x:12    y:6
// i:0     j:2
// x:5     y:7
// i:1     j:2
// x:6     y:7
// i:2     j:2
// x:7     y:7
// i:3     j:2
// x:8     y:7
// i:4     j:2
// x:9     y:7
// i:5     j:2
// x:10    y:7
// i:6     j:2
// x:11    y:7
// i:7     j:2
// x:12    y:7
// i:0     j:3
// x:5     y:8
// i:1     j:3
// x:6     y:8
// i:2     j:3
// x:7     y:8
// i:3     j:3
// x:8     y:8
// i:4     j:3
// x:9     y:8
// i:5     j:3
// x:10    y:8
// i:6     j:3
// x:11    y:8
// i:7     j:3
// x:12    y:8
// i:0     j:4
// x:5     y:9
// i:1     j:4
// x:6     y:9
// i:2     j:4
// x:7     y:9
// i:3     j:4
// x:8     y:9
// i:4     j:4
// x:9     y:9
// i:5     j:4
// x:10    y:9
// i:6     j:4
// x:11    y:9
// i:7     j:4
// x:12    y:9
// i:0     j:5
// x:5     y:10
// i:1     j:5
// x:6     y:10
// i:2     j:5
// x:7     y:10
// i:3     j:5
// x:8     y:10
// i:4     j:5
// x:9     y:10
// i:5     j:5
// x:10    y:10
// i:6     j:5
// x:11    y:10
// i:7     j:5
// x:12    y:10