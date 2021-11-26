#include <iostream>
#include <locale> // для tolower()

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
    if (check_palindrom(string) == true) { cout << "Yes, it's a palindrome!"; return 0; }
    else { cout << "No, it's not a palindrome! :("; return -1; }

}
