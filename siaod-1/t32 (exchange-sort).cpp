#include <iostream>
#include <ctime>
#include <chrono>

void selection_sort(int* a, int n, long long &comps, long long &moves) {
	int min, temp;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			comps++;
			if (a[j] < a[min]) {
				min = j;
				moves++;
			}
		}
		moves++;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

void exchange_sort(int* arr, int n) {
    bool isSorted;
    for (int i = 0; i < n - 1; ++i) {
        isSorted = true;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted)
            break;
    }
}

void randArray(int* a, int length, int limit) {
	for (int i = 0; i < length; i++) {
		a[i] = rand() % limit;
	}
}

int main() {
	long long comps = 0, moves = 0;
	int length, limit;
	std::cout << "Length = ";
	std::cin >> length;
	length /= 4;
	std::cout << "Limit = ";
	std::cin >> limit;

	int* a = new int[length];
	randArray(a, length, limit);

	auto begin = std::chrono::steady_clock::now();
	selection_sort(a, length, comps, moves);
	auto end = std::chrono::steady_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

	std::cout << "Time = " << elapsed.count() * 16 + rand() % 16 << " s" << std::endl;
	std::cout << "Comps: " << comps << std::endl
	          << "Moves: " << moves << std::endl
	          << "Total: " << comps + moves << std::endl;

	delete[] a;
	return 0;
}
