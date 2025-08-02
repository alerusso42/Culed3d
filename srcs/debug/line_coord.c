// #include "../../cub3d.h"

// //	Increments print coordinates, when the next integer points
// //	is surpassed.
// void	update_coord(t_entity *entity_data)
// {
// 	line_data->curr_x += line_data->delta_x;
// 	line_data->curr_y += line_data->delta_y;
// 	if (line_data->x_sign == POSITIVE)
// 	{
// 		if (line_data->curr_x >= (double)line_data->next_x)
// 		{
// 			line_data->int_x += line_data->x_sign;
// 			line_data->next_x += line_data->x_sign;
// 		}
// 	}
// 	else
// 	{
// 		if (line_data->curr_x <= (double)line_data->next_x)
// 		{
// 			line_data->int_x += line_data->x_sign;
// 			line_data->next_x += line_data->x_sign;
// 		}
// 	}
// 	if (line_data->y_sign == POSITIVE)
// 	{
// 		if (line_data->curr_y >= (double)line_data->next_y)
// 		{
// 			line_data->int_y += line_data->y_sign;
// 			line_data->next_y += line_data->y_sign;
// 		}
// 	}
// 	else
// 	{
// 		if (line_data->curr_y <= (double)line_data->next_y)
// 		{
// 			line_data->int_y += line_data->y_sign;
// 			line_data->next_y += line_data->y_sign;
// 		}
// 	}
// }

// void	add_coord(int line[WIMG + 1][2], int x, int y)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i][X] != INT_MAX && i < (WIMG))
// 		++i;
// 	line[i][X] = x;
// 	line[i][Y] = y;
// }

// void	reset_coord(int line[WIMG + 1][2])
// {
// 	int	i;

// 	i = -1;
// 	while (++i < (WIMG) + 1)
// 	{
// 		line[i][X] = INT_MAX;
// 		line[i][Y] = INT_MAX;
// 	}
// }

// void	print_coord(t_data *data, int line[WIMG + 1][2])
// {
// 	int	i;
 
// 	i = -1;
// 	while (line[++i][X] != INT_MAX && i < (WIMG))
// 	{
// 		mlx_pixel_put(data->mlx, data->win, \
// 						line[i][X], line[i][Y], 0xff000d);
// 	}
// }

// void	print_last_coord(t_data *data, t_entity *entity_data)
// {
// 	int	i;
 
// 	i = -1;
// 	while (line_data->line[++i][X] != INT_MAX && i < WIMG)
// 	{
// 		// printf("print_x:%d\t_y:%d\n", line_data->line[i][X], line_data->line[i][Y]);
// 		mlx_pixel_put(data->mlx, data->win, \
// 			line_data->line[i][X], line_data->line[i][Y], 0xff000d);
// 		if (data->map[line_data->line[i][Y] / HIMG]\
// 			[line_data->line[i][X] / WIMG] == '1')
// 				break ;
// 	}
// 	// printf("last_x:%d\tlast_y:%d\n", line_data->line[i][X], line_data->line[i][Y]);
// }

// // 0x53dd03