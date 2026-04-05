#ifndef HEADERS_H
#define HEADERS_H

void teste();

void gerar_individuos(float matriz_individuos[][2], int  m);
float calcular_erro(float a, float b, float matriz[][2], int n);
void selecionar_melhor_fitness(float fitness[], int m, int *pai1, int *pai2);
void crossover_com_mutacao(int pai1, int pai2, float matriz_individuos[][2], float *a, float *b);
void selecionar_pior_fitness(float fitness[], int m, int *pior);

#endif