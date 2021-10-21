// Task2
// Перевод из 2сс в 10сс
#include <iostream>
using namespace std;

int Transform(int number, int main_variable = 1) {
    
    // main_variable отвечает за то, на сколько умножается 1 или 0 (т.е степень двойки)
    // number отвечает за само число после преобразований (/10)
    
    if (number == 0) { return 0; } // Выход из рекурсии

    return Transform(number / 10, main_variable * 2) + number % 10 * main_variable;
}

int main() {
    system("chcp 65001");
    int number;
    
    cout << "Введите двоичное число, которое нужно перевести в 10сс: ";
    cin >> number;
    cout << endl;
    cout << Transform(number);

    return 0;
}
