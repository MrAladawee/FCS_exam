
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <cstdio>

using namespace std;

int number12(int number) {

    int result = 0;

    for (int index = 0; index<3; index++){

        int c = number % 10;
        int b = pow(10,2-index) * c;

        result += b;
        number /= 10;

    }

    return result;
}

int number13(int number) {

    int result = 0;

    int last_number_new = number / 100;

    for (int index = 0; index < 2; index++) {

        int tmp = number % 10;
        int degree = pow(10,1+index) * tmp;

        result += degree;
        number /= 10;
    }
    result += last_number_new;
    return result;
}

int number24(int number) {

    int week = number / 7; // количество недель пройдено
    number -= week*7;
    return number;
}

int for35(int N) {

    int AK_3 = 1;
    int AK_2 = 2;
    int AK_1 = 3;

    for (int index = 4; index < N+1; index++) {
        int AK = AK_1 + AK_2 - 2 * AK_3;
        AK_3 = AK_2;
        AK_2 = AK_1;
        AK_1 = AK;
        cout << AK << " ";
    }
}

void case1(int &number) {

    switch (number) {

        case 7: cout << "Sunday!"; break;
        case 6: cout << "Saturday!"; break;
        case 5: cout << "Friday!"; break;
        case 4: cout << "Thursday!"; break;
        case 3: cout << "Wednesday!"; break;
        case 2: cout << "Thursday!"; break;
        case 1: cout << "Mondey!"; break;
        default: cout << "Error!"; break;

    }

}

double for36(int N, int K) {
    double sum = 0;
    double tmp = 1;
    for (int index = 1; index < N+1; index++) {

        tmp = double(index);

        for (int index_mltpl = 0; index_mltpl < K - 1; index_mltpl++) {
            tmp *= index;
        }

        sum += tmp;
    }

    return sum;
}

void for39(int A, int B) {

    for (int index = A; index < B+1; index++) {

        for (int index_2 = 0; index_2 < index; index_2++) {
            cout << index << " ";
        }

    }
}

void for40(int A, int B) {

    for (int index = A; index < B+1; index++) {

        for (int index_2 = 0; index_2 < index - A + 1; index_2++) {
            cout << index << " ";
        }

    }

}

void while12(int N) {

    int sum = 0;
    int tmp = 0;
    while (sum <= N) {
        sum += tmp;
        tmp += 1;
    }

    cout << sum- (tmp - 1) << endl;
    cout << tmp - 2;

}

void while15(int P) {

    int sum = 1000;
    int tmp = 1;
    int month = 0;
    while (sum < 1100) {
        tmp = sum*P/100;
        sum += tmp;
        month += 1;
    }

    cout <<  "Sum = " << sum << endl;
    cout << "Month = " << month << endl;
}

int while27(int N) {

    int fk2 = 1;
    int fk1 = 1;
    int fk = 2;
    int number = 2;
    while (fk != N) {

        fk = fk2 + fk1;
        fk2 = fk1;
        fk1 = fk;
        number++;
    }

    return number;
}

void while28(double E) {

    double a1 = 2;
    double ak = 2 + 1/a1;

    while (abs(ak - a1) >= E) {

        a1 = ak;
        ak = 2 + 1/a1;

    }

    cout << "|" << a1 << " - " << ak << "| = " << abs(ak-a1);

}

void while29(double E) {

    double a1 = 1;
    double a2 = 2;
    double ak = (a1 + 2*a2) / 3;

    while (E <= abs(ak - a2)) {

        a1 = a2;
        a2 = ak;
        ak = (a1 + 2*a2) / 3;

    }

    cout << a2 << " " << ak;

}

int while30(int A, int B, int C) {

    int count = 0;

    while (A - C > 0) {
        A -= C;
        count++;
    }

    if (B - C < 0) {
        cout << 0; return 0;
    }
    else {
        B -= C;
        while (B - C > 0) {
            B -= C;
            count += count;
        }
    }

    cout << count;
    return 1;
}

void series10(int N) {

    int i = 0;
    int number;
    int result_abs = 0;
    int result = 0;

    while (i < N) {
        cin >> number;
        result_abs += abs(number);
        result += number;
        i++;
    }

    if (result * (-1) == result_abs) { // If sum is negative
        cout << 0;
    }

    else if (result * (-1) == (-1) * result_abs) { // If sum is positive
        cout << 1;
    }

    else {cout << 1;} // If sum has positive number

}

