#include <iostream>
#include <cstring>

// ФИО -> И.О. Фамилия.

using namespace std;

int main() {

    char string[256];
    char array[128];
    int i = 0;

    // Initialization
    cout << "Write the last name, first name, patronymic:" << endl;
    gets(string);

    // Work with last name.
    while (string[i] != ' '){
        array[i] = string[i];
        i++;
    }

    // Work with Name and patronymic.
    array[i] = '\0';
    for (i; i < strlen(string); i++){
        if (string[i] == ' '){
            cout << string[i+1] << ".";
        }
    }
    cout << ' ' << array;

    return 0;
}
