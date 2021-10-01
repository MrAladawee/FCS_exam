#include <iostream>

int main() {
    system("chcp 65001");

    int first_number, number;
    std::cout << "Введите число в диапазоне от -10 миллионов до 10 миллионов включая оба конца промежутка: ";
    std::cin >> first_number;
    std::cout << std::endl;

    // Проверим на отрицательное значение

    if (first_number < 0){
        std::cout << "Минус ";
        number = first_number * -1;
    }
    else {
        number = first_number;
    }
    int million = number / 1000000,
    thousand3 = (number / 100000) % 10, thousand2 = (number / 10000) % 10, thousand21 = (number / 1000) % 100, thousand1 = thousand21 % 10,
    unit3 = (number / 100) % 10, unit2 = (number / 10) % 10, unit21 = number % 100, unit1 = unit21 % 10;

    //  Проверим на ограничение + частные случаи

    if (number == 0) {
        std::cout << "Нуль";
        return 0;
    }

    if (number > 10000000 || number < -10000000) {
        std::cout << "Выход за возможные границы!";
        return 0;
    }

    if (number == 10000000) {
        std::cout << "Десять миллионов";
        return 0;
    }

    // Работаем с числом

    switch (million){
        case 9: std::cout << "девять миллионов "; break;
        case 8: std::cout << "восемь миллионов "; break;
        case 7: std::cout << "семь миллионов "; break;
        case 6: std::cout << "шесть миллионов "; break;
        case 5: std::cout << "пять миллионов "; break;
        case 4: std::cout << "четыре миллиона "; break;
        case 3: std::cout << "три миллиона "; break;
        case 2: std::cout << "два миллиона "; break;
        case 1: std::cout << "один миллион "; break;
    }

    if (thousand3 + thousand2 + thousand1 > 0) {
        
        if (thousand3 > 0) {

            switch (thousand3) {
                case 9: std::cout << "девятьсот "; break;
                case 8: std::cout << "восемьсот"; break;
                case 7: std::cout << "семьсот "; break;
                case 6: std::cout << "шестьсот "; break;
                case 5: std::cout << "пятьсот "; break;
                case 4: std::cout << "четыреста "; break;
                case 3: std::cout << "триста "; break;
                case 2: std::cout << "двести "; break;
                case 1: std::cout << "сто "; break;
            }
        }

        if (thousand2 >= 2) {

            switch (thousand2) {
                case 9: std::cout << "двеяносто "; break;
                case 8: std::cout << "восемьдесят "; break;
                case 7: std::cout << "семьдесят "; break;
                case 6: std::cout << "шестьдесят "; break;
                case 5: std::cout << "пятьдесят "; break;
                case 4: std::cout << "сорок "; break;
                case 3: std::cout << "тридцать "; break;
                case 2: std::cout << "двадцать "; break;
            }
        }

        if (thousand21 >= 10 && thousand21 <= 19) { // осматриваем ситуацию для окончаний на "цать". + "десять"

            switch (thousand21) {
                case 19: std::cout << "девятнадцать тысяч "; break;
                case 18: std::cout << "восемнадцать тысяч "; break;
                case 17: std::cout << "семнадцать тысяч "; break;
                case 16: std::cout << "шестнадцать тысяч "; break;
                case 15: std::cout << "пятнадцать тысяч "; break;
                case 14: std::cout << "четырнадцать тысяч "; break;
                case 13: std::cout << "тринадцать тысяч "; break;
                case 12: std::cout << "двенадцать тысяч "; break;
                case 11: std::cout << "одиннадцать тысяч "; break;
                case 10: std::cout << "десять тысяч "; break;
            }
        }

        else {
            switch (thousand1) {
                case 9: std::cout << "девять тысяч "; break;
                case 8: std::cout << "восемь тысяч "; break;
                case 7: std::cout << "семь тысяч "; break;
                case 6: std::cout << "шесть тысяч "; break;
                case 5: std::cout << "пять тысяч "; break;
                case 4: std::cout << "четыре тысячи "; break;
                case 3: std::cout << "три тысячи "; break;
                case 2: std::cout << "две тысячи "; break;
                case 1: std::cout << "одна тысяча "; break;
                default: std::cout << "тысяч "; break;
            }
        }
    }


    switch (unit3) {
        case 9: std::cout << "девятьсот "; break;
        case 8: std::cout << "восемьсот "; break;
        case 7: std::cout << "семьсот "; break;
        case 6: std::cout << "шестьсот "; break;
        case 5: std::cout << "пятьсот "; break;
        case 4: std::cout << "четыреста "; break;
        case 3: std::cout << "триста "; break;
        case 2: std::cout << "двести "; break;
        case 1: std::cout << "сто "; break;
    }

    switch (unit2){
        case 9: std::cout << "девяносто "; break;
        case 8: std::cout << "восемьдесят "; break;
        case 7: std::cout << "семьдесят "; break;
        case 6: std::cout << "шестьдесят "; break;
        case 5: std::cout << "пятьдесят "; break;
        case 4: std::cout << "сорок "; break;
        case 3: std::cout << "тридцать "; break;
        case 2: std::cout << "двадцать "; break;
    }

    if (unit21 >= 10 && unit21 <= 19) { // осматриваем ситуацию для окончаний на "цать". + "десять"

        switch (unit21) {
            case 19: std::cout << "девятнадцать "; break;
            case 18: std::cout << "восемнадцать "; break;
            case 17: std::cout << "семнадцать "; break;
            case 16: std::cout << "шестнадцать "; break;
            case 15: std::cout << "пятнадцать "; break;
            case 14: std::cout << "четырнадцать "; break;
            case 13: std::cout << "тринадцать "; break;
            case 12: std::cout << "двенадцать "; break;
            case 11: std::cout << "одиннадцать "; break;
            case 10: std::cout << "десять "; break;
        }
    }

    else { // остальные случаи имеют стандартное окончание
        switch (unit1) {
            case 9: std::cout << "девять "; break;
            case 8: std::cout << "восемь "; break;
            case 7: std::cout << "семь "; break;
            case 6: std::cout << "шесть "; break;
            case 5: std::cout << "пять "; break;
            case 4: std::cout << "четыре "; break;
            case 3: std::cout << "три "; break;
            case 2: std::cout << "два "; break;
            case 1: std::cout << "один "; break;
        }
    }

}