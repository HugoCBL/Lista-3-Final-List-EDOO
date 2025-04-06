#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// estrutura para os nós da lista ligada (encadeamento externo)
struct No {
    string bloco;
    int contagem;
    No* prox;
};


// função auxiliar que verifica se o bloco contém somente os caracteres A, T, C ou G
bool blocoValido(const string &s) {
    for (char c : s) {
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G')
            return false;
    }
    return true;
}


// classe que implementa a tabela de espalhamento (hash table)
class TabelaHash {
private:
    static const int tamanho = 10007; // tamanho da tabela (número primo)
    No** vetor;


    // função de espalhamento: converte o bloco em um índice na tabela
    int funcaoEspalhamento(const string &s) {
        unsigned int hash = 0;
        for (char letra : s) {
            hash = hash * 31 + letra; // fórmula simples
        }
        return hash % tamanho;
    }
   
public:
    TabelaHash() {
        vetor = new No*[tamanho];
        for (int i = 0; i < tamanho; i++)
            vetor[i] = nullptr;
    }
   
    ~TabelaHash() {
        // libera toda a memória alocada para os nós
        for (int i = 0; i < tamanho; i++) {
            No* atual = vetor[i];
            while (atual) {
                No* temp = atual;
                atual = atual->prox;
                delete temp;
            }
        }
        delete[] vetor;
    }
   
    // insere o bloco na tabela; retorna true se for a primeira ocorrência, false se já existe
    bool inserirNovo(const string &s) {
        int indice = funcaoEspalhamento(s);
        No* atual = vetor[indice];
        while (atual) {
            if (atual->bloco == s) {
                atual->contagem++;  // bloco já existe, incrementa a contagem
                return false;
            }
            atual = atual->prox;
        }
        // bloco não encontrado, cria novo nó
        No* novo = new No;
        novo->bloco = s;
        novo->contagem = 1;
        novo->prox = vetor[indice];
        vetor[indice] = novo;
        return true;
    }
   
    // retorna a contagem do bloco (0 se não encontrado)
    int obterContagem(const string &s) {
        int indice = funcaoEspalhamento(s);
        No* atual = vetor[indice];
        while (atual) {
            if (atual->bloco == s)
                return atual->contagem;
            atual = atual->prox;
        }
        return 0;
    }
};


int main() {
    // abre o arquivo de entrada
    ifstream entrada("entrada.txt");
    if (!entrada) {
        cerr << "Erro ao abrir o arquivo de entrada!" << endl;
        return 1;
    }
   
    // abre o arquivo de saída
    ofstream saida("saida.txt");
    if (!saida) {
        cerr << "Erro ao abrir o arquivo de saída!" << endl;
        return 1;
    }
   
    TabelaHash tabela;
    vector<string> ordem; // guarda a ordem de primeira aparição dos blocos
   
    string linha;
    // ignora a primeira linha (cabeçalho)
    getline(entrada, linha);
   
    // lê o arquivo linha a linha e processa todos os blocos completos de 6 caracteres
    while(getline(entrada, linha)) {
        // verifica se a linha tem pelo menos 6 caracteres e ignora a última linha incompleta
        if (linha.size() < 6) continue;
       
        // processa cada bloco de 6 caracteres na linha (10 blocos por linha)
        for (int i = 0; i <= 54; i += 6) { // 60-6=54
            string bloco = linha.substr(i, 6);
            if (!blocoValido(bloco)) {
                cerr << "Bloco inválido ignorado: " << bloco << endl;
                continue;
            }
            // se o bloco for novo, registra-o na ordem de aparição
            if (tabela.inserirNovo(bloco)) {
                ordem.push_back(bloco);
            }
        }
    }
   
    // imprime no arquivo de saída os blocos na ordem em que apareceram, com a contagem acumulada
    for (const string &bloco : ordem) {
        saida << bloco << " " << tabela.obterContagem(bloco) << "\n";
    }
   
    entrada.close();
    saida.close();
    return 0;
}