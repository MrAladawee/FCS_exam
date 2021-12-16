#include <iostream>
#include "m_funcs.h"

using namespace std;

int random() {
    return rand()%90 + 10;
}

void initialization(int **array, const int size_str, const int size_col) {
    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            array[str][col] = random();
        }
    }
}

void print_array(int **array, const int size_str, const int size_col) {
    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            cout << array[str][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void del_array(int** array, int str, int col) {
	for (int i = 0; i < col; i++)
		delete[] array[i];

	delete[] array;
}
