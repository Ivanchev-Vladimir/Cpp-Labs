#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

int main () {
	string s;
	getline(cin, s);
	int cnt = 0;
	for (size_t i = 0; i < s.length(); ++i) {
		if (s[i] == ' ') cnt ++;
	}
	cnt = (s.empty()) ? 0 : cnt + 1;
	cout << cnt;

	return 0;
}