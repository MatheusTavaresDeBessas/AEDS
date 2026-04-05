#include <stdlib.h>
#include <stdio.h>
#include "../include/headers.h"
#include <math.h>

void teste()
{
    printf("\nOlá mundo!\n");
}

float gauss(float media, float desvio) 
{
    float u1 = ((float)rand() + 1) / (RAND_MAX + 1.0);
    float u2 = ((float)rand() + 1) / (RAND_MAX + 1.0);

    float z = sqrt(-2.0 * log(u1)) * cos(2.0 * 3.14159 * u2);

    return media + z * desvio;
}

void gerar_individuos(float matriz_individuos[][2], int m)
{
    srand(42);

    for (int x = 0; x < m; x++) 
    {
        matriz_individuos[x][0] = ((float)rand() / RAND_MAX) * 20 - 10;
        matriz_individuos[x][1] = ((float)rand() / RAND_MAX) * 20 - 10;
    }
}

float calcular_erro(float a, float b, float (*matriz)[2], int n)
{
    float erro=0;

    for(int x=0; x<n; x++)
    {
        erro+=(matriz[x][1] - (a*(matriz[x][0]) + b)) * (matriz[x][1] - (a*(matriz[x][0]) + b));
    }

    erro /= n;

    return erro;
}