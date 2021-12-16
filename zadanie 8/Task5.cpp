#include <iostream>
#include <ctime>
#include "m_funcs.h"
using namespace std;

void replace_element_from_min_to_max(int **array, const int size_str, const int size_col) {

    // First indexs of max element (1 str)
    //
    int max_el_s = 0;
    int max_el_c = 0;
    for (int col = 0; col < size_col; col++) {
        if (array[0][col] > array[max_el_s][max_el_c]) {max_el_s = 0; max_el_c = col;}
    }

    for (int str = 1; str < size_str; str++) {

        // Initialization indexs of min element and new max elem
        //
        int min_el_s = str;
        int min_el_c = 0;

        int new_max_el_s = str;
        int new_max_el_c = 0;

        // Search indexs of new minimal element
        //
        for (int col = 0; col < size_col; col++) {
            if (array[str][col] < array[min_el_s][min_el_c]) {min_el_s = str; min_el_c = col;}
        }

        // Replace min -> max
        //
        array[min_el_s][min_el_c] = array[max_el_s][max_el_c];

        // Search new max elem
        //
        for (int col = 0; col < size_col; col++) {
            if (array[str][col] > array[new_max_el_s][new_max_el_c]) {new_max_el_s = str; new_max_el_c = col;}
        }

        // Replace indexs of max element: old elem -> new elem
        //
        max_el_s = new_max_el_s;
        max_el_c = new_max_el_c;

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
    if (size_str <= 0 || size_col <= 0) { cout << "Error! Your size of matrix is wrong!"; return -1;}

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
    cout << "Your matrix is:" << endl;
    initialization(array,size_str,size_col);
    print_array(array, size_str, size_col);

    replace_element_from_min_to_max(array,size_str,size_col);

    cout << "New matrix is:" << endl;
    print_array(array, size_str, size_col);
    
    // Memory clear
    del_array(array,size_str,size_col);
}
