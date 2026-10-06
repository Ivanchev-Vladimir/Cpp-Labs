#include <iostream>
#include <string>
using namespace std;

int main() {
	
	// Ввод
	int n;
	if (!(cin >> n) || n > 10 || n < 1) {
		cout << "error: invalid n";
		return 0;
	}
	int a[10][10] = {0};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!(cin >> a[i][j])){
				cout << "error: invalid matrix element";
				return 0;
			}
		}
	}
	int k;
	if (!(cin >> k) || k > 3 || k < 1) {
		cout << "error: invalid k";
		return 0;
	}
	string flag;
	if (!(cin >> flag) || (flag != "main" && flag != "anti")) {
   	 	cout << "error: invalid flag";
   		return 0;
	}
	
	// Поворот k раз
	while (k != 0) {
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				swap(a[i][j], a[j][i]);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n / 2; ++j)
				swap(a[i][j], a[i][n - 1 - j]);
		--k;
	}	
	
	// Отражение
	if (flag == "main")
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				swap(a[i][j], a[j][i]);
	else
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n - 1 - i; ++j)
				swap(a[i][j], a[n - 1 - j][n - 1 - i]);

	// Вывод
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			cout << a[i][j] << ' ';
	cout << "\n";
	}
	return 0;
}