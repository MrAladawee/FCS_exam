// Task1

#include <iostream>
#include <time.h>
using namespace std;

void game_cube() {
    cout << "Выпавшие значения:" << endl;
    cout << "Значение первой игральной кости: " << 1 + rand() % 6 << endl;
    cout << "Значение второй игральной кости: " << 1 + rand() % 6 << endl;
}


int main() {
    system("chcp 65001");
    srand(time(NULL));
    game_cube();
    return 0;
}
