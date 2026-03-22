#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include "../include/headers.h"

int main(void)
{
    setlocale(LC_ALL, "portuguese");        

    teste();

    FILE *f = fopen("data/input.dat", "r");

    if (!f) 
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fclose(f);

    return 0;
}