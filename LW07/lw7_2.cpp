#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

struct Vector3 {
	double x, y, z;
};

void GramSchmidt(Vector3& u, Vector3& v) {
	const double eps = 1e-9;
	double len_u = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
	if (len_u < eps) {
		cout << "degenerate\n";
		return;
	}
	Vector3 tu = {u.x / len_u, u.y / len_u, u.z / len_u};

	double sc = tu.x * v.x + tu.y * v.y + tu.z * v.z;
	Vector3 tv = {
		v.x - sc * tu.x,
		v.y - sc * tu.y,
		v.z - sc * tu.z
	};
	double len_tv = sqrt(tv.x * tv.x + tv.y * tv.y + tv.z * tv.z);
	if (len_tv < eps) {
		cout << "degenerate\n";
		return;
	}

	tu.x = (fabs(tu.x) < eps) ? 0.0 : tu.x;
	tu.y = (fabs(tu.y) < eps) ? 0.0 : tu.y;
	tu.z = (fabs(tu.z) < eps) ? 0.0 : tu.z;

	tv.x /= len_tv;
	tv.y /= len_tv;
	tv.z /= len_tv;

	tv.x = (fabs(tv.x) < eps) ? 0.0 : tv.x;
	tv.y = (fabs(tv.y) < eps) ? 0.0 : tv.y;
	tv.z = (fabs(tv.z) < eps) ? 0.0 : tv.z;

	u = tu;
	v = tv;

	
}

int main() {
	Vector3 u, v;
	if (!(cin >> u.x >> u.y >> u.z >> v.x >> v.y >> v.z))
		return 0;
	GramSchmidt(u, v);
	printf("%.3f %.3f %.3f\n%.3f %.3f %.3f\n", u.x, u.y, u.z, v.x, v.y, v.z);
	return 0;
}