int series23(int N) {

    int number_lft;
    int number;
    int number_rght;

    int flag = 0;

    cin >> number_lft;
    cin >> number;
    cin >> number_rght;

    if (number_lft > number) { //   \/\/\/\/\/\

        if (number_lft > number && number < number_rght) {

            int count = 0;

            while (count < N-3) {

                number_lft = number_rght;

                cin >> number;
                cin >> number_rght;
                count += 2;

                if (number_lft > number && number < number_rght) {

                    if (N-3 - count - 2 > 0) {
                        continue;
                    }

                    else if (N-3 - count - 2 == 0) {
                        number_lft = number_rght;
                        cin >> number;
                        cin >> number_rght;
                        count += 2;

                        if (number_lft > number && number < number_rght) {
                            cout << "Good"; return 0;
                        }

                        else {
                            cout << "BAD"; return -1;
                        }

                    }

                    else if (N-3 - count - 2 == -1) {

                        number_lft = number_rght;
                        cin >> number;
                        count++;

                        if (number_lft > number ) {
                            cout << "Good"; return 0;
                        }

                        else {
                            cout << "BAD"; return -1;
                        }

                    }

                }

                else {
                    cout << "BAD"; return -1;
                }

            }

        }

        else {
            cout << "BAD"; return -1;
        }


    }

    else if (number_lft < number) { //    /\/\/\/\/\

        if (number_lft < number && number > number_rght) {

            int count = 0;

            while (count < N-3) {

                number_lft = number_rght;

                cin >> number;
                cin >> number_rght;
                count += 2;

                if (number_lft < number && number > number_rght) {

                    if (N-3 - count - 2 > 0) {
                        continue;
                    }

                    else if (N-3 - count - 2 == 0) {
                        number_lft = number_rght;
                        cin >> number;
                        cin >> number_rght;
                        count += 2;

                        if (number_lft < number && number > number_rght) {
                            cout << "Good"; return 0;
                        }

                        else {
                            cout << "BAD"; return -1;
                        }

                    }

                    else if (N-3 - count - 2 == -1) {

                        number_lft = number_rght;
                        cin >> number;
                        count++;

                        if (number_lft < number ) {
                            cout << "Good"; return 0;
                        }

                        else {
                            cout << "BAD"; return -1;
                        }

                    }

                }

                else {
                    cout << "BAD"; return -1;
                }

            }

        }

        else {
            cout << "BAD"; return -1;
        }

    }

}

double proc1(double A) {

    double B;
    B = pow(A,3);

    return B;

}

int proc16(int X) {

    if (X > 0) {return 1;}
    else if (X == 0) {return 0;}
    else {return -1;}

}

double proc19(double R1, double R2) {

    const double Pi = 3.14;

    // R1 > R2

    return Pi * pow(R1,2) - Pi * pow(R2,2);

}

double proc20(double a, double h) {

    double b = sqrt( pow((a/2),2) + pow(h,2) );

    return b+b+a;

}

int proc21(int A, int B) {
    int sum = 0;

    if (A >= B) {return 0;}

    else {
        for (int i = A; i <= B; i++) {
            sum += i;
        }
    }

    return sum;
}

bool proc27(int K, int N) {

    if (K == 1) {return true;}

    else {
        if (K % N == 0) { return true; }

        else { return false; }
    }

}

int minmax16(int N) {

    int count = 0;
    int result_count = 0;

    int i = 0;
    int number;
    int glob_min = INT_MAX;

    while (i < N) {

        cin >> number;

        if (number < glob_min) {
            glob_min = number;
            result_count = count;
            count++;
            i++;
        }

        else {
            count++;
            i++;
        }

    }

    return result_count;

}

