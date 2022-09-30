#include <stdio.h>
#include <windows.h>

int main(){

    int seconds = 0, minutes = 0, hours = 0;

    while(1){
        system("cls");

        if(seconds == 60){
            seconds = seconds - 60;
            minutes++;
        }
        if(minutes == 60){
            minutes = minutes - 60;
            hours++;
        }

        printf("%dh:%dm:%ds", hours, minutes, seconds);
        Sleep(1000); //delay 1 second (1000 ms)
        seconds++;
    }
    return 0;
}
