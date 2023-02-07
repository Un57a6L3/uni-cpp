#include <iostream>


int euclidean_divide(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}


int euclidean_subtract(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}


int main() {
    int a, b, m;
    std::cout << "Enter a, b: ";
    std::cin >> a >> b;
    std::cout << "Choose method: 1 - division, 2 - subtraction: ";
    std::cin >> m;
    switch (m) {
        case 1:
            std::cout << euclidean_divide(a, b);
            break;
        case 2:
            std::cout << euclidean_subtract(a, b);
            break;
        default:
            std::cout << "User is monkey";
    }
}
