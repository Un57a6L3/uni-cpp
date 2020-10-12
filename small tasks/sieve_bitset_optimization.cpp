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
        int max_border = (n/3 - 1) / 2;
        bitset<10000000> arr;
        arr.reset();
        for (long long i = 1; i <= max_border; ++i)
        {
            if (arr.test(i))
                continue;
            int step = 2*i+1;
            for (long long j = 5*i+2; j < len; j += step)
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
