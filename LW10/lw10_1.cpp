#include <fstream>
#include <iostream>
using namespace std;

int main () {
	double x;
	if (!(cin >> x)) {cout << "invalid x"; return 0;}
	ifstream file("data.bin", ios::binary);
	if (!file.is_open()) { cout << "error"; return 0; }
	double a[10] = {0};
	int n = 0;
	while (file.read(reinterpret_cast<char*>(&a[n]), sizeof(double))) n++;
	for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << "\n";
	if (n == 0) {}
	double max = 
	for (int i = 0; i < n)


}