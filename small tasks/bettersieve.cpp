#include <iostream>
#include <ctime>
#include <cmath>
#define CPS CLOCKS_PER_SEC

using namespace std;

int main()
{
	clock_t t_init = clock();

	// initialization
	cout << "Enter sieve range: ";
	int N0, N, n;
	cin >> N0;

	clock_t t_begin = clock();

	// calculating array length
	N = N0 / 10;
	n = N0 % 10;
	if (n == 0) N = 4 * N;
	else N = 4 * (N + 1);

	// defining array
	int s[N];
	s[0] = 2;
	s[1] = 3;
	s[2] = 5;
	s[3] = 7;

	// filling array
	n = 10;
	for (int i = 4; i < N; i += 4)
	{
		s[i] = n + 1;
		s[i + 1] = n + 3;
		s[i + 2] = n + 7;
		s[i + 3] = n + 9;
		n += 10;
	}

	clock_t t_fill = clock();

	// sieving
	for (int i = 0; i < sqrt(N) + 4; ++i)
	{
		if (s[i] == 0) continue;
		for (int j = i + 1; j < N; ++j)
		{
			if (s[j] == 0) continue;
			if (s[j] % s[i] == 0)
				s[j] = 0;
		}
	}

	clock_t t_sieve = clock();

	// output
	n = 0;
	while (s[N] > N0) N--;
	for (int i = 0; i < N; ++i)
	{
		if (s[i] != 0)
		{
			cout << s[i] << "\t";
			if (++n == 8)
			{
				n = 0;
				cout << "\n";
			}
		}
	}

	clock_t t_print = clock();

	cout << "\n\nBetter sieve for numbers up to " << N0 << ":\n";
	// cout << "Time of user input:\t" << double(t_begin - t_init) / CPS << " s\n";
	cout << "Time to fill array:\t" << double(t_fill - t_begin) / CPS << " s\n";
	cout << "Time to sieve array:\t" << double(t_sieve - t_fill) / CPS << " s\n";
	cout << "Time to print array:\t" << double(t_print - t_sieve) / CPS << " s\n";
	cout << "Total time to execute:\t" << double(t_print - t_begin) / CPS << " s";
}
