#include <iostream>

using namespace std;

// difficulty: exponential
// breaks at n and m = ~20
unsigned long long pathsRec(int n, int m, unsigned long long &iters) {
    ++iters;
    if (n > 1 && m > 1)
        return pathsRec(n - 1, m, iters) + pathsRec(n, m - 1, iters);
    else
        return 1;
}


// difficulty: O(nm)
// limited by type maximum value at n, m = ~35
unsigned long long pathsDP(int n, int m, unsigned long long &iters) {
    if (n > m)
        swap(n, m);
    auto *sums = new unsigned long long[n];
    for (int i = 0; i < n; ++i)
        sums[i] = 1;
    for (int j = 0; j < m - 1; ++j)
        for (int i = 1; i < n; ++i) {
            sums[i] += sums[i - 1];
            ++iters;
        }
    return sums[n - 1];
}


unsigned long long pathsDP_print(int n, int m, unsigned long long &iters) {
    if (n > m)
        swap(n, m);
    auto *sums = new unsigned long long[n];
    for (int i = 0; i < n; ++i)
        sums[i] = 1;
    cout << "Array values:" << endl;
    for (int i = 0; i < n; ++i)
        cout << "1" << "\t";
    cout << endl;
    for (int j = 0; j < m - 1; ++j) {
        cout << "1";
        for (int i = 1; i < n; ++i) {
            sums[i] += sums[i - 1];
            cout << "\t" << sums[i];
            ++iters;
        }
        cout << endl;
    }
    return sums[n - 1];
}

int main() {
    int n, m;
    unsigned long long count, iters;
    cout << "Enter rectangle dimensions: ";
    cin >> n >> m;
    iters = 0;
    cout << endl << "----- DP method -----" << endl;
    count = pathsDP(n, m, iters);
    cout << "Answer: " << count << endl << "Iterations: " << iters << endl;
}
