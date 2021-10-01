/*
 Определение трехзначного числа.
 Вычисление кол-ва дней до НГ.
 Чтение числа прописью.
 */

//task 2

#include <iostream>

int main() {
    system("chcp 65001");
    int mounth, day;
    std::cout << "Введите номер месяца: ";
    std::cin >> mounth;
    std::cout << "Введите номер дня: ";
    std::cin >> day;
    if (day > 31 || day < 1) {
        std::cout << "Ошибка! Неверно введено число!";
        return 0;
    }
    day -= 1;
    int result = 0;

    switch (mounth) {
        case 1: result += 31;
        case 2: result += 28;
        case 3: result += 31;
        case 4: result += 30;
        case 5: result += 31;
        case 6: result += 30;
        case 7: result += 31;
        case 8: result += 31;
        case 9: result += 30;
        case 10: result += 31;
        case 11: result += 30;
        case 12: result += 31;
            break;
        default: std::cout << "Ошибка! Неверно введен номер месяца!"; return 0;
    }
    if (result - day <= 4)
        std::cout << "До Нового Года осталось " << result - day << " дня (включительно).";
    else
        std::cout << "До Нового Года осталось " << result - day << " дней (включительно).";
}