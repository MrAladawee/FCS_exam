#include <iostream>
#include <fstream>

using namespace std;

// Task 1 - Дана матрица MxN . Найти кол-во столбов, элементы которого по убыванию

void del_matrix(int** &matrix, const int size_str) {
    for (int i = 0; i < size_str; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int random() {
    return rand()%15 + 1;
}
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
void write_matrix_in_file(int** matrix, const int &size_str, const int &size_col) {

    ofstream fout("task1.txt");

    if (!fout.is_open()) {
        cout << "error";
        exit(-1);
    }

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {

            fout << matrix[str][col] << " ";

        }
        fout << "\n";
    }
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
// //////////////////////////

int search_k(int** mas, int size_str, int size_col) {
    int k = 0; int m = 0;
    for (int i = 0; i < size_col; i++) {
        m = 0;
        for (int j = 0; j < size_str-1; j++) {
            if (mas[j][i] >= mas[j+1][i]) {
                m += 1;
            }
        }
        if (m == size_str-1)k += 1;
    }
    return k;
}

void task1() {

    int size_str = 3;
    int size_col = 4;

    int** matrix_start = new int* [size_str];
    for (int i = 0; i < size_str; i++) {
        matrix_start[i] = new int[size_col];
    }

    initialization_random(matrix_start, size_str, size_col);

    write_matrix_in_file(matrix_start,size_str,size_col);

    del_matrix(matrix_start,size_str);

    int** matrix = new int* [size_str];
    for (int i = 0; i < size_str; i++) {
        matrix[i] = new int[size_col];
    }

    recieve_matrix_from_file(matrix,size_str,size_col,"task1.txt");

    cout << search_k(matrix,size_str,size_col);

    del_matrix(matrix_start,size_str);
}
// ///////////////////////

void find_scale(int &scale, int &scale_full) {

    ifstream fin("task2.txt");

    if (!fin.is_open()) {
        cout << "Error!";
        exit(-1);
    }

    string line;

    while(!fin.eof()) {
        getline(fin,line);
    }
    fin.close();

    scale_full = line.size() / 2 + 1;

    for (int index = 1; index < scale_full + 1; index++) {
        if (index == scale_full - 2 * index - 1) {
            scale = index + 1;
        }
    }

}

void fill_matrix(int** &matrix, const int size_str, const int size_col, int* array, const int size_array) {

    int str = 0;
    int col = 1;
    int index_array = 0;

    for (int index = 0; index < size_str - 1; index++) {
        matrix[str + index][col + index] = array[index_array];
        index_array++;
    }

    str = 0;
    col = 0;

    for (int index = 0; index < size_str ; index++) {
        matrix[str + index][col + index] = array[index_array];
        index_array++;
    }

    str = 1;
    col = 0;

    for (int index = 0; index < size_str - 1 ; index++) {
        matrix[str + index][col + index] = array[index_array];
        index_array++;
    }
}

void write_matrix_in_bin_file(int** matrix, const int &size_str, const int &size_col, string file) {

    ofstream fout(file,ios_base::binary);

    if (!fout.is_open()) {
        cout << "error";
        exit(-1);
    }

    int tmp;

    for (int str = 0; str < size_str; str++) {

        for (int col = 0; col < size_col; col++) {
            tmp = matrix[str][col];
            fout.write((char*)&tmp, sizeof(tmp));

        }

    }

}
void fill_matrix_from_bin_file(int** &matrix, const int size_str, const int size_col, string file) {

    int tmp;

    ifstream fin(file, ios_base::binary);

    for (int i = 0; i < size_str; i++) {
        for (int j = 0; j < size_col; j++) {
            fin.read((char *) &matrix[i][j], sizeof(int));
        }
    }
    fin.close();

    print_matrix(matrix, size_str, size_col);
}

void task2() {

    int size_str = 0;
    int scale_full;

    find_scale(size_str,scale_full);

    int size_col = size_str;
    cout << size_str << endl;
    cout << size_col << endl;
    cout << scale_full << endl;

    int** matrix = new int* [size_str];
    for (int i = 0; i < size_str; i++) {
        matrix[i] = new int[size_col];
    }

    int* array = new int[size_str];

    ifstream fin("task2.txt");

    string tmp;

    if (!fin.is_open()) {
        cout << "Error!";
        exit(-1);
    }

    while (!fin.eof()) {
        for (int i = 0; i < scale_full; i++) {
            fin >> array[i];
        }
    }

    fin.close();

    for (int i = 0; i < scale_full; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    for (int str = 0; str < size_str; str++) {
        for (int col = 0; col < size_col; col++) {
            matrix[str][col] = 0;
        }
    }

    print_matrix(matrix,size_str,size_str);

    fill_matrix(matrix,size_str,size_col,array,scale_full);

    print_matrix(matrix,size_str,size_str);

    write_matrix_in_bin_file(matrix,size_str,size_col,"noobs.dat");

    del_matrix(matrix,size_str);

    fill_matrix_from_bin_file(matrix,size_str,size_col,"noobs.dat");

}

int main() {
    srand(time(NULL));
    //ofstream("task1.txt");
    //ofstream("task2.txt");

    //task1();
    //cout << endl;
    task2();
}
