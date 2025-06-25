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

long	elapsed_time(t_time start);
static void	update_coord(t_drawline *line_data);

int	debug_loop(t_data *data)
{
	int	x;
	int	y;

	if (elapsed_time(data->start) > FRAME_TIME)
	{
		mlx_clear_window(data->mlx_connection, data->mlx_window);
		map_start(data);
		mlx_mouse_get_pos(data->mlx_connection, data->mlx_window, &x, &y);
		printf("X:%d\tY:%d\n", x, y);
		draw_line(data, x, y);
	}
	return (0);
}

static int GAY(t_drawline *line_data, t_data *data, int x, int y);

int	draw_line(t_data *data, int x, int y)
{
	t_drawline line_data;

	line_data = (t_drawline){0};
	line_data.pixel_p[X] = (data->p_pos[X] * WIMG) + PLAYER_OFFSET;
	line_data.pixel_p[Y] = (data->p_pos[Y] * HIMG) + PLAYER_OFFSET;
	//line_data.pixel_win[X] = (data->p_pos[X] * WIMG) + PLAYER_OFFSET;
	//line_data.pixel_win[Y] = (data->p_pos[Y] * HIMG) + PLAYER_OFFSET;
	if (!data || x > data->max_x * WIMG || y > data->max_y * HIMG || \
		x < 0 || y < 0 || \
		(line_data.pixel_p[X] == x && line_data.pixel_p[Y] == y))
		{
			printf("ORA ORA ORA!");
			return (1);
		}`
	GAY(&line_data, data, x, y);
	printf("X:%f\tY:%f\n", line_data.delta_x, line_data.delta_y);
	while (line_data.int_x >= 0 && line_data.int_y >= 0 && \
			line_data.int_x < (data->max_x * WIMG) + WIMG / 2 && \
			line_data.int_y < (data->max_y * HIMG) + HIMG / 2)
	{
		mlx_pixel_put(data->mlx_connection, data->mlx_window, line_data.int_x, line_data.int_y, 0xFFFF00);
		update_coord(&line_data);
		mlx_get_data_addr()
	}
	return (0);
}

static double	proportion(double delta, double sum);

static int GAY(t_drawline *line_data, t_data *data, int x, int y)
{
	double	delta_sum;

	line_data->final_x = x;
	line_data->final_y = y;
	line_data->int_x = (data->p_pos[X] * WIMG) + (WIMG / 2);
	line_data->int_y = (data->p_pos[Y] * HIMG) + (HIMG / 2);
	line_data->curr_x = (int)(data->p_pos[X] * WIMG) + (WIMG / 2);
	line_data->curr_y = (int)(data->p_pos[Y] * HIMG) + (HIMG / 2);
	line_data->x_sign = POSITIVE;
	line_data->y_sign = POSITIVE;
	if ((data->p_pos[X] * WIMG) + WIMG / 2 > x)
		line_data->x_sign = NEGATIVE;
	if ((data->p_pos[Y] * HIMG) + HIMG / 2 > y)
		line_data->y_sign = NEGATIVE;
	line_data->next_x = line_data->int_x + line_data->x_sign;
	line_data->next_y = line_data->int_y + line_data->y_sign;
	line_data->delta_x = x - ((data->p_pos[X] * WIMG) + (WIMG / 2));
	line_data->delta_y = y - ((data->p_pos[Y] * HIMG) + (HIMG / 2));
	delta_sum = fabs(line_data->delta_x) + fabs(line_data->delta_y);
	line_data->delta_x = proportion(fabs(line_data->delta_x), delta_sum);
	line_data->delta_y = proportion(fabs(line_data->delta_y), delta_sum);
	line_data->delta_x *= line_data->x_sign;
	line_data->delta_y *= line_data->y_sign;
	return (0);
}

static void	update_coord(t_drawline *line_data)
{
	line_data->curr_x += line_data->delta_x;
	line_data->curr_y += line_data->delta_y;
	if (line_data->x_sign == POSITIVE)
	{
		if (line_data->curr_x >= (double)line_data->next_x)
		{
			line_data->int_x += line_data->x_sign;
			line_data->next_x += line_data->x_sign;
		}
	}
	else
	{
		if (line_data->curr_x <= (double)line_data->next_x)
		{
			line_data->int_x += line_data->x_sign;
			line_data->next_x += line_data->x_sign;
		}
	}
	if (line_data->y_sign == POSITIVE)
	{
		if (line_data->curr_y >= (double)line_data->next_y)
		{
			line_data->int_y += line_data->y_sign;
			line_data->next_y += line_data->y_sign;
		}
	}
	else
	{
		if (line_data->curr_y <= (double)line_data->next_y)
		{
			line_data->int_y += line_data->y_sign;
			line_data->next_y += line_data->y_sign;
		}
	}
}

//REVIEW - 	elapsed_time
/*
	Returns time passed, in microseconds, between now and start time.
	Start time is a struct timeval already set with gettimeofday.
*/
long	elapsed_time(t_time start)
{
	struct timeval	tv;
	long			diff;

	gettimeofday(&tv, NULL);
	diff = (tv.tv_sec - start.tv_sec) * 1000000
		 + (tv.tv_usec - start.tv_usec);
	return (diff);
}

static double	proportion(double delta, double sum)
{
	if (sum == 0 || delta == 0)
		return (0);
	return (delta / sum);
}
