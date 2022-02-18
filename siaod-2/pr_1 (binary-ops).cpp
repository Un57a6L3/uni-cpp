#include <iostream>
#include <cstdlib>
#include <bitset>
#include <fstream>
#include <vector>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

void task1a()
{
    unsigned char a = 255, mask = 1;
    a = a & (~(mask << 4)); // a & 11101111
    cout << +a << endl; // + is so that a is read as a number
}

void task1b()
{
    unsigned char a = 0, mask = 1;
    a = a | (mask << 6); // a | 01000000
    cout << +a << endl; // + is so that a is read as a number
}

void task1c()
{
    unsigned int x = 25;           // binary 00011001
    const int n = sizeof(int) * 8; // 32 digits
    unsigned mask = (1 << n - 1);  // "1" in 32th digit

    cout << "Mask starting state: " << bitset<n> (mask) << endl;
    cout << "Result:              ";

    // this for loop prints every binary digit in x one at a time
    for (int i = 1; i <= n; i++)
    {
        cout << ((x & mask) >> (n - i));
        // x&mask clears all but one digits to 0
        // >>(n-i) moves the remaining digit into first
        mask = mask >> 1;
    }
    cout << endl;
}

void task2a()
{
    cout << "Array length (up to 8): ";
    int l; cin >> l; int input[l];
    cout << "Enter values (0 - 7): ";
    for (int i = 0; i < l; i++)
        cin >> input[i];
    unsigned char arr = 0, mask;
    const int n = sizeof (unsigned char) * 8;

    for (int i = 0; i < l; i++)
    { // setting n-th bit to 1 if n is present in the array
        mask = 1 << input[i];
        arr = arr | mask;
    }

    cout << "Sorting bitset state: " << bitset<n> (arr) << endl;
    cout << "Result: "; mask = 1;
    for (int i = 0; i < n; i++)
    { // printing n if n-th bit is 1
        if ((arr & mask) != 0)
            cout << i << " ";
        mask = mask << 1;
    }
}

void task2b()
{
    // changed values (8 -> 64)
    cout << "Array length (up to 64): ";
    int l; cin >> l; int input[l];
    cout << "Enter values (0 - 63): ";
    for (int i = 0; i < l; i++)
        cin >> input[i];

    // changed type (u char -> u long long)
    unsigned long long arr = 0, mask;
    const int n = sizeof (unsigned long long) * 8;

    // for some reason values over 30 broke the program
    // ran a test for loop to see what's happening
    // 0 - 30 set their bit to 1   // 31 set mask to 11..1100..00
    // 32 - 62 did same as 0 - 30  // 63 did same as 31

    // reason for that - the << operator returned INT value then = casted it to ULL
    // setting mask to 1 beforehand then shifting bits would not have caused this problem
    // instead I casted the 1 value to unsigned long long beforehand

    for (int i = 0; i < l; i++) {
        mask = 1ULL << input[i]; // <--- took a long time
        arr = arr | mask; }

    cout << "Sorting bitset state: " << bitset<n> (arr) << endl;
    cout << "Result: "; mask = 1;
    for (int i = 0; i < n; i++) {
        if ((arr & mask) != 0)
            cout << i << " ";
        mask = mask << 1; }
}

void task2c()
{
    cout << "Array length (up to 64): ";
    int l; cin >> l; int input[l];
    cout << "Enter values (0 - 63): ";
    for (int i = 0; i < l; i++)
        cin >> input[i];

    // changed back to chars but now there are 8 of them
    unsigned char mask, arr[8];
    for (int i = 0; i < 8; i++) arr[i] = 0;
    const int n = sizeof (unsigned char) * 8;

    // here n = 8 and later both n and 8 are used in code:
    // 8 refers to number of collections of bits (chars in arr[])
    // n refers to number of bits in a collection (bits in one char)

    for (int i = 0; i < l; i++) {
        int index = 7 - input[i] / n; // find the collection of bits
        mask = 1 << input[i] % n;     // find the bit in the collection
        arr[index] = arr[index] | mask; }

    cout << "Sorting bitset state:";
    for (int i = 0; i < 8; i++)
        cout << " " << bitset<n> (arr[i]);
    cout << endl << "Result: ";

    for (int i = 7; i >= 0; i--) { // start from the last array element
        mask = 1; // start from first bit in each element
        for (int j = 0; j < n; j++) {
            if ((arr[i] & mask) != 0)
                cout << (7 - i) * n + j << " ";
            mask = mask << 1; } }
}

void genfile (int count)
{
    ofstream file ("F:/Coding/Siaod2/input.txt");
    vector<int> nums; nums.reserve(count);
    for (int i = 0; i < count; ++i)
        nums.push_back(i);
    random_shuffle (nums.begin(), nums.end());
    for (const auto &e : nums) file << e << endl;
}

bool checksort()
{
    ifstream file ("F:/Coding/Siaod2/result.txt");
    int last, next, count = 0;
    file >> last;
    while (!file.eof())
    {
        file >> next; count++;
        if (next < last) return false;
    }
    cout << "Numbers read: " << count << endl;
    return true;
}

void sortfile()
{
    cout << "Sorting started..." << endl;
    const int min = 0, max = 999999; // configurable
    auto begin = chrono::steady_clock::now(); // start timer
    ifstream file ("F:/Coding/Siaod2/input.txt");
    bitset<max - min + 1> arr; int number; // create bit array

    // filling bit array
    while (!file.eof()) {
        file >> number;
        arr[number - min] = true; }

    // output results
    ofstream res ("F:/Coding/Siaod2/result.txt");
    for (int i = 0; i < arr.size(); ++i)
        if (arr[i])
            res << i + min << endl;

    auto end = chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "Time elapsed: " << elapsed.count() << " ms" << endl;
    if (checksort()) cout << "File sorted" << endl;
    else cout << "File not sorted" << endl;
}

void checksize()
{
    const int min = 1000000, max = 9999999;
    bitset<max - min + 1> arr;
    cout << "Size in bytes:  " << sizeof(arr) << endl
         << "Size in kbytes: " << sizeof(arr) / 1024.0 << endl
         << "Size in mbytes: " << sizeof(arr) / 1024.0 / 1024.0 << endl;
}

int main()
{
    //task1a();
    //task1b();
    //task1c();

    //task2a();
    //task2b();
    //task2c();

    //genfile(1000000);
    //sortfile();
    checksize();
}
