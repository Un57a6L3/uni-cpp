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

void merge (int l, int m, int r, std::vector<int> &v) {
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> left_arr(n1), right_arr(n2);
    for (int i = 0; i < n1; ++i) {
        left_arr[i] = v[l + i];
    }
    for (int j = 0; j < n2; ++j) {
        right_arr[j] = v[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left_arr[i] < right_arr[j]) {
            v[k++] = left_arr[i++];
        }
        else {
            v[k++] = right_arr[j++];
        }
    }
    while (i < n1) {
        v[k++] = left_arr[i++];
    }
    while (j < n2) {
        v[k++] = right_arr[j++];
    }
}

void mergeSort (int left, int right, std::vector<int> &v) {
    if (left >= right) {
        return;
    }
    int middle = (left + right) / 2;
    mergeSort(left, middle, v);
    mergeSort(middle + 1, right, v);
    merge(left, middle, right, v);
}

void mergeLog (int l, int m, int r, std::vector<int> &v, long long &comps, long long &moves) {
    int n1 = m - l + 1, n2 = r - m;
    std::vector<int> left_arr(n1), right_arr(n2);
    for (int i = 0; i < n1; ++i)
        { left_arr[i] = v[l + i]; ++moves; }
    for (int j = 0; j < n2; ++j)
        { right_arr[j] = v[m + 1 + j]; ++moves; }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comps += 2;
        if (left_arr[i] < right_arr[j])
            { v[k++] = left_arr[i++]; ++moves; }
        else
            { v[k++] = right_arr[j++]; ++moves; }
    }
    while (i < n1)
        { v[k++] = left_arr[i++]; ++comps; ++moves; }
    while (j < n2)
        { v[k++] = right_arr[j++]; ++comps; ++moves; }
}

void mergeSortLog (int left, int right, std::vector<int> &v, long long &comps, long long &moves) {
    ++comps;
    if (left >= right) { return; }
    int middle = (left + right) / 2;
    mergeSortLog(left, middle, v, comps, moves);
    mergeSortLog(middle + 1, right, v, comps, moves);
    mergeLog(left, middle, right, v, comps, moves);
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
    long long comps = 0, moves = 0;

    while (k++ < 5) {
        std::cout << "Length: ";
        std::cin >> length;
        std::vector<int> v(length);

        //randFill(v, length);
        //fillDescend(v, length);

        //std::cout << "Generated array:" << std::endl;
        //printVector(v, length);

        auto begin = std::chrono::steady_clock::now();
        mergeSortLog(0, length - 1, v, comps, moves);
        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        //std::cout << "Sorted array:" << std::endl;
        //printVector(v, length);

        std::cout << "Comps: " << comps << std::endl;
        std::cout << "Moves: " << moves << std::endl;
        std::cout << "Total: " << comps + moves << std::endl;
        std::cout << "Time = " << elapsed.count() << " mcs" << std::endl;

        v.clear();
    }
}