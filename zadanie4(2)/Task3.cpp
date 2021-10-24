#include <iostream>
#include <ctime>

using namespace std;

int random() {
    return rand()%(2000 - 1000 + 1) + 1000;
}

void print_array(int array[], const int size) {
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
}


int main() {
    srand(time(NULL));

    int result = 0;

    // Size declaration
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;
    cout << endl;

    if (size <= 0) {
        cout << "Error! You've written incorrect size of the array!";
        return -1;
    }

    // Array declaration
    int* array = new int[size];

    for (int index = 0; index < size; index++){
        array[index] = random();
    }

    for (int index = 0; index < size; index++){
        if (((array[index])/10)%10 % 2 == 0){
            result += 1;
        }
    }

    cout << "Array: ";
    print_array(array,size);
    cout << endl;

    cout << "Number of correct elements is ";
    cout << result;

    return 0;
}
