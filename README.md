📘 Listas de Programação - Hash Table, Strings e Manipulação de Dados
Este repositório contém a resolução de três listas de exercícios da disciplina de Estruturas de Dados.

📂 Organização dos Arquivos
📁 Lista 1 - Análise de Genoma da COVID-19
Arquivo principal: covid_genoma.cpp
 Arquivos auxiliares: entrada1.txt, entrada2.txt, saida1.txt, saida2.txt, processar.bat
Descrição:
 O programa implementa uma tabela de espalhamento com encadeamento externo para identificar e contar repetições de blocos de 6 bases nitrogenadas (A, T, C, G) em um genoma. A leitura é feita em blocos de 6 caracteres a partir de cada linha de 60 caracteres do arquivo de entrada.
Entrada:
 Arquivo .txt com o genoma completo do vírus SARS-CoV-2 (formato NC_045512.2 do NCBI).
Saída:
 Arquivo .txt com duas colunas:
A primeira: bloco de 6 letras


A segunda: número de ocorrências desse bloco no genoma



📁 Lista 2 - A and B and Interesting Substrings
Arquivo: A_and_B_and_Interesting_Substrings.cpp
Descrição:
 Solução de uma questão de string com contagem eficiente de substrings interessantes usando hashing de prefixo. Para cada letra da string, é mantida uma tabela hash associando prefixos parciais com frequências.
Entrada:
26 inteiros: valores atribuídos às letras a a z


Uma string s com letras minúsculas


Saída:
 Número de substrings interessantes segundo os critérios definidos pela questão.

📁 Lista 3 - Stacking Up
Arquivo: Stacking_Up.cpp
Descrição:
 Implementa uma lógica de simulação baseada em operações sobre um vetor de números inteiros com transformações específicas. A solução envolve o uso de operações condicionais e manipulação da pilha de valores, com objetivo de produzir uma string de saída representando a ordem das operações.
Entrada:
 Um inteiro n seguido de n valores inteiros.
Saída:
 Uma string representando a sequência de operações realizadas sobre os dados.

⚙️ Como Compilar
Compile os arquivos C++ com g++ ou outro compilador compatível:
g++ -o covid covid_genoma.cpp
g++ -o substrings A_and_B_and_Interesting_Substrings.cpp
g++ -o stacking Stacking_Up.cpp


▶️ Como Executar
## ▶️ Como Executar a questão Covid genoma analysis:



1. **Insira os dados de genoma** nos arquivos `entrada1.txt` e `entrada2.txt`, conforme o formato descrito (linhas de 60 caracteres, exceto a última que pode ser ignorada).
   
2. **Abra o explorador de arquivos** e vá até o diretório onde os arquivos do projeto estão salvos.

3. **Execute o arquivo `processar.bat`** clicando duas vezes sobre ele.

   Esse script irá:
   - Compilar o código C++ (`covid_genoma.cpp`);
   - Executar o programa para os arquivos `entrada1.txt` e `entrada2.txt`;
   - Gerar os arquivos de saída `saida1.txt` e `saida2.txt`, com os blocos e suas respectivas contagens.
