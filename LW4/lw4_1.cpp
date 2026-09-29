#include <iostream>
#include <climits>
using namespace std;

int main(){
	
	int n;
	if (!(cin >> n) || n < 1 || n > 10){
		cout << "1 <= n <= 10";
		return 0;
	}

	int a[10] = {0};
	for (int i = 0; i < n; ++i){
		if (!(cin >> a[i])){
			cout << "error";
			return 0;
		}
	}

	int min = INT_MAX, i_min = 0, max = INT_MIN, i_max = 0;
	for (int i = 0; i < n; ++i){
		cout << a[i] << ' ';
		if (min > a[i]){
			min = a[i];
			i_min = i;
		}
		if (max < a[i]){
			max = a[i];
			i_max = i;
		}
	}
	cout << '\n' << min << ' ' << i_min << ' ' << max << ' ' << i_max;

	return 0;
}