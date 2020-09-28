#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

float fcreditm(float S, float p, float n)
{
	float m;
	p = p / 100;
	m = (S * p * pow(1.0 + p, n)) / (12 * (pow(1.0 + p, n) - 1));
	return m;
}

void creditm()
{
	float S, p, n, m;
	cout << "Input S: ";
	cin >> S;
	cout << "Input p: ";
	cin >> p;
	cout << "Input n: ";
	cin >> n;
	if (S < 0 || p < 0 || n < 0)
	{
		cout << "Invalid input!" << endl << endl;
		return;
	}	
	m = fcreditm(S, p, n);
	cout << "Monthly pay: m = " << m << endl << endl;
}

float fcreditp(float S, float n, float m)
{
	float p, pr, mr, temp;
	mr = 0xFFFFFFFF;
	for (p = 0; p < 100; p++)
	{
		temp = (S * (p / 100) * pow(1.0 + (p / 100), n)) / (12 * (pow(1.0 + (p / 100), n) - 1));
		if ((fabs(m - temp)) < mr)
		{
			mr = fabs(m - temp);
			pr = p;
		}
	}
	return pr;
}

void creditp()
{
	float S, p, n, m;
	cout << "Input S: ";
	cin >> S;
	cout << "Input n: ";
	cin >> n;
	cout << "Input m: ";
	cin >> m;
	if (S < 0 || m < 0 || n < 0)
	{
		cout << "Invalid input!" << endl << endl;
		return;
	}
	p = fcreditp(S, n, m);
	cout << "Credit % = " << p << endl << endl;
}

void filec()
{
	srand(time(NULL));
	
	ofstream fwrite("pootis.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
			fwrite << rand() % 100 << " ";
		fwrite << endl;
	}
	fwrite.close();

	string temp;
	ifstream fread("pootis.txt");
	while (!fread.eof())
	{
		getline(fread, temp);
		//fread >> temp;
		cout << temp << endl;
	}
	fread.close();
}

void prepod_valit()
{
	char alph[] = {"абвгдеёжзийклмнопрстуфхцчшщъыьэюя"};
	string str;
	char temp;
	bool found;
	int N, count = 0;
	
	cout << "Enter string:" << endl;
	cin >> str;
	
	string res(str.length(), '0');
	for (int i = 0; i < str.length(); i++)
	{
		temp = str[i];
		found = false;
		for (int a = 0; a < 33; a++)
			if (temp == alph[a])
				found = true;
		if (found)
		{
			for (int j = 0; j < res.length(); j++)
			{
				if (temp == res[j])
					break;
				if (res[j] == '0')
				{
					res[j] = temp;
					count++;
					break;
				}
			}
		}
	}
	res = res.substr(0, count);
	
	for (int i = 0; i < res.length(); i++)
	{
		for (int j = i + 1; j < res.length(); j++)
		{
			if (res[i] > res[j])
			{
				temp = res[i];
				res[i] = res[j];
				res[j] = temp;
			}
		}
	}
	
	cout << "Sorted string:" << endl << res << endl;
}

void charsort()
{
	srand(time(NULL));

	char alph[] = {"abcdefghigklmnopqrstuvwxyz"};	
	string str(30, 0);
	char temp;
	
	for (int i = 0; i < 30; i++)
		str[i] = alph[rand() % 26];
	
	cout << "Generated string:" << endl;
	cout << str << endl << endl;
	
	for (int i = 0; i < 30; i++)
	{
		for (int j = i + 1; j < 30; j++)
		{
			if (str[i] > str[j])
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	
	cout << "Sorted string:" << endl;
	cout << str << endl << endl;
}

void filter()
{
	srand(time(NULL));
	
	char alph[] = {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};

	ofstream fwrite("painis.txt");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (rand() % 2)
				fwrite << alph[rand() % 52] << " ";
			else
				fwrite << rand() % 100 << " ";
		}
		fwrite << endl;
	}
	fwrite.close();

	// print all
	cout << "Generated file:" << endl;
	// /*
	ifstream fprint("painis.txt");
	while (!fprint.eof())
	{
		string temp;
		getline(fprint, temp);
		//fprint >> temp;
		cout << temp << endl;
	}
	fprint.close();
	// */

	// print only numbers
	cout << "Filtered file:" << endl;
	ifstream fread("painis.txt");
	while (!fread.eof())
	{
		bool num = false;
		string temp;
		getline(fread, temp);
		//fread >> temp;
		for (int i = 0; i < temp.length(); i++)
		{
			if (isdigit(temp[i]))
			{
				cout << temp[i];
				num = true;
			}
			else if (num)
			{
				cout << " ";
				num = false;
			}
		}
		cout << endl;
	}
}

int main()
{
setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);	
	
	// task 1
	cout << "Task 1: Credit" << endl;
	creditm();

	// task 2
	cout << "Task 2: Credit %" << endl;
	creditp();

	// task 3
	cout << "Task 3: File copy" << endl;
	filec();

	// task 4
	cout << "Task 4: File filter" << endl;
	filter();
	
	// task 5
	cout << "Task 5: String sort" << endl;
	charsort();
	
	// task prepod valit
	cout << "Task NaN: Отчислен" << endl;
	prepod_valit();
}
