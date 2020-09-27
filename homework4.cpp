#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void genfile()
{
	int temp;
	ofstream gen("sample.txt");
	for (int i = 1; i <= 10; i++)
	{
		cout << "Enter integer [" << i << "]: ";
		cin >> temp;
		gen << temp << endl;
	}
	gen.close();
}

int filesum()
{
	int temp, count = 0;
	ifstream sum("sample.txt");
	while (!sum.eof())
	{
		temp = 0;
		sum >> temp;
		count += temp;
	}
	return count;
}

int sign(int x)
{
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

float srec(float a, float b)
{
	return a * b;
}

float stri(float a, float b, float c)
{
	float p = (a + b + c) / 2;
	return p * (p - a) * (p - b) * (p - c);
}

float scir(float r)
{
	return M_PI * r * r;
}

void surfaces()
{
	float a, b, c;
	cout << "Rectangle
}

int main()
{
	// task 1
	cout << "Task 1: File Sum" << endl;
	genfile();
	cout << "Sum of numbers in file = " << filesum() << endl << endl;
	
	// task 2
	cout << "Task 2: Number Sign" << endl;
	cout << "Enter integer: ";
	int a; cin >> a;
	switch (sign(a))
	{
		case 1: cout << "The sign of " << a << " is '+'" << endl; break;
		case -1: cout << "The sign of " << a << " is '-'" << endl; break;
		case 0: cout << "Zero has no sign" << endl; break;
	}
	
	// task 3
	cout << "Task 3: Shape Surface" << endl;
	
}
