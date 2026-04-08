🧬 Algoritmo Genético: Ajuste de Função Linear

Este projeto implementa um Algoritmo Genético (AG) clássico em C voltado para o problema de ajuste de parâmetros. O objetivo principal é encontrar os coeficientes a e b que minimizam o Erro Quadrático Médio (MSE) entre a reta estimada y^​=ax+b e um conjunto de pontos amostrais fixos.
📂 Estrutura do Projeto

A organização do diretório segue as boas práticas de modularização e organização modular de programas:

    src/: Arquivos fonte (.c) contendo a lógica principal e o ciclo evolutivo.

    include/: Cabeçalhos (.h) com as definições de estruturas e protótipos.

    tools/: Ferramentas auxiliares, como o gerador de pontos (gerar.c).

    data/: Diretório reservado para os arquivos input.dat (entrada) e output.dat (saída).

    Makefile: Script de automação para compilação e execução obrigatória em ambiente Linux.

🧬 Funcionamento do Algoritmo

O ciclo evolutivo foi projetado para consolidar o domínio sobre manipulação de vetores, ponteiros e alocação dinâmica de memória:

    Inicialização: Geração aleatória da população inicial de indivíduos (a,b) dentro de limites definidos.

    Avaliação: Cálculo do erro e do fitness (aptidão) para cada indivíduo. O fitness é inversamente proporcional ao erro.

    Seleção: Identificação dos dois indivíduos com maior fitness para servirem como progenitores.

    Crossover: Operação de combinação parcial dos parâmetros dos pais para gerar um descendente.

    Mutação: Introdução de uma variação controlada (δ) para manter a diversidade genética e evitar mínimos locais.

    Atualização: Substituição do indivíduo de pior desempenho pelo novo filho gerado, repetindo o processo por G gerações.

🚀 Como Executar

O projeto utiliza o Makefile para simplificar o processo de build em sistemas Linux (Ubuntu ou Zorin).
Comandos Principais:
Ação	Comando
Compilar o projeto	make
Executar o algoritmo	make run
Limpar binários e objetos	make clean
📄 Formato de Dados (input.dat)

O programa realiza a leitura dos parâmetros de execução e dos pontos amostrais através de um arquivo de texto:
Plaintext

n m G       <-- (Nº de pontos, Tamanho da População, Nº de Gerações)
x1 y1       <-- (Coordenadas X e Y do primeiro ponto)
x2 y2
...
xn yn     

📊 Resultados Esperados

Com base na semente padrão e na natureza convexa do problema de ajuste linear, o algoritmo tende a convergir para os seguintes valores:

    Coeficiente Angular (a): ≈2.00

    Coeficiente Linear (b): ≈4.88

    Erro Médio: ≈2.73

    Nota: Ao atingir o mínimo global, o algoritmo tende a "estacionar", uma vez que o ajuste busca a maximização do fitness através da minimização sistemática do erro.

🔧 Requisitos de Sistema

    Linguagem: C ou C++ (Procedimental ou Orientado a Objetos).

    Compilador: GCC.

    Ambiente: Linux (Ubuntu ou Zorin via Makefile).

📚 Créditos

    Desenvolvedor: Matheus Tavares

    Instituição: CEFET-MG 

    Disciplina: Algoritmos e Estruturas de Dados I 

    Documentação: Estruturada com auxílio de IA.
