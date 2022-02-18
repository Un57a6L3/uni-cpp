#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

void print_arr(vector <vector<string>> crr) {
    for (auto & i : crr) {
        for (int j = 0; j < 9; j++) {
            cout << i[j];
        }
        cout << endl;
    }
}

void input_a(vector <vector<string>> arr) {
    ofstream a("test_samples/a.txt");

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            a << arr.at(i)[j];
        }
        if (i != arr.size() - 1) a << "\n";
    }
    a.close();
}

void input_b(vector <vector<string>> brr) {
    ofstream b("test_samples/b.txt");
    for (int i = 0; i < brr.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            b << brr.at(i)[j];
        }
        if (i != brr.size() - 1) b << "\n";
    }
    b.close();
}

void input_c(vector <vector<string>> crr) {
    ofstream c("test_samples/c.txt");
    for (int i = 0; i < crr.size(); ++i) {
        for (int j = 0; j < 9; j++) {
            c << crr.at(i)[j];
        }
        if (i != crr.size() - 1) c << "\n";
    }
    c.close();
}

vector <vector<string>> output_a(int n) {
    vector <vector<string>> arr;
    ifstream file("test_samples/a.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector <string> str;
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

vector <vector<string>> output_b(int n) {
    vector <vector<string>> arr;
    ifstream file("test_samples/b.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector <string> str;
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

vector <vector<string>> output_c(int n) {
    vector <vector<string>> arr;
    ifstream file("test_samples/с.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector <string> str;
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

vector <vector<string>> output_students(int n) {
    vector <vector<string>> arr;
    ifstream file("test_samples/out.txt");
    string buff;
    for (int i = 0; i < n; ++i) {
        vector <string> str;
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

void merge_files(int n1, int n2, int k) {
    vector <vector<string>> brr = output_b(n1);
    vector <vector<string>> crr = output_c(n2);
    vector <vector<string>> arr;
    int i = 0, j = 0;
    int q = k;
    while (i < n1 && q <= max(n1, n2)) {
        while ((i < q || j < q) && ((i + j) < (n1 + n2))) {
            cout << q << endl;
            cout << i << " " << j << endl;
            if (i < min(n1, n2) && j < min(n1, n2)) {
                if (brr.at(i)[0] <= crr.at(j)[0]) {
                    arr.push_back(brr.at(i));
                    i++;
                } else {
                    arr.push_back(crr.at(j));
                    j++;
                }
                if (i == q && j < q) {
                    for (j; j < q; j++) arr.push_back(crr.at(j));
                } else if (j == q && i < q) {
                    for (i; i < q; i++) arr.push_back(brr.at(i));
                } else if (i >= min(n1, n2)) {
                    for (i; i < q; i++) arr.push_back(brr.at(i));
                } else if (j >= min(n1, n2)) {
                    for (i; i < q; i++) arr.push_back(brr.at(i));
                }
            }
        }
        q += k;
    }
    input_a(arr);
}


void divide_file(vector <vector<string>> arr, int n, int k) {
    int u = 0;
    vector <vector<string>> b, c;
    for (int i = 0; i < n; ++i) {
        if (u < k) {
            u++;
            b.push_back(arr.at(i));
        } else {
            u++;
            if (u == 2 * k) u = 0;
            c.push_back(arr.at(i));
        }
    }
    input_b(b);
    input_c(c);
}


void merge_sort(int n) {
    vector <vector<string>> arr;
    arr = output_students(n);
    int k = 1;
    while (k < n) {
        divide_file(arr, n, k);
        int u = 0;
        int q1 = 0, q2 = 0;
        for (int i = 0; i < n; i++) {
            if (u < k)
                { u++; q1++; }
            else
                { q2++; u++; if (u == 2 * k) u = 0; }
        }
        merge_files(q1, q2, k);
        arr = output_a(n);
        k *= 2;
    }
}

int main() {
    unsigned int start_time = clock();
    setlocale(LC_ALL, "rus");
    int n = 16;
    // cin >> n;
    cout << "Length: " << n << endl;
    merge_sort(n);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << search_time << "ms";
    return 0;
}
