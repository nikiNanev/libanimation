#include "../../include/math/interpolation.h"

double interpolate_linear(double x, double x1, double x2, double y1, double y2)
{
	/*
	 * y = linear interpolation value
	 * x = independent variable
	 * x1, y1 = values of the function at one point
	 * x2, y2 = values of the function at another point
	 */

	return y1 + (x - x1)*((y2-y1)/(x2-x1));
}
