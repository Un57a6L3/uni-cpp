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
		cout << "Rectangle surface = " << c << endl << endl;
	else
		cout << "Error: invalid input!" << endl << endl;

	cout << "Triangle:" << endl << "Enter a, b, c: ";
	cin >> a >> b >> c;
	c = stri(a, b, c);
	if (c != -1)
		cout << "Triangle surface = " << c << endl << endl;
	else
		cout << "Error: invalid input!" << endl << endl;

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
	cout << endl;
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
	cout << endl;
}

// I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
// IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900

int rval(char letter)
{
	switch (letter)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}
}

int romantoarabic(string input)
{
	int result = 0;
	for (int i = 0; i < input.length(); ++i)
		input[i] = toupper(input[i]);
	for (int i = 0; i < input.length(); ++i)
	{
		if (i < input.length() - 1)
		{
			if (rval(input[i]) >= rval(input[i + 1]))
				result = result + rval(input[i]);
			else
			{
				result = result + rval(input[i + 1]) - rval(input[i]);
				++i;
			}
		}
		else result = result + rval(input[i]);
	}
	return result;
}

int main()
{
	int tasknum = 1;
	while (tasknum == 1)
	{
		cout << "Homework 4. Tasks:" << endl
		     << "1) File Sum" << endl
		     << "2) Number Sign" << endl
		     << "3) Shape Surface" << endl
		     << "4) Old USA Flag" << endl
		     << "5) Print sin(x)" << endl
		     << "6) Roman Number" << endl;
		cout << "Enter task number: ";
		cin >> tasknum;
		cout << endl;

		switch (tasknum)
		{
			case 1:
				cout << "Task 1: File Sum" << endl;
				genfile();
				cout << "Sum of numbers in file = " << filesum() << endl << endl;
				break;
			case 2:
				cout << "Task 2: Number Sign" << endl;
				cout << "Enter integer: ";
				int a;
				cin >> a;
				switch (sign(a))
				{
					case 1:
						cout << "The sign of " << a << " is '+'" << endl << endl;
						break;
					case -1:
						cout << "The sign of " << a << " is '-'" << endl << endl;
						break;
					case 0:
						cout << "Zero has no sign" << endl << endl;
						break;
				}
				break;
			case 3:
				cout << "Task 3: Shape Surface" << endl;
				surfaces();
				break;
			case 4:
				cout << "Task 4: Old USA flag (1912)" << endl;
				usaflag();
				break;
			case 5:
				cout << "Task 5: Print sin(x)" << endl;
				printsin();
				break;
			case 6:
				int result;
				cout << "Task 6: Decode Roman Numbers" << endl;
				string input;
				cout << "Enter roman number: ";
				cin >> input;
				result = romantoarabic(input);
				if (result == -1)
					cout << "Error: invalid input!" << endl << endl;
				else
					cout << "Result: " << result << endl << endl;
		}

		cout << "If you want to continue, enter 1: ";
		cin >> tasknum;
		cout << endl;
	}
}
