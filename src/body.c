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
    float x = ((float)rand() + 1) / (RAND_MAX + 1.0);
    float y = ((float)rand() + 1) / (RAND_MAX + 1.0);

    float z = sqrt(-2.0 * log(x)) * cos(2.0 * 3.14159 * y);

    return media + z * desvio;
}

void gerar_individuos(float matriz_individuos[][2], int m)
{
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

//compara cada fitness e, sempre que acha um maior que o anterior, redefine o segundo melhor fitness e 
//atualiza o melhor


//-1e30 funciona como um fitness absurdamente pequeno para garantir que a primeira comparação seja válida 

void selecionar_melhor_fitness(float fitness[], int m, int *pai1, int *pai2)
{
    int melhor1 = -1, melhor2 = -1;
    float fitness1 = -1e30, fitness2 = -1e30;

    for(int x = 0; x < m; x++)
    {
        if(fitness[x] > fitness1)
        {
            fitness2 = fitness1;
            melhor2 = melhor1;

            fitness1 = fitness[x];
            melhor1 = x;
        }
        else if(fitness[x] > fitness2 && x != melhor1) //evita melhor1=melhor2=0
        {
            fitness2 = fitness[x];
            melhor2 = x;
        }
    }

    *pai1 = melhor1;
    *pai2 = melhor2;
}

void crossover_com_mutacao(int pai1, int pai2, float matriz_individuos[][2], float *a, float *b)
{
    *a = matriz_individuos[pai1][0];
    *b = matriz_individuos[pai2][1];

    float mutacao = gauss(0, 0.5);
    
    if(rand() % 2 == 0)
        *a += mutacao;
    else
        *b += mutacao;
}

void selecionar_pior_fitness(float fitness[], int m, int *pior)
{
    int pior_indice = 0;      
    float pior_fitness = fitness[0];

    for (int x = 1; x < m; x++)
    {
        if (fitness[x] < pior_fitness)
        {
            pior_fitness = fitness[x];
            pior_indice = x;
        }
    }

    *pior = pior_indice;  
}