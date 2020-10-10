#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "Enter sieve range: ";
	cin >> N;
	int sieve[N];
	for (int i = 0; i < N; ++i)
		sieve[i] = i + 1;
	for (int i = 2; i < N / 2; ++i)
		for (int j = 1; j < N; ++j)
			if (((j + 1) != i) && ((j + 1) % (i) == 0))
				sieve[j] = 0;
	sieve[0] = 0;
	
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sieve[i] != 0)
		{
			cout << sieve[i] << "\t";
			count++;
		}
		if (count == 10)
		{
			cout << "\n";
			count = 0;
		}			
	}
}