void minmax23(int N) {

    int max_of_all = INT_MIN;
    int max_medium = INT_MIN;
    int max_small = INT_MIN;

    int i = 0;
    int number;

    while (i < N) {

        cin >> number;

        if (number >= max_of_all) {
            max_small = max_medium;
            max_medium = max_of_all;
            max_of_all = number;
            i++;
        }

        else if (number >= max_medium) {
            max_small = max_medium;
            max_medium = number;
            i++;
        }

        else if (number >= max_small) {
            max_small = number;
            i++;
        }

        else {
            i++;
        }

    }

    cout << max_of_all << " " << max_medium << " " << max_small;

}
// ////////////////////////////////////////////
template <typename T>
void print_array(T* array, const int N) {

    for (int index = 0; index < N; index++ ) {

        cout << array[index] << " ";

    }
    cout << endl;
}
int random() {

    return rand()%15 + 1;

}
template <typename T>
void random_array(T* array, const int N) {

    for (int index = 0; index < N; index++) {

        array[index] = random();

    }

}
template <typename T>
void quick_sort(T *a, int n) {
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
void reversed(int *array, int N) {

    int* result_array = new int[N];

    for (int i = 0; i < N; i++) {
        result_array[i] = array[i];
    }

    for (int i = 0; i < N; i++) {
        array[i] = result_array[(N - 1) - i];
    }
}
int count_in_array(int* array, const int N, int number) {

    int count = 0;

    for (int index = 0; index < N; index++) {
        if (array[index] == number) count++;
    }

    return count;
}
void write_array(int* matrix, int*& matrix_result, int size_str) {

    for (int str = 0; str < size_str; str++) {
            matrix_result[str] = matrix[str];
        }

}


int array3(int* array, int N, int A, int D) {

    int* arithmetic_progressive = new int[N];

    arithmetic_progressive[0] = A;

    for (int index = 1; index < N; index++) {

        arithmetic_progressive[index] = A + index*D;

    }

    print_array(arithmetic_progressive,N);

}

int array7(int* array, const int N) {

    for (int index = 0; index < N; index++) {

        cout << array[N-1-index] << " ";

    }

}

void array10(int* array, const int N) {

    for (int index = 0; index < N; index++) {

        if (array[index] % 2 == 0) {

            cout << array[index] << " ";

        }

    }

    for (int index = 0; index < N; index++) {

        if (array[index] % 2 != 0) {

            cout << array[index] << " ";

        }

    }

}

int array17(int* array, const int N) {

    int count = 0; // счетчик выписанных значений для сравнения с N

    for (int index = 0; index < N; index++) {

        if ((index + 1) % 2 == 0) {
            if (N - count - 3 >= 0) {
                cout << array[index] << " " << array[(N - 1) - index + 1] << " " << array[(N - 1) - index] << " ";
                count += 3;
            }

            else if (N - count - 3 == -1) {
                cout << array[index] << " " << array[(N - 1) - index + 1] << " ";
                count += 2;
            }

            else if (N-count - 3 == -2) {
                cout << array[index] << " ";
                count++;
            }

            else if (N - count - 3 == -3) {
                return 0;
            }
        }


        else {

            if (N - count - 1 >= 0) {
                cout << array[index] << " ";
                count++;
            }

            else if (N - count - 1 == -1) {
                return 0;
            }

        }
    }

}

void array31(int* array, const int N) {
    int count = 0;

    for (int index = 0; index < N; index++) {

        if (array[N-1-index] > array[N-1-index-1]) {
            cout << N-1-index << " ";
            count++;
        }

    }

    cout << endl << count;
}

int array37(int* array, const int N) {
    int index = 0;
    int count = 0;
    int result = 0;

    while (index < N) {

        while (array[index] < array[index + 1]) {
            index++;
            count++;
        }
        if (count > 0) {
            result++;
            count = 0;
        }
        index++;
    }
    return result;
}

void array64(int* array_A, int* array_B, int* array_C, int Na, int Nb, int Nc) {
    int N = Na + Nb + Nc;
    int* result_array = new int[N];
    int count = 0;


    for (int index = 0; index < Na; index++) {
        result_array[index] = array_A[index];
    }

    for (int index = 0; index < Nb; index++) {
        result_array[index+Na] = array_B[index];
    }

    for(int index = 0; index < Nc; index++) {
        result_array[index+Na+Nb] = array_C[index];
    }

    quick_sort(result_array,N);
    reversed(result_array,N);
    print_array(result_array,N);

}

void array75(int* array, const int N) {

    int max_elem = 0;
    int min_elem = 0;

    // Find max elem & min elem
    for (int index = 0; index < N; index++) {

        if (array[index] > array[max_elem]) {max_elem = index;}
        else if (array[index] < array[min_elem]) {min_elem = index;}

    }

    int d = max(min_elem,max_elem);
    int b = min(min_elem,max_elem);

    for (int index = b; index < ceil(((double)(d - b) / 2)); index++) {
        swap(array[index],array[d - index]);
    }

    print_array(array,N);
}

void array98(int *&A, int &N)
{
    int c = 0;
    for (int i = 0; i < N; i++) {
        int k = count_in_array(A, N, A[i]);
        if (k < 3)A[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) c++;
    }
    int* mas1 = new int[c];
    int d = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            mas1[d] = A[i];
            d++;
        }
    }
    delete[] A;
    N = c;
    A = mas1;

}

int array106(int *&array, int &N) {

    int c = N + N / 2;
    int d = 0;
    int* mas1 = new int[c];
    for (int i = 0; i < N; i++)
    {

        mas1[d] = array[i];
        if(i % 2 == 1) {
            d++;
            mas1[d ] = array[i];

        }
        d++;
    }
    delete[] array;
    N = c;
    array = mas1;
}

// ////////////////////////////////////////////////
void print_matrix(int **matrix, const int size_str, const int size_col) {
    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            cout << matrix[str][col] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void initialization_random(int **matrix, const int size_str, const int size_col) {
    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            matrix[str][col] = random();
        }
    }
}

void matrix1(int** matrix, const int size_str, const int size_col) {

    for (int m = 0; m < size_str; m++) {
        for (int n = 0; n < size_col; n++) {
            matrix[m][n] = 10*(n+1);
        }
    }

}

void matrix29(int** matrix, const int size_str, const int size_col) {

    for (int m = 0; m < size_str; m++) {
        double mean;
        double sum = 0;
        int count = 0;

        for (int n = 0; n < size_col; n++) {

            sum += matrix[m][n];

        }

        mean = sum / size_col;

        for (int n = 0; n < size_col; n++) {

            if (matrix[m][n] < mean) {
                count++;
            }

        }

        cout << m << " string has " << count << " numbers, which smaller than " << mean << endl;

    }

}

