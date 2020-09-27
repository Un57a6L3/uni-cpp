#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // task 1
    cout << "Program by Arseny\n";

    // task 2
    float a, b, c, D, temp;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "Sum: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Product: " << a * b << endl;
    if (b != 0)
        cout << "Division: " << a / b << endl;
    else
        cout << "Can't divide by zero!" << endl;

    // task 3
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    cout << "Enter C: ";
    cin >> c;
    D = b * b - 4 * a * c;
    if (D >= 0)
    {
        cout << "First solution: " << (0 - b + sqrt(D)) / (2 * a) << endl;
        cout << "Second solution: " << (0 - b - sqrt(D)) / (2 * a) << endl;
    }
    else
        cout << "There are no solutions" << endl;

    // task 4
    bool day = false, curt = false, lamp = false;

    cout << "If daytime, enter 1: ";
    cin >> temp;
    if (temp == 1) day = true;
    cout << "If curtain is open, enter 1: ";
    cin >> temp;
    if (temp == 1) curt = true;
    cout << "If lamp is on, enter 1: ";
    cin >> temp;
    if (temp == 1) lamp = true;

    if ((day && curt) || lamp)
        cout << "The room is light" << endl;
    else cout << "The room is dark" << endl;
}
