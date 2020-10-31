#include <iostream>
#include <fstream>
#include <cctype>
#include <windows.h>

using namespace std;

void analysis(string filename)
{
	string temp;
	ifstream fread(filename);
	char vowelen[] = {'a', 'e', 'i', 'o', 'u',
					  'A', 'E', 'I', 'O', 'U'};
	char vowelru[] = {'а' ,'е' ,'и', 'о' ,'у',
					  'я' ,'э' ,'ы', 'ё', 'ю',
					  'А' ,'Е' ,'И', 'О' ,'У',
					  'Я' ,'Э' ,'Ы', 'Ё', 'Ю'};
	int counten[] = {0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0};
	int countru[] = {0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0};

	while (!fread.eof())
	{
		getline(fread, temp);
		for (int i = 0; i < temp.length(); ++i)
		{
			for (int j = 0; j < 10; ++j)
				if (temp[i] == vowelen[j])
					++counten[j];
			for (int j = 0; j < 20; ++j)
				if (temp[i] == vowelru[j])
					++countru[j];
		}
	}

	int indexen, indexru, min;
	indexen = -1;
	min = 0x7FFFFFFF;
	for (int i = 0; i < 5; ++i)
		if (counten[i] + counten[i + 5] < min &&
			counten[i] + counten[i + 5] != 0)
			{
				indexen = i;
				min = counten[i] + counten[i + 5];
			}			
	
	indexru = -1;
	min = 0x7FFFFFFF;
	for (int i = 0; i < 10; ++i)
		if (countru[i] + countru[i + 10] < min &&
			countru[i] + countru[i + 10] != 0)
			{
				indexru = i;
				min = countru[i] + countru[i + 10];
			}			
			
	if (indexen == -1)
		cout << "There are no english vowels" << endl;
	else
		cout << "The rarest english vowel in the text file is '"
	     	 << vowelen[indexen] << "' with "
	     	 << counten[indexen] + counten [indexen + 5]
			 << " entries" << endl;
	
	if (indexru == -1)
		cout << "There are no russian vowels" << endl;
	else
		cout << "The rarest russian vowel in the text file is '"
	     	 << vowelru[indexru] << "' with "
	     	 << countru[indexru] + countru[indexru + 10]
			 << " entries" << endl;
}

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string name;
	cout << "Please enter file name:" << endl;
	getline(cin, name);
	cout << endl;

	analysis(name);
	cout << endl;
	system("pause");
}
