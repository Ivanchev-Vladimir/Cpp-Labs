#include <cstdio>
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int a, b;
	if (!(cin >> a >> b))
		return 0;
	printf("before: %d %d\n", a, b);
	swap(a, b);
	printf("after: %d %d\n", a, b);	
	return 0;
}
