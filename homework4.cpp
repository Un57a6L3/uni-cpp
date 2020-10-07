#define PI acos(-1)
#include <cmath>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <cctype>

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
	return PI * r * r;
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
		x = PI * (j / 16.0 - 2);
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
	int count = 1;
	int result = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		input[i] = toupper(input[i]);
		if (i != 0)
			if (input[i] == input[i - 1])
				count++;
			else
				count = 1;
		if (count > 3)
			return -1;
	}
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

int crand(int prev, int v)
{
	if (v != 2)
		return (37 * prev + 3) % 64;
	else
		return (25173 * prev + 13849) % 65537;
}

void genrand()
{
	int v, N, temp;
	cout << "Enter PRNG variant - 1 (default) or 2: ";
	cin >> v;
	cout << "Enter number of integers to generate: ";
	cin >> N;
	cout << "Enter seed (default is 0): ";
	cin >> temp;
	for (int i = 0; i <= N; ++i)
	{
		temp = crand(temp, v);
		cout << "Pseudo-random integer S[" << i << "]: " << temp << endl;
	}
	cout << endl;
}

void matrixtask()
{
	// matrices here are hardcoded, since they are constant in the task
	double a[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
	double b[4][2] = {{1.2, 0.5}, {2.8, 0.4}, {5.0, 1.0}, {2.0, 1.5}};
	double c[3][2];
	double sum;

	// matrix multiplication
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
		{
			c[i][j] = 0;
			for (int k = 0; k < 4; ++k)
				c[i][j] += a[i][k] * b[k][j];
		}

	// additional tasks
	// initialization
	double max, min, temp;
	int imax, imin;

	// 1) which seller got most and least profit
	imax = 0;
	imin = 0;
	max = c[0][0];
	min = c[0][0];
	for (int i = 1; i < 3; ++i)
	{
		temp = c[i][0];
		if (temp > max)
		{
			max = temp;
			imax = i;
		}
		if (temp < min)
		{
			min = temp;
			imin = i;
		}
	}
	cout << "Merchant " << imax + 1
	     << " got the most profit: "
	     << max << endl;
	cout << "Merchant " << imin + 1
	     << " got the least profit: "
	     << min << endl;

	// 2) which seller got most and least commitions
	imax = 0;
	imin = 0;
	max = c[0][1];
	min = c[0][1];
	for (int i = 1; i < 3; ++i)
	{
		temp = c[i][1];
		if (temp > max)
		{
			max = temp;
			imax = i;
		}
		if (temp < min)
		{
			min = temp;
			imin = i;
		}
	}
	cout << "Merchant " << imax + 1
	     << " got the most commitions: "
	     << max << endl;
	cout << "Merchant " << imin + 1
	     << " got the least commitions: "
	     << min << endl;

	// 3-5) total profit & total commitions
	max = c[0][0] + c[1][0] + c[2][0];
	min = c[0][1] + c[1][1] + c[2][1];
	cout << "Total profit: " << max << endl;
	cout << "Total commitions: " << min << endl;
	cout << "Total money: " << max + min << endl;
	cout << endl;
}

int xtodecimal(string number, int x)
{
	int sum = 0, digit = 1;
	char t;
	for (int i = number.length() - 1; i >= 0; --i)
	{
		t = number[i];
		if (!isalnum(t))
			return -1;
		if (isdigit(t))
			t = t - 48;
		if (isalpha(t))
			t = toupper(t) - 55;
		if (t >= x)
			return -1;
		sum += digit * t;
		digit *= x;
	}
	return sum;
}

string decimaltox(int number, int x)
{
	string result;
	char figure;
	int digit;
	while (number > 0)
	{
		digit = number % x;
		number /= x;
		if (digit >= 0 && digit <= 9)
			figure = digit + '0';
		if (digit >= 10 && digit <= 35)
			figure = digit + 'A' - 10;
		result = result + figure;
	}
	for (int i = 0, j = result.length() - 1; i < j; ++i, --j)
	{
		figure = result[i];
		result[i] = result[j];
		result[j] = figure;
	}
	return result;
}

void numeralsystems()
{
	string number;
	int x, y;
	cout << "Enter unsigned number in NS base X (input): ";
	cin >> number;
	cout << "Enter X for NS base X from 2 to 36 (input): ";
	cin >> x;
	cout << "Enter Y for NS base Y from 2 to 36 (output): ";
	cin >> y;
	if (x < 2 || x > 36 || y < 2 || y > 36)
	{
		cout << "Error: invalid input!" << endl << endl;
		return;
	}
	for (int i = 0; i < number.length(); ++i)
		number[i] = toupper(number[i]);
	if (x > 16 || y > 16)
	{
		cout << endl << "You've entered base > 16, so here's a reminder!"
		     << endl << "A = 10  B = 11  C = 12  D = 13"
		     << endl << "E = 14  F = 15  G = 16  H = 17"
		     << endl << "I = 18  J = 19  K = 20  L = 21"
		     << endl << "M = 22  N = 23  O = 24  P = 25"
		     << endl << "Q = 26  R = 27  S = 28  T = 29"
		     << endl << "U = 30      V = 31      W = 32"
		     << endl << "X = 33      Y = 34      Z = 35"
		     << endl << endl;
	}
	int decimal = xtodecimal(number, x);
	if (decimal == -1)
	{
		cout << "Error: invalid input!" << endl << endl;
		return;
	}
	string result = decimaltox(decimal, y);
	cout << "Result: " << result << endl << endl;
}

int main()
{
	cout << "Program by Un57a6L3" << endl << endl;
	int tasknum = 1;
	while (tasknum != 0)
	{
		cout << "Homework 4. Tasks:" << endl
		     << "1) Sum of integers in file" << endl
		     << "2) Sign of integer" << endl
		     << "3) Surface of shapes" << endl
		     << "4) Print old USA flag" << endl
		     << "5) Print function sin(x)" << endl
		     << "6) Roman number to int" << endl
		     << "7) Pseudo-random numbers" << endl
		     << "8) Matrix multiplication" << endl
		     << "9) Numeral system change" << endl;
		cout << "Enter task number or 0 to finish: ";
		if (!(cin >> tasknum)) return 1;
		cout << endl;

		switch (tasknum)
		{
			case 0:
				tasknum = 0;
				break;
			case 1:
				cout << "Task 1: Sum of integers in file" << endl;
				genfile();
				cout << "Sum of numbers in file = " << filesum() << endl << endl;
				break;
			case 2:
				cout << "Task 2: Sign of integer" << endl;
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
				cout << "Task 3: Surface of shapes" << endl;
				surfaces();
				break;
			case 4:
				cout << "Task 4: Print old USA flag" << endl;
				usaflag();
				break;
			case 5:
				cout << "Task 5: Print function sin(x)" << endl;
				printsin();
				break;
			case 6:
				{
					cout << "Task 6: Roman number to int" << endl;
					cout << "Enter roman number: ";
					string input;
					cin >> input;
					int result;
					result = romantoarabic(input);
					if (result == -1)
						cout << "Error: invalid input!" << endl << endl;
					else
						cout << "Result: " << result << endl << endl;
					break;
				}
			case 7:
				cout << "Task 7: Pseudo-random numbers" << endl;
				genrand();
				break;
			case 8:
				cout << "Task 8: Matrix multiplication" << endl;
				matrixtask();
				break;
			case 9:
				cout << "Task 9: Numeral system change" << endl;
				numeralsystems();
				break;
			default:
				cout << "Invalid input, try again!" << endl << endl;
				break;
		}
	}
}