int matrix37(int** matrix, const int size_str, const int size_col) {

    int count = 0;

    int* tmp_array = new int[size_str];
    int* static_array = new int[size_str];

    for (int i = 0; i < size_str; i++) {
        static_array[i] = matrix[i][size_col-1];
    }

    quick_sort(static_array,size_str);

    for (int col = 0; col < size_col-1; col++) {
        for (int i = 0; i < size_str; i++) {
            tmp_array[i] = matrix[i][col];
        }

        quick_sort(tmp_array,size_str);

        int flag = 0;
        for (int index = 0; index < size_str; index++) {
            if (tmp_array[index] != static_array[index]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            count++;
        }
    }

    return count;
}

void matrix57(int** matrix, const int size_str, const int size_col) {

    int tmp;

    for (int str = 0; str < size_str/2; str++) {
        for (int col = 0; col < size_col/2; col++) {

            tmp = matrix[str][col];
            matrix[str][col] = matrix[size_str - 1 - str][size_col - 1 - col];
            matrix[size_str - 1 - str][size_col - 1 - col] = tmp;

        }
    }

}
void matrix57_true(int** matrix, const int str, const int col) {
    for (int i = 0; i < str / 2; i++) {
        for (int j = 0; j < col / 2; j++) {
            for (int a = str-1; a >= str / 2; a--) {
                for (int s = col-1; s >= col / 2; s--) {
                    int x = matrix[i][j];
                    matrix[i][j] = matrix[a][s];
                    matrix[a][s] = x;
                }
            }
        }
    }

}

void matrix66(int** matrix, int** &matrix_result, int size_str, int size_col, int size_col_result) {

    // Searching col with only negative numbers
    //
    int flag = 0;
    int flag_col = -1;
    for (int col = 0; col < size_col; col++) {

        flag = 0;

        for (int str = 0; str < size_str; str++) {

            if (matrix[str][col] >= 0) {
                flag = 1;
                break;
            }

        }

        if (flag == 1) {continue;}
        else {flag_col = col;}

    }

    // Rewriting matrix
    //
    if (flag_col != -1) {

        for (int str = 0; str < size_str; str++) {

            for (int col = 0; col < flag_col; col++) {

                matrix_result[str][col] = matrix[str][col];

            }

            for (int col = flag_col + 1; col < size_col; col++) {
                matrix_result[str][col-1] = matrix[str][col];
            }

        }

        print_matrix(matrix_result,size_str,size_col_result);

    }

    else { print_matrix(matrix, size_str, size_col); }

}

void matrix75(int** matrix, int** &matrix_result, int size_str, int size_col) {

    // Look at angle
    //
    if (matrix[0][0] > matrix[1][0] && matrix[0][0] > matrix[0][1] && matrix[0][0] > matrix[1][1]) { matrix_result[0][0] = -1 * matrix[0][0]; }
    if (matrix[0][size_col] > matrix[0][size_col-1] && matrix[0][size_col] > matrix[1][size_col] && matrix[0][size_col] > matrix[1][size_col-1]) { matrix_result[0][size_col] = -1 * matrix[0][size_col]; }
    if (matrix[size_str][0] > matrix[size_str][1] && matrix[size_str][0] > matrix[size_str-1][0] && matrix[size_str][0] > matrix[size_str-1][1]) { matrix_result[size_str][0] = -1 * matrix[size_str][0]; }
    if (matrix[size_str][size_col] > matrix[size_str][size_col-1] && matrix[size_str][size_col] > matrix[size_str-1][size_col] && matrix[size_str][size_col] > matrix[size_str-1][size_col-1]) { matrix_result[size_str][size_col] = -1 * matrix[size_str][size_col]; }

    // Look at str up and down
    //
    for (int col = 1; col < size_col-1; col++) {

        if (matrix[0][col] > matrix[0][col - 1] && matrix[0][col] > matrix[1][col - 1] && matrix[0][col] > matrix[1][col] && matrix[0][col] > matrix[1][col+1] && matrix[0][col] > matrix[0][col+1]) {
            matrix_result[0][col] = -1*matrix[0][col];
        }

    }

    for (int col = 1; col < size_col-1; col++) {

        if (matrix[size_str][col] > matrix[size_str][col - 1] && matrix[size_str][col] > matrix[size_str - 1][col - 1] && matrix[size_str][col] > matrix[size_str - 1][col] && matrix[size_str][col] > matrix[size_str - 1][col+1] && matrix[size_str][col] > matrix[size_str][col+1]) {
            matrix_result[size_str][col] = -1*matrix[size_str][col];
        }

    }

    // Look at left and right col
    //
    for (int str = 1; str < size_str - 1; str++) {
        if (matrix[str][0] > matrix[str - 1][0] && matrix[str][0] > matrix[str - 1][1] && matrix[str][0] > matrix[str][1] && matrix[str][0] > matrix[str+1][1] && matrix[str][0] > matrix[str+1][0]) {
            matrix_result[str][0] = -1*matrix[str][0];
        }
    }

    for (int str = 1; str < size_str - 1; str++) {
        if (matrix[str][size_col] > matrix[str - 1][size_col] && matrix[str][size_col] > matrix[str - 1][size_col - 1] && matrix[str][size_col] > matrix[str][size_col - 1] && matrix[str][size_col] > matrix[str+1][size_col - 1] && matrix[str][size_col] > matrix[str+1][size_col]) {
            matrix_result[str][size_col] = -1*matrix[str][size_col];
        }
    }

    // Look at centre
    //
    for (int str = 1; str < size_str - 1; str++) {
        for (int col = 1; col < size_col - 1; col++) {

            if (matrix[str][col] > matrix[str-1][col-1] && matrix[str][col] > matrix[str-1][col] && matrix[str][col] > matrix[str-1][col+1]) {
                if (matrix[str][col] > matrix[str+1][col-1] && matrix[str][col] > matrix[str+1][col] && matrix[str][col] > matrix[str+1][col+1]) {
                    if (matrix[str][col] > matrix[str][col-1] && matrix[str][col] > matrix[str][col+1]) {
                        matrix_result[str][col] = -1*matrix[str][col];
                    }
                }
            }

        }
    }

}

void matrix98(int**& matrix, const int size_str, int size_col) {

    int tmp;

    for (int str = 0; str < size_str / 2; str++) {
        for (int col = 0; col < size_col; col++) {

            tmp = matrix[str][col];
            matrix[str][col] = matrix[size_str - 1 - str][size_col - 1 - col];
            matrix[size_str - 1 - str][size_col - 1 - col] = tmp;

        }
    }

    print_matrix(matrix,size_str,size_col);

}

int string1(char x) {
    int a;
    a = x;
    return a;
}

char string2(int N) {

    return char(N);

}

void string3(char C) {

    cout << char(int(C) - 1) << " " <<  char(int(C) + 1);

}

void string4(int N) {

    int current = 0;

    while (current < N) {
        cout << char(65+current) << " ";
        current++;
    }


}

void string7(string str) {

    cout << int(str[0]) << " " << int(str[str.size() - 1]);

}

void string8(int N, char W) {

    string result;

    int current = 0;

    while (current < N) {
        result += W;
        current++;
    }
    cout << result;
}

string string9(int N, char C1, char C2) {

    int current = 0;
    string result;


    while (current < N) {
        if (current % 2 == 0) result += C1;
        else result += C2;
        current++;
    }
    return result;
}

string string10(string str) {

    string result;

    int current = 0;

    while (current < str.size()) {

        result += str[str.size()-current-1];
        current++;
    }
    return result;
}

int string13(string str) {

    int count = 0;

    for (int i = 0; i < str.size(); i++) {
        if (48 <= int(str[i]) && int(str[i]) <= 57) count++;
    }

    return count;
}

string string18(string str) {

    string result;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] > 90) result += char(int(str[i])-32);
        else result += char(int(str[i])+32);
    }
    return result;
}

