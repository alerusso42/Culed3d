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
double rad2deg(double rad)
{
	if (rad > 0 && rad < 0.001)
		return (0);
	else if (rad > 0 && rad > 0.999)
		return (1);
	else if (rad < 0 && rad > -0.001)
		return (0);
	else if (rad < 0 && rad < -0.999)
		return (-1);
	// return (rad / (PI / 180));
	return (rad);
}