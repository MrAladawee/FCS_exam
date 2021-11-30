#include <iostream>
#include <cstring>

// Расширение файла.

using namespace std;

int main() {
    char string[80];
    char f_ext[80];
    int i;
    
    cout << "Write your file name:" << endl;
    gets(string);

    cout << "Write your need file extension with point (f.e: .php):" << endl;
    gets(f_ext);

    i = 0;
    int index_point = 0;
    while (string[i] != '\0') {
        if (string[i] == '.') {index_point = i;}
        i++;
    }
    if (index_point != 0)
        strcpy(string+index_point,f_ext);
    else strcat(string,f_ext);

    cout << "Result:" << endl;
    cout << string;

    return 0;
}
