/*
 Определение трехзначного числа.
 Вычисление кол-ва дней до НГ.
 Чтение числа прописью.
 */

//task 1

#include <iostream>

int main() {
    system("chcp 65001");

    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    std::cout << std::endl;

    if (number < 0)
        number *= -1;

    if (number >= 1000 || number < 100)
        std::cout << "Число НЕ является трехзначным!";

    else
        std::cout << "Число является трехзначным.";

}