int string22(string str) {

    int result = 0;

    for (int i = 0; i < str.size(); i++) {
        result += int(str[i]) - 48;
    }

    return result;
}

void string24(string str) {

    string binary;

    int number;

    for (int i = 0; i < str.size(); i++) {

        number += (int(str[i]) - 48) * pow(10,str.size() - 1 - i);

    }

    while (number > 0) {
        binary += char(number%2 + 48);
        number /= 2;
    }

    reverse(binary.begin(), binary.end()); // #include <algorithm>
    cout << binary;
}

bool check_str(string str1, string str2) {
    int flag = 0;

    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {return false;}
    else return true;
}
void string31(string str, string str0) {

    int flag = 0;
    string tmp;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == str0[0]) {

            for (int j = i; j < str.size(); j++) {
                tmp += str[j];
                if (tmp.size() == str0.size()) {

                    if (check_str(tmp, str0) == true) {
                        flag = 1;
                        break;
                    }

                }

            }

        }

    }

    if (flag == 1) {
        cout << "Good";
    }
    else cout << "Bad";

}

void string37(string str, string str1, string str2) {
    string tmp;
    string result;
    int index = 0;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == str1[0]) {

            for (int j = i; j < str.size(); j++) {
                tmp += str[j];
                if (tmp.size() == str1.size()) {

                    if (check_str(tmp, str1) == true) {
                        tmp = "";
                        index = j + 1 - tmp.size();
                        break;
                    }
                }

            }

        }

    }

    for (int i = 0; i < index - 1; i++) {
        result += str[i];
    }
    result += str2;

    for (int i = index; i < str.size(); i++) {
        result += str[i];
    }
    cout << result;
}

bool check_word_A(string str) {

    int count = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'A' || str[i] == 'a') count++;
    }

    if (count == 3) return true;
    else return false;
}
void string44(string str) {

    int count = 0;
    string tmp;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            tmp += str[i];
        }
        else {
            if (tmp != "") {
                if (check_word_A(tmp)) count++;
                tmp = "";
            }
            else continue;
        }
    }
    cout << count;
}

string rewrite48(string str, char word) {

    string result;
    int index = 0; int flag = 0;
    for(int i = 0; i < str.size(); i++){
        if (str[i] == word && flag == 0) {
            index = i;
            flag = 1;
        }
    }

    for (int i = 0; i < str.size(); i++) {

        if (str[i] != word) {
            result += str[i];
        }
        else {
            if (index == i) {
                result += str[i];
            }

            else result += ".";

        }

    }
    return result;
}
void string48(string str, char word) {

    string tmp;
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            tmp += str[i];
        }
        else {
            if (tmp != "") {
                result += rewrite48(tmp, word);
                result += " ";
            }
            else result += " ";
            tmp = "";
        }
    }
    if (tmp != "") {
        result += rewrite48(tmp, word);
    }
    cout << result;
}

string rewrite52(string str) {

    if (int(str[0] < 97 || int(str[0]) > 122)) {
        return str;
    }

    else {
        str[0] = char(int(str[0]) - 32);
    }
    return str;
}
void string52(string str) {

    string tmp;
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            tmp += str[i];
        }
        else {
            if (tmp != "") {
                result += rewrite52(tmp);
                result += " ";
            }
            else result += " ";
            tmp = "";
        }
    }
    if (tmp != "") {
        result += rewrite52(tmp);
        result += " ";
    }
    cout << result;
}

void string64(string &s, int k) {

    /*
    for (int i = 0; i < str.size(); i++) {

        str[i] = char(int(str[i]) +  K);

    }
    cout << str;
     */

    while (k--) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > char(224) && s[i] <= char(255))
                s[i] = char(int(s[i]) - 1);
            else if (s[i] > char(192) && s[i] <= char(223))
                s[i] = char(int(s[i]) - 1);
            else if (s[i] == char(224))
                s[i] = 'я';
            else if (s[i] == char(192))
                s[i] = 'Я';
        }
    }
    cout << s;
}

