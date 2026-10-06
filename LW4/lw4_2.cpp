#include <iostream>
using  namespace std;

int main(){
	int n;
	if (!(cin >> n) || n < 1 || n > 20){
		cout << "n <= 20";
		return 0;
	}
	int orig_n = n;
	
	int j = 0;

	int a[40] = {0};
	for (int i = 0; i < n; ++i){
		if (!(cin >> a[i])){
			cout << "error";
			return 0;
		}
	}
	
	for (int i = 0; i < n; ++i){
		if (a[i] >= 0){
			a[j] = a[i];
			++j;
		}
	}
	n = j;

	j = 0; 
	int start = 0, cnt = 0, mem = a[0]; 
	int series_count = 0;

	for (int i = 0; i < n; ++i){
		if (a[i] == mem){
			++cnt; 
		} 
		else {
			if (cnt == 1){
				for (int k = n - 1; k >= i; --k){
					a[k+1] = a[k];
				}
				++n;
				a[start] = mem;
				a[start+1] = cnt;
			}
			if (cnt == 2){
				a[start] = mem;
				a[start+1] = cnt;
			}
			if (cnt > 2){
				a[start] = mem;
				a[start+1] = cnt;
				j = start + 2;
				for (int k = i; k < n; ++k){
					a[j] = a[k];
					++j;
				}
				n = j;
			}

			++series_count;
			start += 2;     
			mem = a[start]; 
			cnt = 1;        
			i = start;
		}
	}

	if (n > 0){
		a[start] = mem;
		a[start+1] = cnt;
		++series_count;
	}

	int new_len = 2 * series_count;

	for (int k = new_len; k < orig_n; ++k){
		a[k] = 0;
	}

	cout << new_len << '\n';
	for (int i = 0; i < new_len; ++i){
		cout << a[i] << ' ';
	}
	cout << '\n';

	return 0;
}