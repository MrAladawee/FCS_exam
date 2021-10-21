#include <iostream>
#include <ctime>

using namespace std;

int random() {
    return rand() % 21 - 10;
}

void printArr(int* array) {
    for (int index = 0; index < 10; index++){
        cout << array[index] << " ";
    }
}

int main() {
    int N = 10;
    srand(time(NULL));
    int* array = new int[N];

    for (int index = 0; index < N; index++){
        array[index] = random(); // Заполнение элементов массива через ранд.знач.
    }

    printArr(array); // Вывод составленного массива.

    // Перестановки для первой половины массива.
    for (int index = 0; index < N/4; index++){
        int c = array[index];
        array[index] = array[(N-1)/2-index];
        array[(N-1)/2-index] = c;
    }

    // Перестановки для второй половины массива.
    for (int index = 0; index < N/4; index++){
        int c = array[index+5];
        array[index+5] = array[N-1-index];
        array[N-1-index] = c;
    }

    cout << endl;
    printArr(array);
}

/* Начальный массив  для 10 с делением по 2:
 * Замененный:
 *
 * 1    2   3   4   5  |  6   7   8   9   10
 * 5    4   3   2   1  |  10  9   8   7   6
 *
 */
