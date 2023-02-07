#include <iostream>
#include <iomanip>


void matrixProduct(int **a, int **b, int n) {
    int temp, iter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = 0;
            for (int k = 0; k < n; k++) {
                temp += a[i][k] * b[k][j];
                iter++;
            }
            std::cout << std::setw(6) << temp;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "Iterations: " << iter;
}


void random(int **a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 10;
}


void print(int **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << std::setw(4) << a[i][j];
        std::cout << std::endl;
    }
}


int main() {
    int n;
    std::cout << "Enter size of matrices: ";
    std::cin >> n;

    // declare 1st matrix
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // declare 2nd matrix
    int **b = new int *[n];
    for (int i = 0; i < n; i++)
        b[i] = new int[n];

    /*
    // input 1st matrix
    std::cout << "Enter elements of 1st martix:" << std::endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            std::cin >> a[i][j];

    // input 2nd matrix
    std::cout << "Enter elements of 2nd martix:" << std::endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            std::cin >> b[i][j];
    */

    random(a, n);
    std::cout << "1st matrix:" << std::endl;
    print(a, n);
    random(b, n);
    std::cout << "2nd matrix:" << std::endl;
    print(b, n);

    std::cout << "Matrix product:" << std::endl;
    matrixProduct(a, b, n);

    // clearing memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    for (int i = 0; i < n; i++)
        delete[] b[i];
}
