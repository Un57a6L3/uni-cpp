#include <iostream>


void delFirstMethod(int *x, int n, int key) {
    int comp = 0, del = 0;
    int i = 0;

    while (i < n) {
        comp++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                comp++;
                x[j] = x[j + 1];
            }
            n--;
            del++;
        } else
            i++;
    }

    for (i = 0; i < n; i++)
        std::cout << x[i] << ' ';
    delete[] x;
    std::cout << std::endl << std::endl;
    std::cout << "Comparisons: " << comp
              << " Deletions: " << del << std::endl;
}


void delOtherMethod(int *x, int n, int key) {
    int comp = 0, del = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        x[j] = x[i];
        comp += 2;
        if (x[i] != key)
            j++;
        else
            del++;
    }
    n = j;

    for (int i = 0; i < n; i++)
        std::cout << x[i] << ' ';
    delete[] x;
    std::cout << std::endl << std::endl;
    std::cout << "Comparisons: " << comp
              << " Deletions: " << del << std::endl;
}


void random(int *x, int n) {
    for (int i = 0; i < n; i++)
        x[i] = rand() % 10;
}


void print(int *x, int n) {
    for (int i = 0; i < n; i++)
        std::cout << x[i] << ' ';
    std::cout << std::endl;
}


void fill(int *x, int n, int key) {
    for (int i = 0; i < n; i++)
        x[i] = key;
}


int main() {
    int n, key;
    std::cout << "Enter array length: ";
    std::cin >> n;
//	std::cout << "Enter array elements:" << std::endl;
    int *x = new int[n];
//	for (i = 0; i < n; i++)
//		std::cin >> x[i];
    random(x, n);
    print(x, n);
    std::cout << "Enter key: ";
    std::cin >> key;
//	fill (x, n, key);
//	print (x, n);
//	std::cout << std::endl << "New array:" << std::endl;
//	delFirstMethod (x, n, key);
    delOtherMethod(x, n, key);
    return 0;
}
