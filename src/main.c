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
    srand(42); 

    //system("clear");

    teste();

    FILE *f = fopen("data/input.dat", "r");

    if (!f) 
    {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    int g, n, m;

    fscanf(f, "%d %d %d", &n, &m, &g);

    float (*matriz_pontos)[2] = malloc(n * sizeof(*matriz_pontos));
    
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<2; y++)
        {
            fscanf(f, "%f", &matriz_pontos[x][y]);
        }
    }
    fclose(f);

    float (*matriz_individuos)[2] = malloc(m * sizeof(*matriz_individuos));

    gerar_individuos(matriz_individuos, m);

    float erro_medio[m];

    for(int x=0; x<m; x++)
    {
        erro_medio[x] = calcular_erro(matriz_individuos[x][0], matriz_individuos[x][1], matriz_pontos, n);
    }

    float fitness[m];

    for(int x=0; x<m; x++)
    {
        float erro = erro_medio[x];
        fitness[x] = 1.0f / (erro + 0.0001f);
    }

    FILE *out = fopen("data/output.dat", "w");
    if (!out) 
    {
        printf("Erro ao abrir output.dat!\n");
        return 1;
    }

    for(int geracoes = 0; geracoes < g; geracoes++)
    {
        int pior_fitness;
        selecionar_pior_fitness(fitness, m, &pior_fitness);

        int pai1, pai2;
        selecionar_melhor_fitness(fitness, m, &pai1, &pai2);

        float filho_a, filho_b;
        crossover_com_mutacao(pai1, pai2, matriz_individuos, &filho_a, &filho_b);

        matriz_individuos[pior_fitness][0] = filho_a;
        matriz_individuos[pior_fitness][1] = filho_b;

        float erro_novo_individuo = calcular_erro(matriz_individuos[pior_fitness][0], matriz_individuos[pior_fitness][1], matriz_pontos, n);
        float fitness_novo_individuo = 1.0f / (erro_novo_individuo + 0.0001f);

        matriz_individuos[pior_fitness][0] = filho_a;
        matriz_individuos[pior_fitness][1] = filho_b;

        fitness[pior_fitness] = fitness_novo_individuo;
        erro_medio[pior_fitness] = erro_novo_individuo;
    
        int melhor, descarte; 
        selecionar_melhor_fitness(fitness, m, &melhor, &descarte); 
        
        printf("\nGeração: %d\nErro melhor: %f\nFitness melhor: %f\n", geracoes + 1, erro_medio[melhor], fitness[melhor]);
    
        fprintf(out, "Melhor indivíduo da geração: %d\n", geracoes + 1);
        fprintf(out, "a = %f\n", matriz_individuos[melhor][0]);
        fprintf(out, "b = %f\n", matriz_individuos[melhor][1]);
        fprintf(out, "Erro médio = %f\n", erro_medio[melhor]);
        fprintf(out, "Fitness = %f\n\n", fitness[melhor]);        
    }

    fclose(out);

    free(matriz_pontos);
    free(matriz_individuos);

    return 0;
}