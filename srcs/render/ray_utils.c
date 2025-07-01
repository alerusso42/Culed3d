#include "../../cub3d.h"

//	Increments print coordinates, when the next integer points
//	is surpassed.
void	update_coord(t_drawline *line_data)
{
	line_data->curr_x += line_data->delta_x;
	line_data->curr_y += line_data->delta_y;
	if (line_data->x_sign == POSITIVE)
	{
		if (line_data->curr_x > (double)line_data->next_x)
		{
			line_data->int_x += line_data->x_sign;
			line_data->next_x += line_data->x_sign;
		}
	}
	else
	{
		if (line_data->curr_x < (double)line_data->next_x)
		{
			line_data->int_x += line_data->x_sign;
			line_data->next_x += line_data->x_sign;
		}
	}
	if (line_data->y_sign == POSITIVE)
	{
		if (line_data->curr_y > (double)line_data->next_y)
		{
			line_data->int_y += line_data->y_sign;
			line_data->next_y += line_data->y_sign;
		}
	}
	else
	{
		if (line_data->curr_y < (double)line_data->next_y)
		{
			line_data->int_y += line_data->y_sign;
			line_data->next_y += line_data->y_sign;
		}
	}
}

void	add_coord(int line[WIMG + 1][2], int x, int y)
{
	int	i;

	i = 0;
	while (line[i][X] != INT_MAX && i < (WIMG))
		++i;
	line[i][X] = x;
	line[i][Y] = y;
}

void	reset_coord(int line[WIMG + 1][2])
{
	int	i;

	i = -1;
	while (++i < (WIMG) + 1)
	{
		line[i][X] = INT_MAX;
		line[i][Y] = INT_MAX;
	}
}

void	print_coord(t_data *data, int line[WIMG + 1][2])
{
	int	i;
 
	(void)data;
	i = -1;
	while (line[++i][X] != INT_MAX && i < (WIMG))
	{
		put_pixel(data, line[i][X], line[i][Y], data->color);
	}
}

void	print_last_coord(t_data *data, t_drawline *line_data)
{
	int	i;
 
	i = -1;
	while (line_data->line[++i][X] != INT_MAX && i < WIMG)
	{
		if (data->map[line_data->line[i][Y] / HIMG]\
			[line_data->line[i][X] / WIMG] == '1')
				break ;
		// mlx_pixel_put(data->mlx_connection, data->mlx_window,
		// 	line_data->line[i][X], line_data->line[i][Y], 0xff000d);
		put_pixel(data, line_data->line[i][X], line_data->line[i][Y], data->color);
	}
}

// 0x53dd03