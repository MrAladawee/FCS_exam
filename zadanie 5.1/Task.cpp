// Quick sort
#include <iostream>
#include <ctime>

using namespace std;

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int random() {
    return rand() % 90 + 10;
}

void rand_array(int* array, int N){
    for (int i = 0; i < N; i++) {
        array[i] = random();
    }
}

void quick_sort(int *a, int n) {
    int i = 0, j = n-1;
    int v = a[n >> 1]; //  ~  (n / 2)
    do {
        while (a[i] < v) i++;
        while (a[j] > v) j--;

        if (i <= j) {
            if (i  < j) {
                swap(a[i],a[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < n - 1) {
        quick_sort(a+i, n - i); // указатель А сдвигается на I; a[i] = *(a+i)
    }
    if (j > 0) {
        quick_sort(a, j + 1);
    }
}

int main() {
    srand(time(NULL));

    const int size = 10;
    int* array = new int[size];

    rand_array(array,size);
    print_array(array,size);

    quick_sort(array,size);
    print_array(array,size);

    return 0;
}
