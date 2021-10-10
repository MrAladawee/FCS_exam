// Вычисление Nого числа Фибоначи
#include <iostream>

using namespace std;

int fib(int N) {
    //Работа с исключениями.
    if (N == 0){ return 0; }
    else if (N == 1) { return 1; }
    else if (N == 2) { return 1; }
    else if (N < 0) { cout << "Ошибка! N'ое число не может быть отрицательным!"; return -1;}

    //Основной алгоритм.
    else {
        int prev_number = 1;
        int next_number = 1;
        int count = 2;

        while (count != N) {
            next_number = prev_number + next_number;
            prev_number = next_number - prev_number;
            count++;
        }
        return next_number;
    }
}

int main() {
    system("chcp 65001"); // Руссификация.

    int N;
    cout << "Введите номер нужного числа Фибоначчи: ";
    cin >> N;
    cout << endl;
    cout << fib(N);
}