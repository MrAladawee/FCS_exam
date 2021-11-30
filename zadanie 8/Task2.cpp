#include <iostream>
#include <ctime>

// Транспозиция

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

void transposition(int **array, int**array_trnsp, const int size_str, const int size_col) {

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            array_trnsp[col][str] = array[str][col];
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

    cout << "Write the size of the matrix:" << endl;
    cin >> size_str >> size_col;



    // Error
    //
    //
    if (size_str <= 0 || size_col <= 0) { cout << "Error! Your sizes of matrices is wrong for transposition!"; return -1;}



    // Initialization
    //
    //
    int** array = new int* [size_str]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i = 0; i < size_str; i++) {
        array[i] = new int[size_col]; // каждый из эл. есть массив из m элементов.
    }

    int** array_trnsp = new int*[size_col]; // "**" - обозначение двумерности
    // введение n памяти, но каждая - массив из-за "*"
    for (int i_tr = 0; i_tr < size_col; i_tr++) {
        array_trnsp[i_tr] = new int[size_str]; // каждый из эл. есть массив из m элементов.
    }

    initialization(array,size_str,size_col);
    cout << endl;

    cout << "Standard matrix is:" << endl;
    print_array(array,size_str,size_col);


    // To transpose
    //
    //
    transposition(array, array_trnsp, size_str, size_col);
    cout << "Transpose matrix is:" << endl;
    print_array(array_trnsp,size_col,size_str);

    return 0;
}
