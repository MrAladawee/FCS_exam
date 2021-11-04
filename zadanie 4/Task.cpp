#include <iostream>
#include <ctime>
using namespace std;

void print_array(int array[], const int size) {
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
    cout << endl << endl;
}

void arythmetic_progressive(int* array, int size, int a1, int d) {
    array[0] = a1;

    for (int index = 1; index < size; index++) {
        array[index] = array[index-1] + d;
    }
}

int random(int N) {
    return rand()%(N) + 1;
}

int summa(int number) {
    return ((1+number)/2)*number; // Формула суммы ариф. прогрессии.
}

int summa_array(int array[], const int size) {
    int result = 0;
    for (int index = 0; index < size; index++){
        result += array[index];
    }
    return result;
}

void random_array(int* array, int size) {

    for (int index = 0; index < size; index++){
        array[index] = 0;
    }

    int flag = 1;

    while ((summa(size) != summa_array(array,size) && flag == 1) || (summa(size) == summa_array(array,size) && flag == 1)) {
        for (int index = 0; index < size; index++) {
            array[index] = random(size);
        }

        flag = 0; // flag for duplicate variable
        // 0 - there are no such variables
        // 1 - there are such variables

        for (int i = 0; i < size-1; i++){
            for (int j = i+1; j < size; j++){
                if (array[i] == array[j]){
                    flag = 1;
                }
            }
        }
    }
}

int random_2_type() {
    return rand()%(2000 - 1000 + 1) + 1000;
}

int find_good_n(int* array, int size){
    int result = 0;
    for (int index = 0; index < size; index++){
        if (((array[index])/10)%10 % 2 == 0){
            result += 1;
        }
    }
    return result;
}

void random_array_2_type(int* array, int size){
    for (int index = 0; index < size; index++){
        array[index] = random_2_type();
    }
}

int main() {

    srand(time(NULL));

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
        cout << "Error! You've written incorrect size of array! Please, rewrite number > 0!";

        cout << endl;

        return -1;
    }

    // Array declaration
    int* array = new int[size];

    // Task 1: Arythmetic Progressive.
    cout << "Array with progression:" << endl;
    arythmetic_progressive(array, size, a1, d);
    print_array(array, size);

    // Task 2: Create array with random numbers
    random_array(array, size);
    cout << "Random array, where all numbers from 1 to N:" << endl;
    print_array(array, size);

    // Task3: Create array with numbers [1000; 2000] and search good elements
    cout << "Random array, where numbers from 1000 to 2000:" << endl;
    random_array_2_type(array, size);
    print_array(array, size);
    cout << "Number of correct elements is ";
    cout << find_good_n(array,size);

    cout << endl;

    return 0;
}
