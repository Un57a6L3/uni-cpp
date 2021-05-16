#include <iostream>
#include <chrono>
#include <vector>

void bubbleSortAiv (std::vector<int> &v, int n) {
    bool isSorted = false;
    for (int i = 0; !isSorted && i < n-1; ++i) {
        isSorted = true;
        for (int j = 0; j < n-i-1; ++j) {
            if (v[j] > v[j+1]) {
                std::swap (v[j], v[j+1]);
                isSorted = false;
            }
        }
    }
}

void bubbleSortAivLog (std::vector<int> &v, int n) {
    bool isSorted = false;
    long long comps = 0, swaps = 0;
    for (int i = 0; !isSorted && i < n-1; ++i) {
        isSorted = true;
        for (int j = 0; j < n-i-1; ++j) {
            ++comps;
            if (v[j] > v[j+1]) {
                ++swaps;
                std::swap (v[j], v[j+1]);
                isSorted = false;
            }
        }
    }
    std::cout << "Comps: " << comps << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Total: " << comps + swaps << std::endl;
}

void randFill (std::vector<int> &v, int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = rand() % n;
    }
}

void printVector (std::vector<int> &v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}

void fillAscend (std::vector<int> &v, int n)
{
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
}

void fillDescend (std::vector<int> &v, int n)
{
    for (int i = 0; i < n; ++i) {
        v[i] = n - i;
    }
}

int main() {
    //bool run = true;
    int length, k = 0;

    while (k++ < 4) {
        std::cout << "Length: ";
        std::cin >> length;
        std::vector<int> v(length);

        //randFill(v, length);
        fillDescend(v, length);

        //std::cout << "Generated array:" << std::endl;
        //printVector(v, length);

        auto begin = std::chrono::steady_clock::now();
        bubbleSortAivLog(v, length);
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        //std::cout << "Sorted array:" << std::endl;
        //printVector(v, length);

        std::cout << "Time = " << elapsed.count() << " ms" << std::endl;

        v.clear();
    }
}