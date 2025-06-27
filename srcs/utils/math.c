#include "../../cub3d.h"

double	safe_division(double delta, double sum)
{
	if (sum == 0 || delta == 0)
		return (0);
	return (delta / sum);
}
