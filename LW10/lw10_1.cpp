#include <fstream>
#include <iostream>
using namespace std;

int main () {
	double x;
	if (!(cin >> x)) {cout << "invalid x"; return 0;}

	ifstream file1("data.bin", ios::binary);
	if (!file1.is_open()) { cout << "error"; return 0; }
	double a[10] = {0};
	int n = 0;
	while (file1.read(reinterpret_cast<char*>(&a[n]), sizeof(double))) n++;

	for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << "\n";
	if (n == 0) {}
	
	double max = a[0]; int idx = 0;
	for (int i = 1; i < n; ++i)
		if (max < a[i]) { max = a[i]; idx = i; }
	// cout << max << " " << idx;
	for (int i = n; i > idx + 1; --i) swap(a[i], a[i-1]);
	a[idx+1] = x; ++n;
	for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << "\n";

	ofstream file2("data.bin", ios::binary);
	if (!file2.is_open()) return 0;
	file2.write(reinterpret_cast<const char*>(a), sizeof(a));
	file2.close();

	ifstream file3("data.bin", ios::binary);
	if (!file3.is_open()) { cout << "error"; return 0; }
	double b[10] = {0};
	int m = 0;
	while (file3.read(reinterpret_cast<char*>(&b[m]), sizeof(double))) m++;
	for (int i = 0; i < m; ++i) cout << b[i] << ' '; cout << "\n";


}