int string69(string str) {

    int count_open = 0;
    int count_close = 0;

    int count = 0;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            count_open++; count++;
        }

        else if (str[i] == ')') {
            count_close++; count--;
            if (count_close > count_open) {return i+1;}
        }

    }

    if (count != 0) { return -1;}
    else if (count == 0) {return 0;}

}

bool file1(string s) {

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '\\' || s[i] == '/' || s[i] == ':' || s[i] == '*' || s[i] == '?' || s[i] == '<' || s[i] == '>' || s[i] == '|') {
            return false;
        }

    }
    s += ".txt";
    ofstream fout(s);
    return true;
}

int file4(string s1, string s2, string s3, string s4) {

    int count = 0;

    ifstream fout1(s1);
    ifstream fout2(s2);
    ifstream fout3(s3);
    ifstream fout4(s4);

    if (fout1.is_open()) { count++; }
    if (fout2.is_open()) { count++; }
    if (fout3.is_open()) { count++; }
    if (fout4.is_open()) { count++; }

    return count;
}

int file5(string s) {
    string tmp;
    int count = 0;

    ifstream fin(s);

    if (!fin.is_open()) {
        return -1;
    }

    while (!fin.eof()) {
        getline(fin,tmp);
    }

    return tmp.size();
}

void file7(string s) {

    ifstream fin(s);
    string a;
    int count = 0;
    int current = 0;

    if (!fin.is_open()) {
        cout << "Error!";
    }

    while (!fin.eof()) {
        fin >> a;
        count++;
    }
    fin.seekg(0, ios_base::beg);

    while(!fin.eof()) {
        fin >> a;
        current++;
        if (current == 1 || current == 2 || current == count - 1 || current == count) {
            cout << a << " ";
        }
    }

}

string reverse_str(string s) {

    string result;
    string tmp;

    for (int i = s.size() - 1; i > -1; i--) {

        if (s[i] != ' ') {
            tmp += s[i];
        }

        else {
            reverse(tmp.begin(), tmp.end());
            result += tmp + " ";
            tmp = "";
        }

    }

    reverse(tmp.begin(), tmp.end());
    result += tmp;
    return result;
}
int file13(string s) {

    ifstream fin(s);
    ofstream fout1("even.txt");
    ofstream fout2("odd.txt");

    if (!fin.is_open()) {
        cout << "Error";
        return -1;
    }

    string even;
    string odd;
    string current;

    while (!fin.eof()) {

        fin >> current;
        if (stoi(current) % 2 == 0) {
            even += current + " ";
        }

        else {
            odd += current + " ";
        }

    }

    even.pop_back(); // delete last symbol
    odd.pop_back();

    fout1 << reverse_str(even); // reverse string
    fout2 << reverse_str(odd);

    return 1;

}

int sumotorial(int N) {

    int result = 0;

    for (int i = 1; i < N+1; i++) {
        result += i;
    }
    return result;
}
int file16(string s) {

    ifstream fin(s);
    int tmp = 1;
    int result = 0;
    string tmp_str;
    string seris;

    if (!fin.is_open()) {
        cout << "Error!";
        exit(-1);
    }

    fin >> seris;

    while (!fin.eof()) {

        fin >> tmp_str;
        if (tmp_str == seris) {
            tmp++;
        }

        else {
            result += sumotorial(tmp - 1);
            seris = tmp_str;
            tmp = 1;
        }

    }

    return result;

}

void file24(string s) {

    ifstream fin(s);
    ofstream fout("pizdec.txt");

    if (!fin.is_open()) {
        cout << "Error!";
        exit(-1);
    }

    int tmp;
    int previous;
    string tmp_str;

    fin >> tmp_str;
    previous = stoi(tmp_str);

    int lenght_up = 1;
    int lenght_down = 1;

    while (!fin.eof()) {

        fin >> tmp_str;
        tmp = stoi(tmp_str);

        if (previous < tmp) {
            if (lenght_down != 1) {
                fout << lenght_down << " ";
                lenght_down = 1;
            }
            lenght_up++;
            previous = tmp;
        }

        else if (previous > tmp) {
            if (lenght_up != 1) {
                fout << lenght_up << " ";
                lenght_up = 1;
            }
            lenght_down++;
            previous = tmp;
        }

        else if (previous = tmp) {
            if (lenght_up != 1) {
                fout << lenght_up << " ";
                lenght_up = 1;
            }
            if (lenght_down != 1) {
                fout << lenght_down << " ";
                lenght_down = 1;
            }
            previous = tmp;
        }
    }

    if (lenght_down != 1) {
        fout << lenght_down << " ";
        lenght_down = 1;
    }

    if (lenght_up != 1) {
        fout << lenght_up << " ";
        lenght_up = 1;
    }

}

int file25(string s) {

    ifstream fin(s);

    if (!fin.is_open()) {
        cout << "Error";
        return -1;
    }

    string tmp;
    string result;

    while (!fin.eof()) {
        int k;
        fin >> tmp;
        k = stoi(tmp);
        k = k * k;
        result += to_string(k) + " ";
    }

    fin.close();

    ofstream ofs;
    ofs.open(s, ofstream::out | ofstream::trunc);
    ofs.close();

    ofstream fout1(s);

    if (!fout1.is_open()) {
        cout << "Error";
        return -1;
    }

    fout1 << result;
    fout1.close();
    return 1;

}


