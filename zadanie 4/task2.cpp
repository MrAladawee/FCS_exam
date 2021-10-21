#include <iostream>
#include <ctime>

using namespace std;

int random() {
    return rand() % 21 - 10;
}

void printArr(int* array) {
    for (int index = 0; index < 12; index++){
        cout << array[index] << " ";
    }
}

int main() {
    int N = 12;
    srand(time(NULL));
    int* array = new int[N];

    for (int index = 0; index < N; index++){
        array[index] = random(); // Заполнение элементов массива через ранд.знач.
    }

    printArr(array); // Вывод составленного массива.

    // Перестановки для первой половины массива.
    for (int index = 0; index < N/6; index++){
        int c = array[index];
        array[index] = array[(N)/4-index];
        array[(N)/4-index] = c;
    }

    // Перестановки для второй половины массива.
    for (int index = 0; index < N/6; index++){
        int c = array[index+4];
        array[index+4] = array[(N/2) + 1 - index];
        array[(N/2) + 1 - index] = c;
    }

    // Перестановки для третьей половины массива.
    for (int index = 0; index < N/6; index++){
        int c = array[index+8];
        array[index+8] = array[N-1-index];
        array[N-1-index] = c;
    }

    cout << endl;
    printArr(array);
  
/* Начальный массив  для 12 с делением по 3:
 * Замененный:
 * 0    1   2   3  |  4   5   6   7  |  8   9   10  11
 *
 * 1    2   3   4  |  5   6   7   8  |  9   10  11  12
 * 4    3   2   1  |  8   7   6   5  |  12  11  10  12
 *
 */
  
}
