#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

using namespace std;

void cone()
{
	float R, r, h;
	cout << "Enter bigger radius: "; cin >> R;
	cout << "Enter smaller radius: "; cin >> r;
	cout << "Enter height: "; cin >> h;
	if (R < 0 || r < 0 || h < 0)
	{
		cout << "Invalid input!" << endl;
		return;
	}
	if (R < r)
	{
		int temp = R;
		R = r;
		r = temp;
	}
	cout << "Volume: V = " << (1.0 / 3) * M_PI * h * (pow(R, 2) + R * r + pow(r, 2)) << endl;
	cout << "Surface: S = " << M_PI * (pow(R, 2) + pow(r, 2) + 	pow((pow(R - r, 2) + pow(h, 2)),0.5) * (R + r)) << endl;
	
	//sqrt(pow(R - r, 2) + pow(h, 2))
	//pow((pow(R - r, 2) + pow(h, 2)),0.5)
	
	return;
}

void branch()
{
	float x, a;
	cout << "Enter x: "; cin >> x;
	cout << "Enter a: "; cin >> a;
	if (fabs(x) < 1 && x != 0)
		cout << "w = " << a * log(fabs(x)) << endl;
	else
	{
		if (a - pow(x, 2) >= 0)
			cout << "w = " << sqrt(a - pow(x, 2)) << endl;
		else
			cout << "w doesn't exist for these values!" << endl;
	}
}

void func()
{
	float x, y, b;
	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "Enter b: "; cin >> b;
	//cin >> x >> y >> b;
	if ((b - y) > 0 && (b - x) >= 0)
		cout << "z = " << log(b - y) * sqrt(b - x) << endl;
	else
		cout << "z doesn't exist for these values!" << endl;
}

void order()
{
	int N;	
	cout << "Enter N: "; cin >> N;
	if (N < 1)
	{
		cout << "Invalid input" << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << N + i << " ";
	}
	cout << endl;
}

void tab()
{
	float x = -4;
	while(x<=4)
	{
		cout << "y(" << x << ") ";
		if (x != 1)
			cout << "= " << ((pow(x, 2) - 2 * x + 2) / (x - 1)) << endl;
		else
			cout << "doesn't exist" << endl;
		x += 0.5;
	}
	/*
	for (float x = -4; x <= 4; x += 0.5)
	{
		cout << "y(" << x << ") ";
		if (x != 1)
			cout << "= " << ((pow(x, 2) - 2 * x + 2) / (x - 1)) << endl;
		else
			cout << "doesn't exist" << endl;
	}
	*/
}

int main()
{
	// task 1
	cout << "Task 1: Cone" << endl;
	//cone();

	// task 2
	cout << endl << "Task 2: Branch" << endl;
	//branch();

	// task 3
	cout << endl << "Task 3: Function" << endl;
	//func();

	// task 4
	cout << endl << "Task 4: Order" << endl;
    //order();

	// task 5
	cout << endl << "Task 5: Tab" << endl;
	tab();
}
