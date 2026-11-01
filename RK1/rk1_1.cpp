#include "iostream"
using namespace std;

int main(){
	int n;
	if (!(cin >> n) || n > 10 || n < 1){
		cout << "bad n";
		return 0;
	}
	int a[10][10] = {0};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!(cin >> a[i][j])){
				cout << "bad a[i][j]";
				return 0;
			}

	int sum[19] = {0};
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			int d = j - i;
            int idx = d + n - 1;
            sum[idx] += a[i][j];
		}

	cout << "sums:";
	for (int i = 0; i < 2 * n - 1; ++i){
		cout << ' ' << sum[i];
	}
	cout << '\n' << "max ";
	int max = sum[0], d = - n + 1;
	for (int i = 1; i < 2 * n - 1; ++i){
		if (sum[i] > max){
			max = sum[i];
			d = i - n + 1;
		}
	} 
	cout << d << ' ' << max;

	return 0;
}