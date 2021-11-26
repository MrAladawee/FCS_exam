#include <iostream>
#include <cstring>
// Сумма.

using namespace std;

int result_of_eq(char* string) {
    int sum = 0;

    char* s_copy = new char[strlen(string) + 1];
    strcpy_s(s_copy,strlen(string)+1,string);

    char* contex;
    char* temp = s_copy;

    while(char* part = strtok_s(temp, "+", &contex)) {
        int a;
        a = atoi(part);
        sum += a;
        temp = nullptr;
    }
    return sum;
}



int main() {

    // Initialization
    char equation[256];
    cout << "Write your mathematical equation: " << endl;
    gets(equation);
    cout << endl;
    
    // Result
    cout << "The result of equation is: " << result_of_eq(equation);
    return 0;
}
