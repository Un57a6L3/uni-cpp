// Arseny Antonov IKBO-02-20
// Siaod PR 3
// Variant 15

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Sorting function for string array (alphabetical)
void sort (string *keywords, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; j > i; j--)
            if (keywords[j - 1].compare(keywords[j]) > 0)
            {
                string temp = keywords[j - 1];
                keywords[j - 1] = keywords[j];
                keywords[j] = temp;
            }
}

// Function to scramble keywords (that come already sorted)
void scrambleTextFile (int size)
{
    ifstream source ("F:/Coding/Siaod2/keywords.txt");
    ofstream file ("F:/Coding/Siaod2/keywords_scramble.txt");
    vector<string> keywords; keywords.reserve(size);
    string temp;
    for (int i = 0; i < size; ++i)
    {
        source >> temp;
        keywords.push_back(temp);
    }
    random_shuffle (keywords.begin(), keywords.end());
    for (const auto &e : keywords) file << e << endl;
}

void task1()
{
    const int size = 59; int index = 0;
    string keywords[size]; // Because there are 59 keywords in the list
    ifstream file("F:/Coding/Siaod2/keywords_scramble.txt");
    while (!file.eof())
    {
        file >> keywords[index];
        index++;
    }

    cout << "Scrambled keywords:" << endl;
    for (int i = 0; i < size; i++)
        cout << keywords[i] << " ";
    cout << endl << endl;

    sort(keywords, size);

    cout << "Sorted keywords:" << endl;
    for (int i = 0; i < size; i++)
        cout << keywords[i] << " ";
    cout << endl << endl;
}

// Find shift lengths for each symbol in pattern
void setPatternImage (string str, int size, int *asciiSet)
{
    int i;
    for (i = 0; i < 256; i++) // Initialize all symbols with -1
        asciiSet[i] = -1;
    for (i = 0; i < size; i++) // Set value of last occurrence of a character
        asciiSet[(int) str[i]] = i;
}

// Boyer-Moore-Horspool Algorithm
void searchABMH (string text, string pattern)
{
    int patSize = pattern.size();
    int txtSize = text.size();
    int asciiSet[256];

    // Set the image for searched pattern
    setPatternImage(pattern, patSize, asciiSet);
    int shift = 0, count = 0;
    while (shift <= (txtSize - patSize))
    {
        int j = patSize - 1;
        while (j >= 0 && pattern[j] == text[shift + j])
            j--; // Reducing j while characters of pattern and text are matching

        if (j < 0) // If pattern is matched, j is -1
        {
            count++;
            if (shift + patSize < txtSize) // Next shift
                shift += patSize - asciiSet[text[shift + patSize]];
            else
                shift++; // If the pattern is at the end of text
        }
        else
            // The max() function is to ensure positive shift
            shift += max(1, j - asciiSet[text[shift + j]]);
    }

    if (count != 0)
        cout << "The pattern \"" << pattern << "\" occurred " << count << " times" << endl;
    else
        cout << "The pattern \"" << pattern << "\" did not occur" << endl;
}

void task2()
{

    cout << "Enter text string:" << endl;
    string txt; getline(cin, txt);
    cout << "Enter number of patterns: ";
    int pat_num; cin >> pat_num;
    string pat[pat_num];
    for (int i = 0; i < pat_num; i++)
    {
        cout << "Enter pattern string:" << endl;
        cin >> pat[i];
    }
    cout << endl;
    for (int i = 0; i < pat_num; i++)
        searchABMH(txt, pat[i]);
}

int main()
{
    //task1();
    task2();
    return 0;
}
