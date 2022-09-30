#include <stdio.h>
#include <windows.h>
void SetColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

    SetConsoleTextAttribute(hConsole, color);
}

int main()
{
    int scale, randomColor, width, height;
    int door;
    int load = 0;
    while(load == 0)
    {
        printf("Insira um numero: ");
        scanf(" %d", &scale);
        printf("Insira o tamanho da porta: ");
        scanf(" %d", &door);
        printf("\n\n");

        int n[] = {scale/2, scale/2};
        for(int i = 0; i < ((scale/2)+1); i++)
        {
            for(int j = 0; j < scale; j++)
            {
                randomColor = rand()%15 + 1;
                SetColor(randomColor);
                if(j == n[0] || j == n[1])
                {
                    printf("X");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
            if(n[0] > 0) n[0]--;
            if(n[1] < (scale-1)) n[1]++;
        }

        for(int i = 0; i < scale-1; i++)
        {
            for(int j = 0; j < scale; j++)
            {
                randomColor = rand()%15 + 1;
                SetColor(randomColor);
                if((j == 0 || j == scale - 1) || i == (scale - 2) || // lados da casa
                        (i > (scale - 2 - door) && ((j == scale/2 - (door/2)) || (j == scale/2 + (door/2)))) || //lados da porta
                        (i == (scale - 2 - door) && (j >= scale/2 - (door/2)) && (j <= scale/2 + (door/2))) //parte de cima da porta
                  )
                {
                    printf("X");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }

        SetColor(15);
        printf("\n\n\nContinuar (Sim = 0 / Nao = Outro numero): ");
        scanf("%d", &load);
        system("cls");
    }
    
    system("cls");
    printf("Acabou oh filho\n\n");
    return 0;
}
