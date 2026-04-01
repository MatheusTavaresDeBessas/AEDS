#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include "../include/headers.h"

int main(void)
{
    setlocale(LC_ALL, "portuguese");        

    system("clear");

    teste();

    FILE *f = fopen("data/input.dat", "r");

    if (!f) 
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    short int g, n, m;
    fflush(stdin);
    fscanf(f, "%hd %hd %hd", &n, &m, &g);

    float matriz[n][2];
    float matriz_individuos[m][2];

    gerar_individuos(matriz_individuos, m);
    
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<2; y++)
        {
            fscanf(f, "%f", &matriz[x][y]);
        }

        printf("\n%f", matriz[x][0]);
        printf(" %f\n", matriz[x][1]);
    }

    printf("\n-------------------------------------\n");

    for(int x=0; x<m; x++)
    {
        printf("\n%f", matriz_individuos[x][0]);
        printf(" %f\n", matriz_individuos[x][1]);
    }

    fclose(f);

    return 0;
}