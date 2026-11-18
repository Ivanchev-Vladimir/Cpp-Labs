#include <iostream>
#include <fstream>
using namespace std;

int main () {
	ofstream file("data1.bin", ios::binary);
	if (!file.is_open()) return 0;
	double a[] = { 12.345, -7.891, 147.85, 3.141, 0.05 };
	double b[] = { };
	double c[] = { 4.5, 50.0, 12.3, 50.0, 1.1 };
	file.write(reinterpret_cast<const char*>(b), sizeof(b));
	cout << "done";
	file.close();
	return 0;
}