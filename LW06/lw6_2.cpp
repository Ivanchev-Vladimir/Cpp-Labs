#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2 || n == 3) return true;
	if ((n % 2 == 0) || (n % 3 == 0)) return false;
	for (int i = 5; i * i <= n; i += 6)
		if (n % i == 0 || n % (i + 2) == 0) return false;
	return true;
}

int main() {
	int n;
	if (!(cin >> n) || n > 50 || n < 1) {
		cout << "Error: invalid input N";
		return 0;
	}
	int a[50] = {0};
	for (int i = 0; i < n; ++i) {
		if (!(cin >> a[i])){
			cout << "Error: invalid input a[i]";
			return 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (isPrime(a[i])) {
			cout << a[i] << ' ';
			++cnt;
		}
	}
	if (cnt == 0){
		cout << "no primes";
		return 0;
	}
	cout << cnt << '\n';
	cnt = 0;
	for (int i = 0; i < n; ++i) {
	    if (isPrime(a[i]) && isPrime(2 * a[i] + 1)) {
    	    cout << a[i] << ' ';
    	    ++cnt;
    	}
	}
	if (cnt == 0){
		cout << "no primes";
		return 0;
	}
	cout << cnt;
	return 0;
}