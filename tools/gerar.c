#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ferramenta usada so para testes, ignorei no makefile

float gauss(float media, float desvio) 
{
    float u1 = ((float)rand() + 1) / (RAND_MAX + 1.0);
    float u2 = ((float)rand() + 1) / (RAND_MAX + 1.0);

    float z = sqrt(-2.0 * log(u1)) * cos(2.0 * 3.14159 * u2);

    return media + z * desvio;
}

int main(void) 
{
    int pontos = 40, populacao = 60, geracoes = 100;

    FILE *f = fopen("data/input.dat", "w");

    srand(42); 

    fprintf(f, "%d %d %d\n", pontos, populacao, geracoes);

    for (int contador = 0; contador < pontos; contador++) 
    {
        float x = contador - 20;

        float ruido = gauss(0, 2);

        float y = 2 * x + 5 + ruido;

        fprintf(f, "%.2f %.2f\n", x, y);
    }

    fclose(f);

    return 0;
}