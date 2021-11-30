#include <iostream>
#include <locale> // для tolower()
#include <cstring>

// Палиндром ли?

using namespace std;

int lenght(char* string) {
    int index = 0;
    int lenght = 0;
    while (string[index] != '\0') {
        lenght += 1;
        index ++;
    }
    return lenght;
}

bool check_palindrom(char* string) {

    int string_lenght = lenght(string);

    for (int index = 0; index < (string_lenght / 2); index++) {
        if (tolower(string[index]) != tolower(string[string_lenght - 1 - index])) { return false; } // Учитываются буквы различных регистров.
    }
    return true;
}

int main() {

    // Initialization
    char string[256];
    cout << "Write your word to determine it is a palindrome or no: " << endl;
    gets(string);

    // To determine
    int count_ = 0;
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            count_++;
        }
        i++;
    }

    if (count_ == 0) {
        if (check_palindrom(string) == true) {
            cout << "Yes, it's a palindrome!";
            return 0;
        }
        else {
            cout << "No, it's not a palindrome! :(";
            return -1;
        }
    }

    else {
        char* s_copy = new char[strlen(string)];
        strcpy_s(s_copy,strlen(string) + 1, string);
        char *context;
        char *temp = s_copy; //копия указ, а не строки
        char result[256] = "";
        while (char *part = strtok_s(temp," ",&context)) {
            int a;
            a = atoi(part);
            strcat(result,part);
            temp = nullptr;
        }
        if (check_palindrom(result) == true) {
            cout << "Yes, it's a palindrome!";
            return 0;
        }
        else {
            cout << "No, it's not a palindrome! :(";
            return -1;
        }
    }
}
