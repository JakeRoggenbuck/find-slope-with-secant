#include <stdio.h>
#include <math.h>

#define H 0.000000001

struct PointSlope {
	double x_1;
	double x_2;
	double y_1;
	double y_2;
	double slope;
};

double f(double x) {
	// f(x) = 3x^2 - x^7 - 4x^3
	return 3 * pow(x, 2) - pow(x, 7) - 4 * pow(x, 3);
}

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

void draw(struct PointSlope* ps) {
	printf("slope: %lf\n", ps->slope);
	printf("equation: y - %lf = %lf ( x - %lf)\n", ps->y_1, ps->slope, ps->x_1);
}

int main() {
	double x_1 = 1.0;
	double x_2 = x_1 + H;

	struct PointSlope g_ps = get_aroc(x_1, x_2, g);
	struct PointSlope f_ps = get_aroc(x_1, x_2, f);

	draw(&g_ps);
	draw(&f_ps);
	return 0;
}
