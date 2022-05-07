#include <iostream>
#include <conio.h>
#include "game.h"
#include "background.h"

using namespace std;

int main()
{
    Background background;

    while (true) {
        background.position(50, 0);
        cout << "Flappy Bird";
        background.instructions(0, 2);
        background.position(0, 6);
        cout << "Press any key to start a new game or ESC to exit" << endl;
        char option = _getch();
        if (option == 27) return 0;

        system("cls");
        Game* game = new Game("Flappy Bird");
    }
}
