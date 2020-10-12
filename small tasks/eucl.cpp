#include <iostream>

using namespace std;

int euclidean_divide(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int euclidean_subtract(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

int main()
{
	int a, b, m;
	cout << "Enter a, b: ";
	cin >> a >> b;
	cout << "Choose method: 1 - division, 2 - subtraction: ";
	cin >> m;
	switch (m)
	{
		case 1:
			cout << euclidean_divide(a, b);
			break;
		case 2:
			cout << euclidean_subtract(a, b);
			break;
		default:
			cout << "User is monkey";
	}	
}
