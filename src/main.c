#include <stdio.h>

#define H 0.00001

struct PointSlope {
	double x_1;
	double x_2;
	double y_1;
	double y_2;
	double slope;
};

double g(double x) {
	// g(x) = x^2 - 2x - 2
	return (x * x) - (2.0 * x) - 2.0;
}

struct PointSlope get_aroc(double x_1, double x_2, double (*func)(double)) {
	double y_2 = func(x_2);
	double y_1 = func(x_1);

	double delta_y = y_2 - y_1;
	double delta_x = x_2 - x_1;

	double slope = delta_y / delta_x;

	struct PointSlope ps = { x_1, x_2, y_1, y_2, slope};
	return ps;
}

int main() {
	double x_1 = 4.0;
	double x_2 = x_1 + H;
	struct PointSlope ps = get_aroc(x_1, x_2, g);

	printf("slope: %f\n", ps.slope);
	printf("equation: y - %f = %f ( x - %f)\n", ps.y_1, ps.slope, ps.x_1);
	return 0;
}
