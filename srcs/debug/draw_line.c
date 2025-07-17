// #include "../../cub3d.h"

// /* static void	quadrant(t_drawline *line_data); */
// static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data);
// static int	buliccio(t_drawline *line_data, t_data *data, int x, int y);
// static void	quadrant(t_drawline *line_data);
// static double rad2deg(double radianti);

// //	tan
// int	compute_line(t_data *data, int x, int y)
// {
// 	t_drawline	line_data;
// 	int			stepper;

// 	line_data = (t_drawline){0};
// 	stepper = WIMG - 1;
// 	reset_coord(line_data.line);
// 	line_data.pixel_p[X] = (data->player.line.map[X] * WIMG) + PLAYER_OFFSET;
// 	line_data.pixel_p[Y] = (data->player.line.map[Y] * HIMG) + PLAYER_OFFSET;
// 	line_data.pixel_win[X] = ((data->max_x + 1) * WIMG) + PLAYER_OFFSET;
// 	line_data.pixel_win[Y] = ((data->max_y + 1) * HIMG) + PLAYER_OFFSET;
// 	if (!data || x > line_data.pixel_win[X] || y > line_data.pixel_win[Y] || \
// 		x < 0 || y < 0 || \
// 		(line_data.pixel_p[X] == x && line_data.pixel_p[Y] == y))
// 		return (printf("ORA ORA ORA!"));
// 	buliccio(&line_data, data, x, y);
// 	while (line_data.int_x >= 0 && line_data.int_y >= 0 && \
// 			line_data.int_x <= line_data.pixel_win[X] && \
// 			line_data.int_y <= line_data.pixel_win[Y])
// 	{
// 		if (the_wall_checker(&stepper, &line_data, data) == true)
// 			break ;
// 		add_coord(line_data.line, line_data.int_x, line_data.int_y);
// 		update_coord(&line_data);
// 	}
// 	return (0);
// }

// static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data)
// {
// 	int			x;
// 	int			y;

// 	if (*stepper != WIMG - 1)
// 	{
// 		(*stepper)++;
// 		return (false);
// 	}
// 	(*stepper) = 0;
// 	x = (int)floor(line_data->curr_x / WIMG);
// 	y = (int)floor(line_data->curr_y / HIMG);
// 	if (data->map[y][x] == '1')
// 	{
// 		// printf("Wall at double X:%f\tY:%f\n", line_data->curr_x, line_data->curr_y);
// 		// printf("Wall at int X:%d\tY:%d\n", x, y);
// 		print_last_coord(data, line_data);
// 		return (true);
// 	}
// 	print_coord(data, line_data->line);
// 	reset_coord(line_data->line);
// 	return (false);
// }

// static int buliccio(t_drawline *line_data, t_data *data, int x, int y)
// {
// 	double	delta_sum;

// 	line_data->final_x = x;
// 	line_data->final_y = y;
// 	line_data->int_x = (data->player.line.map[X] * WIMG) + (WIMG / 2);
// 	line_data->int_y = (data->player.line.map[Y] * HIMG) + (HIMG / 2);
// 	line_data->curr_x = (int)(data->player.line.map[X] * WIMG) + (WIMG / 2);
// 	line_data->curr_y = (int)(data->player.line.map[Y] * HIMG) + (HIMG / 2);
// 	line_data->x_sign = POSITIVE;
// 	line_data->y_sign = POSITIVE;
// 	if ((data->player.line.map[X] * WIMG) + WIMG / 2 > x)
// 		line_data->x_sign = NEGATIVE;
// 	if ((data->player.line.map[Y] * HIMG) + HIMG / 2 > y)
// 		line_data->y_sign = NEGATIVE;
// 	line_data->next_x = line_data->int_x + line_data->x_sign;
// 	line_data->next_y = line_data->int_y + line_data->y_sign;
// 	line_data->delta_x = x - ((data->player.line.map[X] * WIMG) + (WIMG / 2));
// 	line_data->delta_y = y - ((data->player.line.map[Y] * HIMG) + (HIMG / 2));
// 	delta_sum = fabs(line_data->delta_x) + fabs(line_data->delta_y);
// 	line_data->delta_x = safe_division(fabs(line_data->delta_x), delta_sum);
// 	line_data->delta_y = safe_division(fabs(line_data->delta_y), delta_sum);
// 	line_data->delta_x *= line_data->x_sign;
// 	line_data->delta_y *= line_data->y_sign;
// 	quadrant(line_data);
// 	return (0);
// }

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
