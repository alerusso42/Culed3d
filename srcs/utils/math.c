#include "../../cub3d.h"

double	safe_division(double delta, double sum)
{
	if (sum == 0 || delta == 0)
		return (0);
	return (delta / sum);
}

double	grad2rad(double grad)
{
	return (grad * (PI / 180));
}
double round_rad(double rad)
{
	if (rad > 0 && rad < 0.0001)
		return (0);
	else if (rad > 0 && rad > 0.9999)
		return (1);
	else if (rad < 0 && rad > -0.0001)
		return (0);
	else if (rad < 0 && rad < -0.9999)
		return (-1);
	return (rad);
}

double rad2deg(double rad)
{
	return (rad / (PI / 180));
}