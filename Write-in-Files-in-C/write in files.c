#include <stdio.h>
#include <windows.h>

int main(){

    char string[100];
    FILE *file;
    file = fopen("a.txt", "a");

    printf("Write anything: ");
    gets(string);

    fprintf(file, "%s", string);
    fclose(file);

    return 0;

}
