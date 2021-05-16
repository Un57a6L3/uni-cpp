#include <iostream>
#include <chrono>
#include <vector>

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

void cocktailShakerSort (std::vector<int> &v, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        for (int i = left; i < right; i++) {
            if (v[i] > v[i+1]) {
                std::swap(v[i], v[i+1]);
            }
        }
        --right;
        for (int i = right; i >= left; --i) {
            if (v[i] > v[i+1]) {
                std::swap(v[i], v[i+1]);
            }
        }
        ++left;
    }
}

void cocktailShakerSortLog (std::vector<int> &v, int n) {
    int left = 0, right = n - 1;
    long long comps = 0, swaps = 0;
    while (left <= right) {
        ++comps;
        for (int i = left; i < right; i++) {
            ++comps;
            if (v[i] > v[i+1]) {
                ++swaps;
                std::swap(v[i], v[i+1]);
            }
        }
        --right;
        for (int i = right; i >= left; --i) {
            ++comps;
            if (v[i] > v[i+1]) {
                ++swaps;
                std::swap(v[i], v[i+1]);
            }
        }
        ++left;
    }
    std::cout << "Comps: " << comps << std::endl;
    std::cout << "Swaps: " << swaps << std::endl;
    std::cout << "Total: " << comps + swaps << std::endl;
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
        cocktailShakerSortLog(v, length);
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);

        //std::cout << "Sorted array:" << std::endl;
        //printVector(v, length);

        std::cout << "Time = " << elapsed.count() << " ms" << std::endl;

        v.clear();
    }
}