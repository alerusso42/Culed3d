#include "../../cub3d.h"

/* static void	quadrant(t_drawline *line_data); */
static int	GAY(t_drawline *line_data, t_data *data, int x, int y);
static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data);

int	draw_line(t_data *data, int x, int y)
{
	t_drawline	line_data;
	int			stepper;

	line_data = (t_drawline){0};
	stepper = WIMG;
	reset_coord(line_data.line);
	line_data.pixel_p[X] = (data->p_pos[X] * WIMG) + PLAYER_OFFSET;
	line_data.pixel_p[Y] = (data->p_pos[Y] * HIMG) + PLAYER_OFFSET;
	line_data.pixel_win[X] = ((data->max_x + 1) * WIMG) + PLAYER_OFFSET;
	line_data.pixel_win[Y] = ((data->max_y + 1) * HIMG) + PLAYER_OFFSET;
	if (!data || x > line_data.pixel_win[X] || y > line_data.pixel_win[Y] || \
		x < 0 || y < 0 || \
		(line_data.pixel_p[X] == x && line_data.pixel_p[Y] == y))
		return (printf("ORA ORA ORA!"));
	GAY(&line_data, data, x, y);
	// printf("X:%f\tY:%f\n", line_data.delta_x, line_data.delta_y);
	while (line_data.int_x >= 0 && line_data.int_y >= 0 && \
			line_data.int_x <= line_data.pixel_win[X] && \
			line_data.int_y <= line_data.pixel_win[Y])
	{
		if (the_wall_checker(&stepper, &line_data, data) == true)
			break ;
		//mlx_pixel_put(data->mlx_connection, data->mlx_window, 
		//				line_data.int_x, line_data.int_y, 0x1000f5);
		add_coord(line_data.line, line_data.int_x, line_data.int_y);
		update_coord(&line_data);
	}
	return (0);
}

static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data)
{
	int			x;
	int			y;

	(void)line_data;
	if (*stepper != WIMG)
	{
		(*stepper)++;
		return (false);
	}
	(*stepper) = 0;
	x = (int)(line_data->curr_x / WIMG);
	y = (int)(line_data->curr_y / HIMG);
	if (data->map[y][x] == '1')
	{
		//quadrant(line_data);
		printf("Wall at double X:%f\tY:%f\n", line_data->curr_x, line_data->curr_y);
		printf("Wall at int X:%d\tY:%d\n", x, y);
		print_last_coord(data, line_data);
		return (true);
	}
	print_coord(data, line_data->line);
	reset_coord(line_data->line);
	return (false);
}

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
	line_data->delta_x = safe_division(fabs(line_data->delta_x), delta_sum);
	line_data->delta_y = safe_division(fabs(line_data->delta_y), delta_sum);
	line_data->delta_x *= line_data->x_sign;
	line_data->delta_y *= line_data->y_sign;
	return (0);
}

/* static void	quadrant(t_drawline *line_data)
{
	//QUADRANTE 1
	if (line_data->delta_y < -0.5 && (line_data->delta_x >= -0.5 && line_data->delta_x <= 0.5))
	{
		line_data->radiant = Y;
		line_data->curr_y = floor(line_data->curr_y / 48) * 48;
		line_data->curr_y += WIMG * (line_data->curr_y == 0);
	}
	//QUADRANTE 2
	else if (line_data->delta_x > 0.5 && (line_data->delta_y >= -0.5 && line_data->delta_y <= 0.5))
	{
		line_data->radiant = X;
		line_data->curr_x = floor(line_data->curr_x / 48) * 48;
		line_data->curr_x += WIMG * (line_data->curr_x == 0);
	}
	//QUADRANTE 3
	else if (line_data->delta_y > 0.5 && (line_data->delta_x >= -0.5 && line_data->delta_x <= 0.5))
	{
		line_data->radiant = Y;
		line_data->curr_y = floor(line_data->curr_y / 48) * 48;
		line_data->curr_y += WIMG * (line_data->curr_y == 0);
	}
	//QUADRANTE 4
	else if (line_data->delta_x < -0.5 && (line_data->delta_y >= -0.5 && line_data->delta_y <= 0.5))
	{
		line_data->radiant = X;
		line_data->curr_x = floor(line_data->curr_x / 48) * 48;
		line_data->curr_x += WIMG * (line_data->curr_x == 0);
	}
} */
