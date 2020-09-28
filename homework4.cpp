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
	if (a <= 0 || b <= 0)
		return -1;
	return a * b;
}

float stri(float a, float b, float c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return -1;	
	float p = (a + b + c) / 2;
	if (p - a <= 0 || p - b <= 0 || p - c <= 0)
		return -1;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

float scir(float r)
{
	if (r <= 0)
		return -1;
	return M_PI * r * r;
}

void surfaces()
{
	float a, b, c;
	
	cout << "Rectangle:" << endl << "Enter a, b: ";
	cin >> a >> b;
	c = srec(a, b);
	if (c != -1)
		cout << "Rectangle surface = " << c << endl;
	else
		cout << "Error: invalid input!" << endl;
	
	cout << "Triangle:" << endl << "Enter a, b, c: ";
	cin >> a >> b >> c;
	c = stri(a, b, c);
	if (c != -1)
		cout << "Triangle surface = " << c << endl;
	else
		cout << "Error: invalid input!" << endl;
	
	cout << "Circle:" << endl << "Enter radius: ";
	cin >> c;
	c = scir(c);
	if (c != -1)
		cout << "Circle surface = " << c << endl << endl;
	else
		cout << "Error: invalid input!" << endl << endl;
}

int main()
{
	// task 1
	//cout << "Task 1: File Sum" << endl;
	//genfile();
	//cout << "Sum of numbers in file = " << filesum() << endl << endl;
	
	// task 2
	cout << "Task 2: Number Sign" << endl;
	cout << "Enter integer: ";
	int a; cin >> a;
	switch (sign(a))
	{
		case 1: cout << "The sign of " << a << " is '+'" << endl << endl; break;
		case -1: cout << "The sign of " << a << " is '-'" << endl << endl; break;
		case 0: cout << "Zero has no sign" << endl << endl; break;
	}
	
	// task 3
	cout << "Task 3: Shape Surface" << endl;
	surfaces();
}
