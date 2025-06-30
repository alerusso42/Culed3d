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
	// return (rad / (PI / 180));
	return (rad * (180 / PI));
}