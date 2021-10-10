#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int sum_of_digits[10000]; // основной массив всех сумм.

int digits(int N){ // N - число < 10000
    int digit = 1;
    for (int d = 2; d < floor(sqrt(N)) + 1; d++){
        if (N % d == 0 && d != N/d) {
            digit += N/d;
            digit += d;
        }
        else if (N % d == 0 && d == N/d) {
            digit += d;
        }
    }
    return digit;
}

int main() {
    for (int number = 1; number < 10000; number++){
        sum_of_digits[number] = digits(number);
    }

    // перебор всех чисел на выполнение условия: дел(1) = 2 & дел(2) = 1.
    for (int number1 = 1; number1 < 10000; number1++){
        for (int number2 = number1 + 1; number2 < 10000; number2++){
            if (sum_of_digits[number1] == number2 && sum_of_digits[number2] == number1){
                cout << number1 << ", " << number2 << endl;
            }
        }
    }
}