double arithmetic_mean(double* array, const int N) {

    double sum = 0;

    for (int i = 0; i < N + 1; i++) {
        sum += array[i];
    }

    return sum/(N+1);
}
void param5(double* &array, const int N) {

    double sum;
    double result;

    for (int i = 0; i < N; i++) {

        array[i] = arithmetic_mean(array,i);

    }

    print_array(array,N);
}

void param10(int* array, const int size_array, int number) {

    int count_dubl = 0;

    // Initialization array temp
    //
    int* array_tmp = new int[2*size_array];

    for (int index = 0; index < 2 * size_array; index++) {
        if (index < size_array) {
            array_tmp[index] = array[index];
        }
        else array_tmp[index] = INT_MIN;
    }

    // Rewrite with duplication element
    //
    for (int index = 0; index < size_array * 2; index++) {

        if (array_tmp[index] == number) {
            int tmp = array_tmp[index+1];
            for (int index_temp = index + 1; index_temp < 2 * size_array - 1; index_temp++) {
                if (array_tmp[index_temp] != INT_MIN) {
                    int tmp_new = array_tmp[index_temp + 1];
                    array_tmp[index_temp + 1] = tmp;
                    tmp = tmp_new;
                }
            }

            array_tmp[index+1] = array_tmp[index];
            index++;
            count_dubl += 1;

        }

    }

    array = array_tmp;
    print_array(array,size_array + count_dubl);

}

void param13(int* array, int N) {

    print_array(array,N);

    int* result_array = new int[N];

    int count = 0; // count of elements, which has rewritten.
    int minimal = INT_MAX;
    int index_minimal = 0;
    int index_left = 0;
    int index_right = 0;

    for (int counter = 0; counter < N; counter++) {

        // search min
        //
        for (int index = 0; index < N; index++) {
            if (array[index] < minimal && array[index] != INT_MIN) {
                minimal = array[index];
                index_minimal = index;
            }
        }

        array[index_minimal] = INT_MIN;
        if (minimal != INT_MAX) {

            count++;

            if (count % 2 != 0) {
                result_array[index_left] = minimal;
                index_left++;
            }

            else {
                result_array[N - index_right - 1] = minimal;
                index_right++;
            }

        }

        minimal = INT_MAX;
    }

    print_array(result_array,N);
}

void rewrite_col_in_matrix(int** &array, const int size_str, const int size_col, const int col1, const int col2) {

    // A E I M O        A O I M E
    // B F J N Q   ->   B Q J N F
    // C G K F R        C R K F G
    // D H L P S        D S L P H
    //
    // 2 col <-> 5 col
    //

    int tmp;

    for (int str = 0; str < size_str; str++) {

        tmp = array[str][col1];
        array[str][col1] = array[str][col2];
        array[str][col2] = tmp;

    }

}
void param29(int** &matrix, const int size_str, const int size_col) {

    int flag_rewrite = 0;

    while (flag_rewrite != 1) {

        int flag_const = 0;

        for (int col1 = 0; col1 < size_col - 1; col1++) {
            int flag = 0;
            for (int col2 = col1 + 1; col2 < size_col; col2++) {

                // Compare
                //
                for (int str = 0; str < size_str; str++) {

                    if (matrix[str][col1] > matrix[str][col2]) {

                        rewrite_col_in_matrix(matrix, size_str, size_col, col1, col2);
                        flag = 1;
                        break;

                    } else if (matrix[str][col1] == matrix[str][col2]) {
                        continue;
                    }
                    else {
                        break;
                    }

                }

                if (flag == 1) {
                    flag = 0;
                    flag_const = 1;
                    break;
                }

            }

        }

        if (flag_const == 0) flag_rewrite = 1;
    }
}

string param31(string s, int N) {

    string result;

    while (result.size() < N) {
        result += s;
    }

    while (result.size() != N) {
        result.pop_back();
    }

    return result;
}

string param36(string s, int K, int N) {

    string result;

    if (K > s.size()) {
        return "";
    }


    else if (s.size() < K+N) {

        for (int index = 0; index < s.size(); index++) {

            if (index >= K - 1) {
                result += s[index];
            }

        }

    }

    else {
        for (int index = 0; index < s.size(); index++) {

            if (index >= K - 1 && result.size() <= N - 1) {
                result += s[index];
            }

        }
    }

    reverse(result.begin(), result.end());

    return result;

}

string param42(string s) {

    string tmp;
    tmp += s[0];
    string result;
    int count = 1;

    for (int index = 1; index < s.size(); index++) {

        if (s[index] == tmp[0]) {
            tmp += s[index];
            count++;
        }

        else {

            if (count > 4) {
                result += tmp[0];
                result += '{';
                result += to_string(count);
                result += '}';
                tmp = s[index];
                count = 1;
            }

            else if (count <= 4) {
                result += tmp;
                tmp = s[index];
                count = 1;
            }

        }
    }

    if (count > 4) {
        result += tmp[0];
        result += '{';
        result += to_string(count);
        result += '}';
    }

    else if (count <= 3) {
        result += tmp;
    }
    return result;
}

int param49(string s) {

    ifstream fin(s);

    if (!fin.is_open()) {
        return -1;
    }

    string tmp;
    int count = 0;

    while (!fin.eof()) {

        getline(fin,tmp);

        if (tmp.size() > 0 || tmp == "\0") {
            count++;
        }
    }
    return count;
}

