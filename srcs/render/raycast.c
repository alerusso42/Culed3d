#include "../../cub3d.h"

static int	the_wall_checker(int *stepper, t_drawline *line_data, t_data *data);
static void	init_line_data(t_data *data, t_drawline *line_data, int *stepper);
static int	buliccio(t_drawline *line_data, t_data *data, double x, double y);

int	draw_line(t_data *data, double pov_x, double pov_y)
{
	t_drawline	line_data;
	int			stepper;

	if (!data || pov_x > 360 || pov_y > 360)
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
	int	x;
	int	y;

	if (*stepper != 0)
	{
		(*stepper)++;
		return (false);
	}
	(*stepper) = 0;
	x = (int)floor(line_data->curr_x / WIMG);
	y = (int)floor(line_data->curr_y / HIMG);
	if (data->map[y][x] == '1')
	{
		print_last_coord(data, line_data);
		return (true);
	}
	print_coord(data, line_data->line);
	reset_coord(line_data->line);
	return (false);
}

static int	buliccio(t_drawline *line_data, t_data *data, double x, double y)
{
	(void)y;
	line_data->int_x = (data->p_pos[X] * WIMG) + (WIMG / 2);
	line_data->int_y = (data->p_pos[Y] * HIMG) + (HIMG / 2);
	line_data->curr_x = (int)(data->p_pos[X] * WIMG) + (WIMG / 2);
	line_data->curr_y = (int)(data->p_pos[Y] * HIMG) + (HIMG / 2);
	line_data->next_x = line_data->int_x + line_data->x_sign;
	line_data->next_y = line_data->int_y + line_data->y_sign;
	line_data->delta_x = round_rad(cos(x));
	line_data->delta_y = round_rad(sin(x)) * -1;
	line_data->x_sign = POSITIVE;
	line_data->y_sign = POSITIVE;
	if (line_data->delta_x < 0)
		line_data->x_sign = NEGATIVE;
	if (line_data->delta_y < 0)
		line_data->y_sign = NEGATIVE;
	return (0);
}

static void	init_line_data(t_data *data, t_drawline *line_data, int *stepper)
{
	*line_data = (t_drawline){0};
	*stepper = 0;
	reset_coord(line_data->line);
	line_data->pixel_p[X] = (data->p_pos[X] * WIMG) + PLAYER_OFFSET;
	line_data->pixel_p[Y] = (data->p_pos[Y] * HIMG) + PLAYER_OFFSET;
	line_data->pixel_win[X] = ((data->max_x + 1) * WIMG) + PLAYER_OFFSET;
	line_data->pixel_win[Y] = ((data->max_y + 1) * HIMG) + PLAYER_OFFSET;
}
		