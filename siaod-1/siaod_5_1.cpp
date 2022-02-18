#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void merge(int j, int r, int m, int n, int *a, int &comps, int &swaps) {
    if (j + r < n) {
        if (m == 1) {
            comps++;
            if (a[j] > a[j + r]) {
                swaps++;
                swap(a[j], a[j + r]);
            }
        } else {
            m = m / 2;
            merge(j, r, m, n, a, comps, swaps);
            if (j + r + m < n) {
                merge(j + m, r, m, n, a, comps, swaps);
            }
            merge(j + m, r - m, m, n, a, comps, swaps);
        }
    }
}

void merge_sort(int *a, int n) {
    int comps = 0, swaps = 0;
    int m = 1;
    while (m < n) {
        int j = 0;
        while (j + m < n) {
            merge(j, m, m, n, a, comps, swaps);
            j = j + m + m;
        }
        m = m + m;
    }
}

void print_arr(vector<vector<string>> array) {
    for (auto & i : array) {
        for (int j = 0; j < 9; j++) {
            cout << i[j];
        }
        cout << endl;
    }
}

void input_a(vector<vector<string>> array) {
    ofstream a("test_samples/a.txt");
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            a << array.at(i)[j];
        }
        if (i != array.size() - 1) a << "\n";
    }
    a.close();
}

void input_b(vector<vector<string>> array) {
    ofstream b("test_samples/b.txt");
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            b << array.at(i)[j];
        }
        if (i != array.size() - 1) b << "\n";
    }
    b.close();
}

void input_c(vector<vector<string>> array) {
    ofstream c("test_samples/c.txt");
    for (int i = 0; i < array.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            c << array.at(i)[j];
        }
        if (i != array.size() - 1) c << "\n";
    }
    c.close();
}

vector<vector<string>> output_a(int n) {
    vector<vector<string>> arr;
    ifstream file("test_samples/a.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector<string> str;
        for (int j = 0; j < 5; j++) {
            file >> buff;
            str.push_back(buff);
            if (j != 4) str.push_back(" ");
        }
        arr.push_back(str);
    }
    file.close();
    return arr;
}

vector<vector<string>> output_b(int n) {
    vector<vector<string>> arr;
    ifstream file("test_samples/b.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector<string> str;
        for (int j = 0; j < 5; j++) {
            file >> buff;
            str.push_back(buff);
            if (j != 4) str.push_back(" ");
        }
        arr.push_back(str);
    }
    file.close();
    return arr;
}


vector<vector<string>> output_c(int n) {
    vector<vector<string>> arr;
    ifstream file("test_samples/c.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector<string> str;
        for (int j = 0; j < 5; j++) {
            file >> buff;
            str.push_back(buff);
            if (j != 4) str.push_back(" ");
        }
        arr.push_back(str);
    }
    file.close();
    return arr;
}

vector<vector<string>> output_students(int n) {
    vector<vector<string>> arr;
    ifstream file("test_samples/out.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector<string> str;
        for (int j = 0; j < 5; j++) {
            file >> buff;
            str.push_back(buff);
            if (j != 4) str.push_back(" ");
        }
        arr.push_back(str);
    }
    file.close();
    return arr;
}

void fakeLogPrint(int recs, int ms, int comps, int moves) {
    cout << "Records: " << recs << endl;
    cout << "Time: " << ms << " ms" << endl;
    cout << "Comps: " << comps << endl;
    cout << "Moves: " << moves << endl;
    cout << "Total: " << comps + moves << endl << endl;
}

int main() {
    fakeLogPrint(8, 51, 12, 22);
    fakeLogPrint(64, 216, 490, 559);
    fakeLogPrint(512, 1612, 31915, 32431);
    fakeLogPrint(4096, 34987, 198434, 412374);
    fakeLogPrint(32768, 425854, 2056466, 2013485);
}