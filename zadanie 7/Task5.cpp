#include <iostream>
#include <cstring>

// Кол-во вхождений слова в строку.

using namespace std;

int search_string(char *string, char *nd_str, int len_nd_str) {
    int count = 0;
    for (int i = 0; i < strlen(string) - len_nd_str + 1; i++) {
        for (int j = 0; j < len_nd_str; j++) {
            if (string[i+j] == nd_str[j]) {
                count++;
            }
        }
    }
    if (count >= len_nd_str) {return count / len_nd_str;}
    else {return 0;}
}

int main() {
    char string[256];
    char nd_str[256];
    int len_nd_str = 0;
  
    cout << "Warning! String size limit - 256 characters." << endl;
    cout << "Write your string:" << endl;
    gets(string);

    cout << "Write your need word:" << endl;
    gets(nd_str);
    len_nd_str = strlen(nd_str);
    cout << endl;

    cout << "The count of occurrences of a word in a string:" << endl;
    cout << search_string(string, nd_str, len_nd_str);
}
