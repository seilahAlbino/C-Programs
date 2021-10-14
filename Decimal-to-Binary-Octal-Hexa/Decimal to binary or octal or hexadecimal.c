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
int main(){
    int decimal, restDiv, Div, iColor = 10, decision;

    printf("Enter the decimal number: ");
    scanf(" %d", &decimal);
    printf("Binary System(2)\nOctal System(8)\nHexadecimal System(16)\n\nEnter: ");
    scanf(" %d", &decision);
    system("cls");

    switch(decision){
        case 2:
                while(decimal > 0){
                    SetColor(iColor);
                    if(iColor == 14) iColor = 10;
                    if(iColor < 14) iColor++;
                    Div = decimal / 2;
                    restDiv = decimal % 2;
                    decimal = decimal / 2;
                    printf("Division: %d\nRest split: %d\n\n\n", Div, restDiv);
                }
                SetColor(10);
                printf("Bottom up is the binary number ^^\n\n\n");
                SetColor(15);
                break;

        case 8:
                while(decimal > 0){
                    SetColor(iColor);
                    if(iColor == 14) iColor = 10;
                    if(iColor < 14) iColor++;
                    Div = decimal / 8;
                    restDiv = decimal % 8;
                    decimal = decimal / 8;
                    printf("Division: %d\nRest split: %d\n\n\n", Div, restDiv);
                }
                SetColor(10);
                printf("Bottom up is the octal number ^^\n\n\n");
                SetColor(15);
                break;

        case 16:
                while(decimal > 0){
                    SetColor(iColor);
                    if(iColor == 14) iColor = 10;
                    if(iColor < 14) iColor++;
                    Div = decimal / 16;
                    restDiv = decimal % 16;
                    if(restDiv == 10){
                        printf("Division: %d\nRest split: A\n\n\n", Div);
                    }else if(restDiv == 11){
                        printf("Division: %d\nRest split: B\n\n\n", Div);
                    }else if(restDiv == 12){
                        printf("Division: %d\nRest split: C\n\n\n", Div);
                    }else if(restDiv == 13){
                        printf("Division: %d\nRest split: D\n\n\n", Div);
                    }else if(restDiv == 14){
                        printf("Division: %d\nRest split: E\n\n\n", Div);
                    }else if(restDiv == 15){
                        printf("Division: %d\nRest split: F\n\n\n", Div);
                    }else{
                        printf("Division: %d\nRest split: %d\n\n\n", Div, restDiv);
                    }
                    decimal = decimal / 16;

                }
                SetColor(10);
                printf("Bottom up is the hexadecimal number ^^\n\n\n");
                SetColor(15);
                break;

        default:
            printf("There is nothing else in my system! Come back if you want to turn one decimal number into another");
    }
    return 0;
}
