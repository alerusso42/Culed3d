#include "../../cub3d.h"

/* static void	quadrant(t_drawline *line_data); */
static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data);
static void	init_line_data(t_data *data, t_drawline *line_data, int *stepper);
static int	buliccio(t_drawline *line_data, t_data *data, double x, double y);
// static void	quadrant(t_drawline *line_data);

int	draw_line(t_data *data, double pov_x, double pov_y)
{
	t_drawline	line_data;
	int			stepper;

	if (!data || pov_x < 0 || pov_x > 360 || pov_y < 0 || pov_y > 360)
		return (printf("ORA ORA ORA!"));
	init_line_data(data, &line_data, &stepper);
	buliccio(&line_data, data, pov_x, pov_y);
	while (1)
	{
		if (the_wall_checker(&stepper, &line_data, data) == true)
			break ;
		add_coord(line_data.line, line_data.int_x, line_data.int_y);
		update_coord(&line_data);
	}
	return (0);
}

static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data)
{
	int			x;
	int			y;

	if (*stepper != WIMG - 1)
	{
		(*stepper)++;
		return (false);
	}
	(*stepper) = 0;
	x = (int)floor(line_data->curr_x / WIMG);
	y = (int)floor(line_data->curr_y / HIMG);
	if (data->map[y][x] == '1')
	{
		// printf("Wall at double X:%f\tY:%f\n", line_data->curr_x, line_data->curr_y);
		// printf("Wall at int X:%d\tY:%d\n", x, y);
		print_last_coord(data, line_data);
		return (true);
	}
	print_coord(data, line_data->line);
	reset_coord(line_data->line);
	return (false);
}

static int	buliccio(t_drawline *line_data, t_data *data, double x, double y)
{
	double	delta_sum;
	double	cos_x;
	double	sin_x;

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
	cos_x = rad2deg(cos(x));
	sin_x = rad2deg(sin(x));
	delta_sum = fabs(cos_x) + fabs(sin_x);
	line_data->delta_x = safe_division(fabs(cos_x), delta_sum);
	line_data->delta_y = safe_division(fabs(sin_x), delta_sum);
	line_data->delta_x *= line_data->x_sign;
	line_data->delta_y *= line_data->y_sign;
	//quadrant(line_data);
	return (0);
}

static void	init_line_data(t_data *data, t_drawline *line_data, int *stepper)
{
	*line_data = (t_drawline){0};
	*stepper = WIMG - 1;
	reset_coord(line_data->line);
	line_data->pixel_p[X] = (data->p_pos[X] * WIMG) + PLAYER_OFFSET;
	line_data->pixel_p[Y] = (data->p_pos[Y] * HIMG) + PLAYER_OFFSET;
	line_data->pixel_win[X] = ((data->max_x + 1) * WIMG) + PLAYER_OFFSET;
	line_data->pixel_win[Y] = ((data->max_y + 1) * HIMG) + PLAYER_OFFSET;
}

// static void	quadrant(t_drawline *line_data)
// {
// 	double	excess;
// 	double	rad;
// 	double	x;
// 	double	y;

// 	rad = atan2(line_data->delta_y, line_data->delta_x);
// 	x = cos(rad);
// 	y = sin(rad);
// 	if (line_data->delta_y <= 0)
// 	{
// 		printf(BGREEN"delta_x: %f, delta_y: %f\n"RST, line_data->delta_x, line_data->delta_y);
// 		printf(RED"RADIANTI: %f\n"RST, atan2(line_data->delta_y, line_data->delta_x));
// 		printf(BYELLOW"GRADI: %f\n"RST, fabs(rad2deg(atan2(line_data->delta_y, line_data->delta_x))));
// 		printf(RED"int_x: %f\n"RST, x);
// 		printf(RED"int_y: %f\n"RST, y);
// 		printf(BYELLOW"true_int_x: %d\n"RST, line_data->int_x);
// 		printf(BYELLOW"true_int_y: %d\n"RST, line_data->int_y);
// 		return ;
// 	}
// 	else
// 	{
// 		excess = 180 - rad2deg(atan2(line_data->delta_y, line_data->delta_x));
// 		printf(BGREEN"delta_x: %f, delta_y: %f\n"RST, line_data->delta_x, line_data->delta_y);
// 		printf(RED"RADIANTI: %f\n"RST, atan2(line_data->delta_y, line_data->delta_x));
// 		printf(BYELLOW"GRADI: %f\n"RST, ((excess * 2) + rad2deg(atan2(line_data->delta_y, line_data->delta_x))));
// 		printf(RED"int_x: %f\n"RST, x);
// 		printf(RED"int_y: %f\n"RST, y);
// 		printf(BYELLOW"true_int_x: %d\n"RST, line_data->int_x);
// 		printf(BYELLOW"true_int_y: %d\n"RST, line_data->int_y);
// 	}
// }
		
