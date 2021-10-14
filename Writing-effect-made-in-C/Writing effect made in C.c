#include <stdio.h>
#include <windows.h>

int main(){

    char *strings[1][100];

    strings[1][1] = "I do not know what write";
    strings[1][2] = "Like and Subscribe";

    int i = 0;

    while(i < strlen(strings[1][1])){
        printf("%c", strings[1][1][i]);
        Sleep(100); //0.1 second
        i++;
    }

    i = 0;
    printf("\n");
    while(i < strlen(strings[1][2])){
        printf("%c", strings[1][2][i]);
        Sleep(100); //0.1 second
        i++;
    }

    return 0;
}
