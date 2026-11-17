#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main () {
	struct Student {
		string surname;
		int grade;
	};
	Student st[5];
	int n = 0;
	while (n < 5) {
		string s = ""; int g = 0;
		if (!(cin >> s >> g)) break;
		else if (g >= 2 && g <= 5) {
			st[n].surname = s; st[n].grade = g;
			++n;
		}
		else cout << "warning: bad grade\n";
	}
	if (n == 0) {cout << "empty"; return 0;}
	float avg = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - 1; ++j) {
			if (st[j].surname > st[j+1].surname) swap(st[j], st[j+1]);
		}
	for (int i = 0; i < n; ++i) {
		cout << st[i].surname << ' ' << st[i].grade << '\n'; 
		avg += st[i].grade;
	}
	printf("avg=%.2f", avg/n);
	return 0;
}