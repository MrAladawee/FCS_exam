#include <iostream>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
void print_array(T* array, const int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}


template <typename T>
void array_initialization(T* array, int size) {
    for (int i = 0; i < size; i++){
        cin >> array[i];
    }
    cout << endl;
}

template <typename T>
bool check_str_int(T a, T b) {
    return to_string(a) > to_string(b);
}

int lenght_of_int(int x) {
    int len = 0;

    if (x == 0) return 1;
    while (x > 0) {
        x /= 10;
        len++;
    }
    return len;
}

template <typename T>
T max_of_two(T a, T b) {
    if (a > b) { return a; }
    else { return b; }
}

bool check_str_double(double a, double b) {
    a = abs(a); b = abs(b);

    if (a * b <= 0)
        return a > b;

    int a_whole = (int)a, b_whole = (int)b; // выделение целой части
    int a_whole_lenght = lenght_of_int(a_whole), b_whole_lenght = lenght_of_int(b_whole); // определение длины
    int max_lenght = max_of_two(a_whole_lenght, b_whole_lenght); // определение макс.длины

    int compare_1 = (int)(a * pow(10, max_lenght - a_whole_lenght) - b * pow(10, max_lenght - b_whole_lenght));
    if (compare_1 < 0) { return false; }
    else if (compare_1 > 0) { return true; }

    int compare_2 = a_whole - b_whole;
    if (compare_2 < 0) return false;
    else if (compare_2 > 0) return true;

    double a_fractional = a - a_whole;
    double b_fractional = b - b_whole;

    double cmp3 = a_fractional - b_fractional;
    if (cmp3 < 0) { return false; }
    else if (cmp3 > 0) { return true; }

    return false;
}

typedef bool (*comparator)(double a, double b);

void bubble(double* array, int size, comparator cmp) // использование cmp как сравнение
{
    for (int index = 0; index < size; index++)
        for (int s_index = 0; s_index < size - 1; s_index++) {
            if (cmp(array[s_index], array[s_index + 1])) {
                double c = array[s_index];
                array[s_index] = array[s_index + 1];
                array[s_index + 1] = c;
            }
        }
}

int main()
{
    // Инициализация размера
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    cout << endl;

    // Работа с ошибками
    if (size <= 0) {
        cout << "Error! You have written wrong size!";
        return -1;
    }

    double* array = new double[size];

    comparator my = check_str_double;
    comparator string = check_str_int;

    array_initialization(array, size);

    cout << "Array sorted by lexicographical method:" << endl;
    bubble(array, size, string);
    print_array(array, size);

    return 0;
}
