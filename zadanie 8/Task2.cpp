#include <iostream>
#include <ctime>
#include "m_funcs.h"
// Умножение матриц.

using namespace std;

void multiply(int **array_1, int**array_2, const int size_str_1, const int size_col_1, const int size_str_2, const int size_col_2) {

    int m = size_col_1;

    for (int i = 0; i < size_str_1; i++) {
        for (int j = 0; j < size_col_2; j++) {

            int element_of_mltp = 0;
            for (int r = 0; r < m; r++) {
                element_of_mltp += array_1[i][r] * array_2[r][j];
            }

            cout << element_of_mltp << " ";

        }
        cout << endl;
    }
}

int main() {

    srand(time(NULL));
    cout << "Using random range [10;99]" << endl;

    // Determine the size
    //
    //
    int size_str_1, size_str_2, size_col_1, size_col_2;

    cout << "Write the size of the first matrix:" << endl;
    cin >> size_str_1 >> size_col_1;

    cout << "Write the size of the second matrix:" << endl;
    cin >> size_str_2 >> size_col_2;



    // Error
    //
    //
    if (size_col_1 != size_str_2) { cout << "Error! Your sizes of matrices is wrong for multiply!"; return -1;}
    if (size_str_1 <= 0 || size_str_2 <= 0 || size_col_1 <= 0 || size_col_2 <= 0) { cout << "Error! Your sizes of matrices is wrong for multiply!"; return -1;}



    // Initialization
    //
    //
    int** array_1 = new int* [size_str_1]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str_1; i++) {
        array_1[i] = new int[size_col_1]; // каждый из эл. есть массив из m элементов.
    }

    int** array_2 = new int* [size_str_2]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str_2; i++) {
        array_2[i] = new int[size_col_2]; // каждый из эл. есть массив из m элементов.
    }

    initialization(array_1,size_str_1,size_col_1);
    initialization(array_2,size_str_2,size_col_2);
    cout << endl;

    cout << "First matrix is:" << endl;
    print_array(array_1,size_str_1,size_col_1);
    cout << "Second matrix is:" << endl;
    print_array(array_2,size_str_2,size_col_2);



    // To multiply
    //
    //
    cout << "Multiply is:" << endl;
    multiply(array_1,array_2,size_str_1,size_col_1,size_str_2,size_col_2);

    return 0;
    
    // Memory clear
    del_array(array_1,size_str_1,size_col_1);
    del_array(array_2,size_str_2,size_col_2);
}
