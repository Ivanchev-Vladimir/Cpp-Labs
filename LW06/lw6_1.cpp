#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	return sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1)*(y2 - y1)));
}

int main() {
	double Ax, Ay, Bx, By, Cx, Cy;
	if (!(cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy)) {
		cout << "Error: Invalid input A, B, C";
		return 0;
	}
	double AB, BC, CA, P, s, eps = 1e-9;
	s = 0.5 * fabs((Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)));
	if (s <= eps) {
		cout << "degenerate";
		return 0;
	}
	AB = distance(Ax, Ay, Bx, By);
	BC = distance(Bx, By, Cx, Cy);
	CA = distance(Cx, Cy, Ax, Ay);
	P = AB + BC + CA;
	printf("P = %.2f", P);	

	return 0;
}