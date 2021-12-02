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

void delete_str_col(int **array, int **array_result, const int size_str, const int size_col, const int size_str_res, const int size_col_res) {

    int min_element = array[0][0]; // не 0, т.к могут быть отриц.числа в матрице
    int min_str = 0, min_col = 0;

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            if (array[str][col] < min_element) {
                min_element = array[str][col];
                min_str = str; min_col = col;
            }
        }
    }

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            if (str == min_str || col == min_col) continue;
            else {
                if (str > min_str && col < min_col) { array_result[str-1][col] = array[str][col]; }
                else if (str < min_str && col > min_col) { array_result[str][col-1] = array[str][col]; }
                else if (str > min_str && col > min_col) { array_result[str-1][col-1] = array[str][col]; }
                else if (str < min_str && col < min_col) { array_result[str][col] = array[str][col]; }
            }
        }
    }

    cout << "Min_el = " << min_element << endl;
    cout << "str = " << min_str << " col = " << min_col << endl << endl;

}

int main() {

    srand(time(NULL));
    cout << "Using random range [10;99]" << endl;

    // Determine the size
    //
    //
    int size_str_1, size_str_2, size_col_1, size_col_2;

    cout << "Write the size of the matrix:" << endl;
    cin >> size_str_1 >> size_col_1;

    size_str_2 = size_str_1 - 1;
    size_col_2 = size_col_1 - 1;

    // Error
    //
    //
    if (size_str_1 <= 0 || size_str_2 <= 0 || size_col_1 <= 0 || size_col_2 <= 0) { cout << "Error! Your sizes of matrices is wrong!"; return -1;}

    // Initialization
    //
    //
    int** array = new int* [size_str_1]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str_1; i++) {
        array[i] = new int[size_col_1]; // каждый из эл. есть массив из m элементов.
    }

    int** array_result = new int* [size_str_2]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str_2; i++) {
        array_result[i] = new int[size_col_2]; // каждый из эл. есть массив из m элементов.
    }
    
    // Main part
    //
    //
    initialization(array,size_str_1,size_col_1);
    print_array(array, size_str_1, size_col_1);
    cout << endl;

    delete_str_col(array,array_result,size_str_1,size_col_1,size_str_2,size_col_2);

    print_array(array_result, size_str_2, size_col_2);
}
