#include <iostream>
#include <ctime>
#include <chrono>

void insertionSort(int* a, int n) {
	std::cout << "Selection Sort" << std::endl;
	long long comps = 0, moves = 0;
	int i, j, k;
	for (j = 1; j < n; j++) {
		k = a[j];
		i = j - 1;
		moves++;
		while ((i >= 0) && (a[i] > k)) {
			a[i + 1] = a[i];
			i--;
			comps++;
			moves++;
		}
		a[i + 1] = k;
	}
	//comps = comps * 16 + rand() % 16;
	//moves = moves * 16 + rand() % 16;
	//std::cout << "Comps: " << comps <<	std::endl
	//          << "Moves: " << moves <<	std::endl
	//          << "Total: " << comps + moves << std::endl;
}

void print(int* a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
}

void randArray(int* a, int length, int limit) {
	for (int i = 0; i < length; i++) {
		a[i] = rand() % limit;
	}
}

void fillSorted(int* a, int n, char sym) {
	switch (sym) {
		case '+':
			for (int i = 0; i < n; i++) a[i] = i;
			return;
		case '-':
			for (int i = 0; i < n; i++) a[i] = n-i-1;
			return;
	}
}

int main() {
	srand(NULL);
	int length, limit;
	std::cout << "Length = ";
	std::cin >> length;
	limit = 20;
	//std::cout << "Limit = ";
	//std::cin >> limit;

	int* a = new int[length];
	//fillSorted(a, length, '+');
	randArray(a, length, limit);
	std::cout << "Random array:" << std::endl;
	print(a, length);

	//auto begin = std::chrono::steady_clock::now();
	insertionSort(a, length);
	//auto end = std::chrono::steady_clock::now();
	//auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);
	print(a, length);

	//std::cout << "Length = " << length << std::endl;
	//std::cout << "Limit = " << limit << std::endl;
	//std::cout << "Time = " << elapsed.count() << " s";

	delete[] a;
	return 0;
}

