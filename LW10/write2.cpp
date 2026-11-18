#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Item {
	string brand;
	double price;
};

int main () {
	ofstream file("data2.bin", ios::binary);
	if (!file.is_open()) return 0;
    
    Item items[] = {
	    {"Apple", 999.0},
	    {"Xiaomi", 250.5},
	    {"Samsung", 799.0},
	    {"Sony", 450.0},
	    {"Asus", 620.3}
	};	
	int n = sizeof(items) / sizeof(items[0]);

	for (int i = 0; i < n; ++i) {
		int len = items[i].brand.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(items[i].brand.data(), len);
		file.write(reinterpret_cast<const char*>(&items[i].price), sizeof(items[i].price));
	}
	file.close();
	cout << "done " << n << "\n";
	return 0;
}