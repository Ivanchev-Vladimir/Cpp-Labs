#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	if (!(cin >> n) || n > 10 || n < 1){
		cout << "bad n";
		return 0;
	}
	int a[10][10] = {0};
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			if (!(cin >> a[i][j]) || (a[i][j] != 0 && a[i][j] != 1)){
				cout << "bad matrix";
				return 0;
			}
	}
	int k;
	if (!(cin >> k) || k > 15 || k < 1){
		cout << "bad k";
		return 0;
	}

	return 0;
}