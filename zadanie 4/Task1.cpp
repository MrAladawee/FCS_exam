#include <iostream>

using namespace std;

void print_array(int array[], const int size) {
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
}

int main() {

    // Progression declaration
    int a1, d;
    cout << "Enter the first variable of the progression and the difference : ";
    cin >> a1 >> d;
    cout << endl;

    // Array size declaration
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    cout << endl;

    if (size <= 0) {
        cout << "Error! You've written incorrect size of array!";
        return -1;
    }

    // Array declaration
    int* array = new int[size];
    array[0] = a1;

    for (int index = 1; index < size; index++) {
        array[index] = array[index-1] + d;
    }

    cout << "Array with progression: ";
    print_array(array, size);

    return 0;
}
