📘 Projeto: Algoritmo Genético para Ajuste de Função Linear

Este projeto implementa um Algoritmo Genético (AG) para encontrar os parâmetros ótimos de uma função linear do tipo:

y=ax+b
y=ax+b

O objetivo é ajustar uma reta que minimize o erro médio quadrático entre os valores previstos e os valores reais de um conjunto de pontos.

📁 Estrutura do Projeto

/
├── src/            # Código-fonte principal (main e módulos do AG)
├── include/        # Headers (.h)
├── tools/          # Ferramentas auxiliares (gerar.c)
├── build/          # Objetos compilados e executáveis
├── data/           # Arquivos de entrada e saída (.dat)
├── Makefile        # Automação de compilação e execução
└── README.md       # Documentação do projeto

🧬 Descrição Geral

O programa utiliza um algoritmo genético clássico composto por:

Geração inicial de indivíduos (valores aleatórios de a e b)
Avaliação do erro usando os pontos fornecidos
Cálculo do fitness (inversamente proporcional ao erro)
Seleção dos dois melhores indivíduos
Crossover para gerar o novo indivíduo
Mutação controlada
Substituição do pior indivíduo da população

Esse processo é repetido durante G gerações, até que os melhores valores de a e b sejam encontrados.

📄 Entrada de Dados (input.dat)

OBS: Essa ferramenta foi desabilitada para que a edição livre do input.dat possa ser feita. 

Os dados utilizados pelo algoritmo genético são gerados automaticamente pelo arquivo:

tools/gerar.c

Ela usa uma seed fixa, garantindo replicabilidade da execução.

O arquivo input.dat contém:

n m G
x1 y1
x2 y2
...
xn yn

Onde:

n = número de pontos
m = tamanho da população (nº de indivíduos)
G = número de gerações
🚀 Execução via Makefile

O projeto é totalmente automatizado por um Makefile.

Compilar:

make

Compilar e executar:

make run

Limpar arquivos compilados:

make clean

Sobre o gerador de dados

Para facilitar manutenção, o Makefile contém blocos comentados responsáveis por:

Compilar gerar.c
Gerar automaticamente o arquivo input.dat

Atualmente, o projeto usa o input.dat existente, sem apagá-lo a cada execução.

📤 Saída (output.dat)

O programa gera um arquivo contendo, para cada geração:

Melhor indivíduo da população
Parâmetros a e b
Erro médio
Fitness

Ao final do processo, o arquivo contém o melhor ajuste encontrado em todas as gerações.

🔧 Requisitos
GCC
Make
Linux ou WSL recomendado
🧠 Observações sobre convergência

O AG tende a convergir para:

a≈2.00, b≈4.88
a≈2.00, b≈4.88

Com erro:

Erro mıˊnimo≈2.73
Erro mnimo≈2.73

Este é o mínimo global real para os pontos utilizados.

Por ser um problema convexo, é esperado que o algoritmo “estacione” quando atingir esse valor — qualquer ajuste em a ou b só aumentaria o erro.

📚 Créditos

Projeto desenvolvido por: Matheus Tavares
Readme: Desenvolvido com ajuda do LLM ChatGPT.
Disciplina: Meta-Heurísticas