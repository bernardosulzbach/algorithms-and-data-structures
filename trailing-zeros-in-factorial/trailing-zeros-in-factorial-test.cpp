#include <iostream>

#include "trailing-zeros-in-factorial.h"

using std::cin;
using std::cout;

int main() {
    unsigned tests;
    cin >> tests;
    unsigned value;
    while (tests--) {
        cin >> value;
        cout << trailing_zeros_in_factorial_of(value) << "\n";
    }
}