#include <iostream>
using namespace std;

void Digits(int number) {

    if (number < 10) {
        cout << number;
        return;
    }

    Digits(number / 10);
    cout << "  " << number % 10;
}

int main() {
    system("chcp 65001");

    int number;
    cout << "Введите число: ";
    cin >> number;

    Digits(number);

    return 0;
}
