#include <iostream>
#include <ctime>

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

void replace_sc_relatively_diag(int **array, const int size_str, const int size_col) {

    for (int str = 0; str < size_str - 1; str++) {
        for (int col = 0; col < size_col - 1 - str; col++) {

            int temp = array[str][col];

            array[str][col] = array[(size_str - 1) - col][(size_col - 1) - str];
            array[(size_str - 1) - col][(size_col - 1) - str] = temp;
        }
    }

}

int main() {

    srand(time(NULL));
    cout << "Using random range [10;99]" << endl;

    // Determine the size
    //
    //
    int size_str, size_col;

    cout << "Write the size of the square matrix (str = col):" << endl;
    cin >> size_str >> size_col;
    cout << endl;

    // Error
    //
    //
    if (size_str <= 0 || size_col <= 0 || size_str != size_col) { cout << "Error! Your size of matrix is wrong!"; return -1;}

    // Initialization
    //
    //
    int** array = new int* [size_str]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str; i++) {
        array[i] = new int[size_col]; // каждый из эл. есть массив из m элементов.
    }

    // Main part
    //
    //
    cout << "Your matrix is:";
    initialization(array,size_str,size_col);
    print_array(array, size_str, size_col);

    replace_sc_relatively_diag(array,size_str,size_col);

    cout << "Matrix relatively side diagonal is:" << endl;
    print_array(array, size_str, size_col);
}
