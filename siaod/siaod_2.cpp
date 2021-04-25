#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void get(int* mass, int n) {
	for (int i = 0; i < n; i++)
		cin >> mass[i];
}


void out(int* mass, int n) {
	for (int i = 0; i < n; i++)
		cout << mass[i] << " ";
}


void Random(int* mass, int n) {
	for (int i = 0; i < n; i++)
		mass[i] = rand() % 10;
}

int FirstEntry(int* mass, int n, int k) {
	int f = -1;
	for (int i = 0; i < n; i++)
		if (mass[i] == k)
		{
			f = i;
			break;
		}
	return f;
}

int Negative(int* mass, int n) {
	int f = -1;
	for (int i = 0; i < n; i++)
		if (mass[i] < 0)
		{
			f = i;
			break;
		}
	return f;
}

void AllEntries(int* mass, int n, int k) {
	bool f = false;
	for (int i = 0; i < n; i++)
		if (mass[i] == k)
		{
			f = true;
			cout << "Index of value: "<< i << endl;
		}
	if (!f)
		cout << "No entries";
}

void NewValue(int* mass, int k, int p) {
	mass[k] = p;
}

void Delete(int* mass, int n, int p) {
	for (int i = p; i < n - 1; i++)
		mass[i] = mass[i + 1];
}

int DeleteAll(int* mass, int n, int k) {
	int counter = 0, iter = 0;
	for (int i = 0; i < n; i++)
		if (mass[i] == k)
		{
			iter++;
			counter++;
			for (int j = i; j < n - 1; j++) {
				mass[j] = mass[j + 1];
				iter++;
			}
			mass[n - 1] = 0;
			i--;
		}
	cout << endl << "Iterations: " << iter << endl;
	return n - counter;
}

int DeleteAllEff(int* mass, int n, int k) {
	int iter = 0;
	vector<int> n_mass;
	for (int i = 0; i < n; i++)
	{
		if (mass[i] != k)
			n_mass.push_back(mass[i]);
		iter++;
	}		
	for (int i = 0; i < n_mass.size(); i++)
	{
		mass[i] = n_mass[i];
		iter++;
	}
	cout << endl << "Iterations: " << iter << endl;
	return n_mass.size();
}

void addForRealloc(int*& mass, int& n, int k, int p) {
	n++;
	mass = (int*)realloc(mass, (n) * sizeof(int));
	for (int i = n; i > k; i--)
		mass[i] = mass[i - 1];
	mass[k] = p;
}

void deleteForRealloc(int*& mass, int& n, int k) {
	int last = mass[n - 1];
	n--;
	mass = (int*)realloc(mass, (n) * sizeof(int));
	for (int i = k; i < n; i++)
		mass[i] = mass[i + 1];
	mass[n - 1] = last;
}


int main() {
	int n;
	cout << "Enter n: ";
	cin >> n;
	int* mass = new int[n];
	cout << "Enter array: " << endl;
	get(mass, n);
	
	int k;
	cout << "Enter index: ";
	cin >> k;
	
	if (k >= n) {
		cout << "Out of bounds";
		return 0;
	}
	
	//int p;
	//cout << "Enter new value: ";
	//cin >> p;
	
	//cout << "Print array:" << endl;
	//out(mass, n);
	//Random(mass, n);
	//cout << "Random array:" << endl;
	//out(mass, n);
	
	//cout << "Index of first entry: " << FirstEntry(mass, n, k);
	//cout << "Index of first negative: " << Negative(mass, n);
	//AllEntries(mass, n, k);
	
	//NewValue(mass, k, p);
	//Delete(mass, n, k);
	deleteForRealloc(mass, n, k);
	cout << "Print array:" << endl;
	out(mass, n);
	
	return 0;
}

