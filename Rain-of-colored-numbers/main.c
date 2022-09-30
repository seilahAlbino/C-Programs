#include <stdio.h>
#include <windows.h>

void SetColor(int ForgC){
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);

            SetConsoleTextAttribute(hStdOut, wColor);
    }
}

int main()
{
    int i = 0, iColor = 0;

    while(1)
    {
        iColor = rand() % 15 + 1;
        i++;
        SetColor(iColor);
        printf("%d", i);

    }
    return 0;
}
