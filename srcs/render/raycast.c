#include "../../cub3d.h"

static int	the_wall_checker(t_drawline *line_data, t_data *data);
static void	init_line_data(t_data *data, t_drawline *line_data, double pov_x);

int	draw_line(t_data *data, double pov_x)
{
	t_drawline	line_data;

	if (!data || pov_x > 360)
		return (printf("ORA ORA ORA!"));
	init_line_data(data, &line_data, pov_x);
	while ((the_wall_checker(&line_data, data) == false))
	{
		if (DEBUG == true)
			//add_coord(line_data.line, line_data.int_x, line_data.int_y);
			put_pixel(data, line_data.int_x, line_data.int_y, data->color);
		update_coord(&line_data);
	}
	return (0);
}

static int	the_wall_checker(t_drawline *line_data, t_data *data)
{
	int	x;
	int	y;

	x = (int)line_data->curr_x / WIMG;
	y = (int)line_data->curr_y / HIMG;
	if (data->map[y][x] == '1')
	{
		ray_lenght(data, x * WIMG, y * HIMG);
		return (true);
	}
	return (false);
}

static void	init_line_data(t_data *data, t_drawline *line_data, double pov_x)
{
	*line_data = (t_drawline){0};
	line_data->int_x = (data->player.screen[X]);
	line_data->int_y = (data->player.screen[Y]);
	line_data->curr_x = (int)data->player.screen[X];
	line_data->curr_y = (int)data->player.screen[Y];
	line_data->next_x = line_data->int_x + line_data->x_sign;
	line_data->next_y = line_data->int_y + line_data->y_sign;
	update_delta(pov_x, &line_data->delta_x, &line_data->delta_y);
	line_data->x_sign = POSITIVE;
	line_data->y_sign = POSITIVE;
	if (line_data->delta_x < 0)
		line_data->x_sign = NEGATIVE;
	if (line_data->delta_y < 0)
		line_data->y_sign = NEGATIVE;
}
		