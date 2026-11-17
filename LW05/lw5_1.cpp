#include <iostream>
using namespace std;

int main(){

	int n, m;
	if (!(cin >> n >> m) || n > 10 || m > 10 || n < 1 || m < 1){
		cout << "error: n, m = (1, ..., 10)";
		return 0;
	}
	int a[10][10] = {0};
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(!(cin >> a[i][j])){
				cout << "error: a[i][j] = Z";
				return 0;
			}
		}
	}

	int rows[10] = {0}, cols[10] = {0};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j){
			rows[i] += a[i][j];
			cols[j] += a[i][j];
		}
	cout << "rows:";
	for (int k = 0; k < n; ++k) cout << ' ' << rows[k];
	cout << "\ncols:";
	for (int k = 0; k < m; ++k) cout << ' ' << cols[k];
	return 0;
}