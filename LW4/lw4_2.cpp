#include <iostream>
using  namespace std;

int main(){
	int n;
	if (!(cin >> n) || n < 1 || n > 20){
		cout << "n <= 20";
		return 0;
	}
	int orig_n = n; // запоминаем исходный размер для зануления хвоста и вывода
	
	int j = 0;

	int a[40] = {0};
	for (int i = 0; i < n; ++i){
		if (!(cin >> a[i])){
			cout << "error";
			return 0;
		}
	}
	
	// Шаг 1: Удаление отрицательных элементов за один проход O(n) и O(1) памяти
	for (int i = 0; i < n; ++i){
		if (a[i] >= 0){
			a[j] = a[i];
			++j;
		}
	}
	n = j; // длина массива после удаления отрицательных

	// Шаг 2: RLE-сжатие на месте
	j = 0; 
	int start = 0, cnt = 0, mem = a[0]; 
	int series_count = 0;

	for (int i = 0; i < n; ++i){
		if (a[i] == mem){
			++cnt; // серия продолжается
		} else {
			// Серия сменилась: записываем предыдущую пару <mem, cnt>
			if (cnt == 1){
				// Серия из 1 элемента расширяется до 2 - сдвигаем хвост вправо перед записью
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
				// Серия сжимается - сдвигаем хвост влево
				j = start + 2;
				for (int k = i; k < n; ++k){
					a[j] = a[k];
					++j;
				}
				n = j;
			}

			++series_count;
			start += 2;     // место под следующую пару
			mem = a[start]; // новое значение серии
			cnt = 1;        // сбрасываем счетчик для новой серии
			i = start;      // перемещаем i к новой серии (в цикле будет ++i)
		}
	}

	// Тщательно обрабатываем завершающую серию
	if (n > 0){
		a[start] = mem;
		a[start+1] = cnt;
		++series_count;
	}

	int new_len = 2 * series_count; // новая логическая длина

	// Шаг 3: Заполняем неиспользованный хвост нулями
	for (int k = new_len; k < orig_n; ++k){
		a[k] = 0;
	}

	// Шаг 4: Вывод новой логической длины и содержимого массива
	cout << new_len << '\n';
	int print_len = (orig_n > new_len) ? orig_n : new_len;
	for (int k = 0; k < print_len; ++k){
		cout << a[k] << (k + 1 == print_len ? "" : " ");
	}
	cout << '\n';

	return 0;
}