// Составление массива из рандомных значений,
// Где используются все значения из [1...N]

#include <iostream>
#include <ctime>

using namespace std;

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

void print_array(int array[], const int size) {
    for (int index = 0; index < size; index++){
        cout << array[index] << " ";
    }
}


int main() {
    srand(time(NULL));

    // Size declaration
    int N;
    cout << "Enter the size of the array : ";
    cin >> N;
    cout << endl;

    if (N <= 0) {
        cout << "Error! You've written incorrect size of the array!";
        return -1;
    }

    // Array declaration
    int* array = new int[N];

    for (int index = 0; index < N; index++){
        array[index] = 0;
    }

    int flag = 1;

    while ((summa(N) != summa_array(array,N) && flag == 1) || (summa(N) == summa_array(array,N) && flag == 1)) {
        for (int index = 0; index < N; index++) {
            array[index] = random(N);
        }

        flag = 0; // flag for duplicate variable
                  // 0 - there are no such variables
                  // 1 - there are such variables

        for (int i = 0; i < N-1; i++){
            for (int j = i+1; j < N; j++){
                if (array[i] == array[j]){
                    flag = 1;
                }
            }
        }
    }
    print_array(array,N);

    return 0;
}
