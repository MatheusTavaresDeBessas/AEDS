#include <stdlib.h>
#include <stdio.h>
#include<locale.h>
#include "../include/headers.h"

//o bloco de FILE lê os pontos gerados pela ferramenta gerar.c, que é executada em
//conjunto com o main através do makefile. O arquivo input.dat é gerado através de uma seed
//fixa. Abaixo, a função responsável por gerar a matriz de indivíduos é chamada.

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

    float matriz_pontos[n][2]; 
    
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<2; y++)
        {
            fscanf(f, "%f", &matriz_pontos[x][y]);
        }
    }
    fclose(f);

    float matriz_individuos[m][2];

    gerar_individuos(matriz_individuos, m);

    float erro_medio[m];

    for(int x=0; x<m; x++)
    {
        erro_medio[x] = calcular_erro(matriz_individuos[x][0], matriz_individuos[x][1], matriz_pontos, n);
    }

    return 0;
}