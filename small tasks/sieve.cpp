#include <iostream>
#include <ctime>

#define CPS CLOCKS_PER_SEC


int main() {
    clock_t t_init = clock();

    int N;
    std::cout << "Enter sieve range: ";
    std::cin >> N;

    clock_t t_begin = clock();

    int sieve[N];
    for (int i = 0; i < N; ++i)
        sieve[i] = i + 1;

    clock_t t_fill = clock();

    for (int i = 2; i < N / 2; ++i)
        for (int j = 1; j < N; ++j)
            if (((j + 1) != i) && ((j + 1) % (i) == 0))
                sieve[j] = 0;
    sieve[0] = 0;

    clock_t t_sieve = clock();

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (sieve[i] != 0) {
            std::cout << sieve[i] << "\t";
            count++;
        }
        if (count == 10) {
            std::cout << "\n";
            count = 0;
        }
    }

    clock_t t_print = clock();

    std::cout << "\n\nSieve for numbers up to " << N << ":\n";
    std::cout << "Time to fill array:\t" << double(t_fill - t_begin) / CPS << " s\n";
    std::cout << "Time to sieve array:\t" << double(t_sieve - t_fill) / CPS << " s\n";
    std::cout << "Time to print array:\t" << double(t_print - t_sieve) / CPS << " s\n";
    std::cout << "Total time to execute:\t" << double(t_print - t_begin) / CPS << " s";
}
