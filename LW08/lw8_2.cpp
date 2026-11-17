#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

int main () {
	string s, r = "";
	getline(cin, s);
	bool seen[128] = {false};
	for (size_t i = 0; i < s.length(); ++i){
		int a = tolower(s[i]);
		if (seen[a] == false) {
			seen[a] = true;
			r += s[i];
		}
	}
	cout << r;
	return 0;
}