#include <stdio.h>
#include <windows.h>

SetColor(int ForgC){
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);

            SetConsoleTextAttribute(hStdOut, wColor);
    }
}

goXY(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleCursorPosition(hConsole, coord)){

    }
}

int main(){

    int i = 0, x = 0, y = 0, color;

    while(i != 1){

        x = rand() % 157; //number between 0 and 157
        y = rand() % 60;

        color = rand() % 15;

        goXY(x, y);

        SetColor(color);

        printf("*");
        Sleep(100);
    }
}
