#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

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

void usaflag()
{
	HANDLE hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	// parameters for text color
	// 15 - default (black bg, white text)
	// 31 for stars (blue bg, white text)
	// 64-79 for red stripe (red bg) - (68)
	// 240-255 for white stripe (white bg) - (255)
	
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (i < 6 && j < 8)
			{
				SetConsoleTextAttribute(hdl, 31);
				cout << "* ";
			}
			else if (i % 2 == 0)
			{
				SetConsoleTextAttribute(hdl, 64);
				cout << "  ";
			}
			else if (i % 2 == 1)
			{
				SetConsoleTextAttribute(hdl, 240);
				cout << "  ";
			}
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hdl, 15);
}

void printsin()
{
	int i = 25, j = 65;
	char graph[i][j];
	
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 65; j++)
		{
			if (j == 32) graph[i][j] = '|';
			else if (i == 12) graph[i][j] = '-';
			else graph[i][j] = ' ';
		}
	}
	
	int a;
	float x, y;
	for (j = 0; j < 65; j++)
	{
		x = M_PI * (j / 16.0 - 2);
		y = sin(x);
		y = y * (-10);
		if (y > 0) a = floor(y) + 12;
		else a = ceil(y) + 12;
		//graph[a][j] = '*';
		
		if (1 - fabs(cos(x)) > 0.85) graph[a][j] = '-';
		else if (cos(x) > 0) graph[a][j] = '^';
		else if (cos(x) < 0) graph[a][j] = 'v';		
	}
	
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 65; j++)
			cout << graph[i][j];
		cout << endl;
	}		
}

int main()
{
	/*
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
		case 1: cout << "The sign of " << a << " is '+'" << endl << endl; break;
		case -1: cout << "The sign of " << a << " is '-'" << endl << endl; break;
		case 0: cout << "Zero has no sign" << endl << endl; break;
	}
	
	// task 3
	cout << "Task 3: Shape Surface" << endl;
	surfaces();	
	
	// task 4
	cout << "Task 4: Old USA flag (1912)" << endl;
	usaflag();
	*/
	
	// task 5
	cout << "Task 5: Print sin(x)" << endl;
	printsin();
	
	cin.get(); // wait
}
