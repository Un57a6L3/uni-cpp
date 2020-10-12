#include <iostream>
#include <ctime>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
    for (long long n = 100; n <= 10000000; n *= 10)
    {
        clock_t t_begin = std::clock();
        int len = n/2 + n%2;
        int max_border = n/3;
        bitset<10000000> arr;
        arr.reset();
        for (long long i = 1; i <= max_border; ++i)
        {
            if (arr.test(i))
                continue;
            for (long long j = 3*i+1; j < len; j += 2*i+1)
                arr.set(j);
        }
        //for (int i = 0; i < len; ++i)
        //    if (!arr.test(i))
        //       cout << i*2+1 << " ";
        cout << "n = " << n << endl;
        cout << "Execution time: " << double(std::clock() - t_begin) / CLOCKS_PER_SEC << " seconds" << endl;
    }
    return 0;
}
