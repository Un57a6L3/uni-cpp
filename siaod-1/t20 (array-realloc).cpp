#include <cstdlib>
#include <iostream>
#include <vector>

/*
Warning: the brace style down below is not suited for sensitive people.
It is convenient for better compactness and readability of finished code.
But NEVER! use it while you're actually coding! You've been warned.
*/


void get(int* mass, int n)           {
    for (int i = 0; i < n; i++)
        std::cin >> mass[i]          ;}


void out(int* mass, int n)           {
    for (int i = 0; i < n; i++)
        std::cout << mass[i] << " "  ;}


void Random(int* mass, int n)        {
    for (int i = 0; i < n; i++)
        mass[i] = rand() % 10        ;}


int FirstEntry(int* mass, int n, int k)  {
    int f = -1                           ;
    for (int i = 0; i < n; i++)
        if (mass[i] == k)                {
            f = i                        ;
            break                        ;}
    return f                             ;}


int Negative(int* mass, int n)   {
    int f = -1                   ;
    for (int i = 0; i < n; i++)
        if (mass[i] < 0)         {
            f = i                ;
            break                ;}
    return f                     ;}


void AllEntries(int* mass, int n, int k)                      {
    bool f = false                                            ;
    for (int i = 0; i < n; i++)
        if (mass[i] == k)                                     {
            f = true                                          ;
            std::cout << "Index of value: "<< i << std::endl  ;}
    if (!f)
        std::cout << "No entries"                             ;}


void NewValue(int* mass, int k, int p)  {
    mass[k] = p                         ;}


void Delete(int* mass, int n, int p)    {
    for (int i = p; i < n - 1; i++)
        mass[i] = mass[i + 1]           ;}


int DeleteAll(int* mass, int n, int k)                             {
    int counter = 0, iter = 0                                      ;
    for (int i = 0; i < n; i++)
        if (mass[i] == k)                                          {
            iter++                                                 ;
            counter++                                              ;
            for (int j = i; j < n - 1; j++)                        {
                mass[j] = mass[j + 1]                              ;
                iter++                                             ;}
            mass[n - 1] = 0                                        ;
            i--                                                    ;}
    std::cout << std::endl << "Iterations: " << iter << std::endl  ;
    return n - counter                                             ;}


int DeleteAllEff(int* mass, int n, int k)                          {
    int iter = 0                                                   ;
    std::vector<int> n_mass                                        ;
    for (int i = 0; i < n; i++)                                    {
        if (mass[i] != k)
            n_mass.push_back(mass[i])                              ;
        iter++                                                     ;}
    for (int i = 0; i < n_mass.size(); i++)                        {
        mass[i] = n_mass[i]                                        ;
        iter++                                                     ;}
    std::cout << std::endl << "Iterations: " << iter << std::endl  ;
    return n_mass.size()                                           ;}


void addForRealloc(int*& mass, int& n, int k, int p)  {
    n++                                               ;
    mass = (int*)realloc(mass, (n) * sizeof(int))     ;
    for (int i = n; i > k; i--)
        mass[i] = mass[i - 1]                         ;
    mass[k] = p                                       ;}


void deleteForRealloc(int*& mass, int& n, int k)      {
    int last = mass[n - 1]                            ;
    n--                                               ;
    mass = (int*)realloc(mass, (n) * sizeof(int))     ;
    for (int i = k; i < n; i++)
        mass[i] = mass[i + 1]                         ;
    mass[n - 1] = last                                ;}


int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int* mass = new int[n];
    std::cout << "Enter array: " << std::endl;
    get(mass, n);

    int k;
    std::cout << "Enter index: ";
    std::cin >> k;

    if (k >= n) {
        std::cout << "Out of bounds";
        return 0;
    }

    int p;
    std::cout << "Enter new value: ";
    std::cin >> p;

//  std::cout << "Print array:" << std::endl;
//	out(mass, n);
//	Random(mass, n);
//  std::cout << "Random array:" << std::endl;
//	out(mass, n);

//  std::cout << "Index of first entry: " << FirstEntry(mass, n, k);
//  std::cout << "Index of first negative: " << Negative(mass, n);
//	AllEntries(mass, n, k);

    NewValue(mass, k, p);
//	Delete(mass, n, k);
//	deleteForRealloc(mass, n, k);
    std::cout << "Print array:" << std::endl;
    out(mass, n);

    return 0;
}