void recieve_matrix_from_file(int** &matrix, const int size_str, const int size_col, string file) {

    ifstream fin(file);

    if (!fin.is_open()) {
        cout << "Error!" << endl;
        exit(-1);
    }

    int str = 0;
    string line;

    while(!fin.eof()) {

        string tmp;
        int col = 0;

        getline(fin,line);

        for (int index = 0; index < line.size(); index++) {

            if (line[index] != ' ') {
                tmp += line[index];
            }

            else {
                matrix[str][col] = stoi(tmp);
                tmp = "";
                col++;
            }

        }

        if (tmp.size() > 0) matrix[str][size_col-1] = stoi(tmp);

        str++;
    }

    print_matrix(matrix,size_str,size_col);
}

unsigned long int recur1(unsigned long int N) {

    if (N == 0 || N == 1) {
        return 1;
    }

    return N * recur1(N-1);
}

double recur3(int X, int N) {

    if (N == 0) {
        return 1;
    }

    else if (N > 0 && N % 2 == 0) {
        return pow(recur3(X,N/2),2);
    }

    else if (N > 0 && N % 2 != 0) {
        return X*recur3(X,N-1);
    }

    else if (N < 0) {
        return 1/pow(X,-N);
    }

}

int recur4(int N) {

    if (N == 1 || N == 2) {
        return 1;
    }
    return recur4(N-1) + recur4(N-2);
}

int recur6(int N, int K) {

    if (N == K  || K == 0) { return 1; }

    else if (N > 0 && K > 0 && N > K) { return recur6(N-1,K) + recur6(N-1,K-1); }

}

bool recur13(string s) {

    // Basic comparison
    //
    if (s[0] != s[s.size() - 1]) {
        return false;
    }

    // Exceptions
    //
    if (s.size() == 1) return true;
    else if (s.size() == 2) { return s[0] == s[1]; }

    // Calling yourself
    //
    else if (s.size() > 2) {
        s.erase(0, 1);
        s.pop_back();
        return recur13(s);
    }

}

// Write binary file
void binaryfile1(string s) {

    int n = 3; // количество вещественных чисел
    int i; // счетчик вещественных чисел
    int a;

    ofstream f("noobs.dat",ios_base::binary);

    f.write((char*) &n,sizeof(n));

    for (i = 0; i < n; i++) {
        cin >> a;
        f.write((char*) &a, sizeof(a));
    }

    f.close();

}

// Read binary file through for
void binaryfile2(string s) {
    int n = 3;
    int tmp;
    int i; // счетчик вещественных чисел


    ifstream f("noobs.dat",ios_base::binary);

    f.read((char*) &tmp,sizeof(tmp));
    cout << tmp << endl;

    for (i = 0; i < n; i++) {

        f.read((char*)&tmp, sizeof(tmp));

        if (!f.fail()) {
            cout << tmp << " ";
        }

    }

    f.close();

}

// Read binary file through while
void binaryfile3(string s) {

    int tmp;

    ifstream f("noobs.dat",ios_base::binary);

    while (!f.eof()) {

        f.read((char*) &tmp, sizeof(tmp));

        if (!f.fail()) {

            cout << tmp << " ";

        }
    }

    f.close();

}

struct building {

    int cost;
    int area;
    char nameStreet[128];
    int count_of_room;
    int prof_owner;
    int count_of_shop;
    char shop[256];

};
void struct_from_binary(string s);

// Write and read struct
void struct1() {

    building apartament1;
    building apartament2;

    ofstream f("noob.dat", ios_base::binary);

    cin >> apartament1.cost;
    f.write((char*) &apartament1.cost, sizeof(apartament1.cost));

    cin >> apartament1.area;
    f.write((char*) &apartament1.area, sizeof(apartament1.area));

    cin >> apartament1.nameStreet;
    f.write((char*) &apartament1.nameStreet, sizeof(apartament1.nameStreet));

    cin >> apartament1.count_of_room;
    f.write((char*) &apartament1.count_of_room, sizeof(apartament1.count_of_room));

    char prof_owner[4];
    cin >> prof_owner;
    if (prof_owner[0] == 'Y') {
        apartament1.prof_owner = 1;
        f.write((char*) &apartament1.prof_owner, sizeof(apartament1.prof_owner));
    }
    else {
        apartament1.prof_owner = 0;
        f.write((char*) &apartament1.prof_owner, sizeof(apartament1.prof_owner));
    }

    cin >> apartament1.count_of_shop;
    f.write((char*) &apartament1.count_of_shop, sizeof(apartament1.count_of_shop));

    cin >> apartament1.shop;
    f.write((char*) &apartament1.shop, sizeof(apartament1.shop));
    f.close();

    ifstream f1("noobs.dat",ios_base::binary);
    f1.read((char*) &apartament2, sizeof(apartament2));

    f1.close();

    cout << apartament2.cost << " ";
    cout << apartament2.nameStreet;

}

// Read from file
void struct2() {
    building apartament2;

    ifstream f1("noobs.dat",ios_base::binary);
    f1.read((char*) &apartament2, sizeof(apartament2));

    f1.close();

    cout << apartament2.cost << " ";
    cout << apartament2.nameStreet;
    // https://pro-prof.com/forums/topic/чтение-и-запись-строки-с-бинарного-фай
}


int main()
{

    struct2();

}