#include <cstdio>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

struct Item {
	string brand;
	double price;
};


int main () {
	ifstream file1("data2.bin", ios::binary);
	if (!file1.is_open()) { cout << "error"; return 0; }
	Item items[10];
	int n = 0;
	while (true) {
		int len;
		if (!file1.read(reinterpret_cast<char*>(&len), sizeof(len))) break;
		items[n].brand.resize(len);
		file1.read(&items[n].brand[0], len);
		file1.read(reinterpret_cast<char*>(&items[n].price), sizeof(double));
		++n;
	} 
	printf("%-10s %-10s\n", "Brand", "Price");
	for (int i = 0; i < n; ++i) 
		printf("%-10s %-10.2f\n", items[i].brand.c_str(), items[i].price);
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (items[j].price > items[j + 1].price) {
				swap(items[j], items[j+1]);
			}
		}
	}
	printf("--------------------\n");
	printf("%-10s %-10s\n", "Brand", "Price");
	for (int i = 0; i < n; ++i) 
		printf("%-10s %-10.2f\n", items[i].brand.c_str(), items[i].price);

	file1.close();

	ofstream file2("data2sort.bin", ios::binary);
	if (!file2.is_open()) return 0;
	for (int i = 0; i < n; ++i) {
		int len = items[i].brand.size();
		file2.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file2.write(items[i].brand.data(), len);
		file2.write(reinterpret_cast<const char*>(&items[i].price), sizeof(items[i].price));
	}
	file2.close();

	ifstream file3("data2sort.bin", ios::binary);
	if (!file3.is_open()) { cout << "error"; return 0; }
	Item ans[10];
	int k = 0;
	while (true) {
		int len;
		if (!file3.read(reinterpret_cast<char*>(&len), sizeof(len))) break;
		ans[k].brand.resize(len);
		file3.read(&ans[k].brand[0], len);
		file3.read(reinterpret_cast<char*>(&ans[k].price), sizeof(double));
		++k;
	} 
	printf("--------------------\n");
	printf("%-10s %-10s\n", "Brand", "Price");
	for (int i = 0; i < n; ++i) 
		printf("%-10s %-10.2f\n", ans[i].brand.c_str(), ans[i].price);

}