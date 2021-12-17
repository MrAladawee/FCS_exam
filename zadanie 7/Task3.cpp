#include <iostream>
#include <cstring>

// ФИО -> И.О. Фамилия.

using namespace std;

void lfp(char* string, char* array) {
    int i = 0;

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


}

int main() {

    char string[256];
    char array[128];

    // Initialization
    cout << "Write the last name, first name, patronymic:" << endl;
    gets(string);
    
    // Main part
    lfp(string,array);

    return 0;
}
