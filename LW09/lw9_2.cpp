#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
	struct Employee{
		string name;
		double salary;
		int years;
	};
	Employee e[10];
	int n = 0;
	while (n < 10) {
		string a; double b; int c; 
		if (!(cin >> a >> b >> c)) break;
		else if (b > 0 && c >= 0){
			e[n].name = a; e[n].salary = b; e[n].years = c;
			++n;
		}
		else cout << "warning: bad salary or years\n";
	}
	
	if (n == 0) {
		cout << "none";
		return 0;
	}

	double avg = 0.0;
	for (int i = 0; i < n; ++i) {
		avg += e[i].salary;
	}
	avg /= n;

	int r[9];
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (e[i].salary < avg) {
			r[m] = i;
			++m;
		}
	}
	
	for (int j = 0; j < m-1; ++j) {
		for (int i = 0; i < m-1; ++i) {
			if(e[r[i]].name > e[r[i+1]].name) swap(r[i], r[i+1]);
		}
	}

	int mx = -1, index = 0;
	for (int i = 0; i < m; ++i) {
		if (e[r[i]].years > mx) { mx = e[r[i]].years; index = r[i]; }
	}
	
	if (m == 0) 
		cout << "none";
	else {
		printf("%-10s %-15s %-2s\n", "name", "salary", "years");
		for (int i = 0; i < m; ++i)
			printf("%-10s %-15.2f %-2d\n", e[r[i]].name.c_str(), e[r[i]].salary, e[r[i]].years);
		e[index].salary *= 2;
	}

	printf("\n%-10s %-15s %-2s\n", "name", "salary", "years");
	for (int i = 0; i < n; ++i) {
		printf("%-10s %-15.2f %-2d\n", e[i].name.c_str(), e[i].salary, e[i].years);
	}
	return 0;
}
