#include <iostream>
#include <cmath>

using namespace std;

void Digits(int number) {

    if (number <= 2) {
        cout << number;
        return;
    }

    // выполнение перебора до корня, где digit - возможный делитель числа number.
    for (int digit = 2; digit <= (floor(sqrt(number))); digit++) {
        if (number % digit == 0) {
            cout << digit << " x ";
            Digits(number / digit);
            return;
        }
    }

    cout << number;
}

int main() {
    system("chcp 65001");

    int number;
    cout << "Введите число, которое нужно разложить на простые сомножители: ";
    cin >> number;

    Digits(number);
    cout << " = " << number;
    return 0;
}
