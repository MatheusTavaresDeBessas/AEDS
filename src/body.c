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

void gerar_individuos(float matriz_individuos[][2], short int  m)
{
    srand(42); 

    for (int contador = 0; contador < m; contador++) 
    {
        float x = contador - 20;

        float ruido = gauss(0, 2);

        float y = 2 * x + 5 + ruido;

        matriz_individuos[contador][0] = x;
        matriz_individuos[contador][1] = y;
    }
}

float calcular_erro(float a, float b, float (*matriz)[2], int n)
{
    float erro=0;

    for(int x=0; x<n; x++)
    {
        erro+=(matriz[x][1] - (a*(matriz[x][0]) + b)) * (matriz[x][1] - (a*(matriz[x][0]) + b));
    }

    erro = erro * 1/n;

    return erro;
}