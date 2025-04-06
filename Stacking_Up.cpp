#include <bits/stdc++.h> 

#define inteiro_longo long long 
#define decimal_longo long double
#define OTIMIZAR_ENTRADA_SAIDA \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); // deixa a entrada e saída mais rápida

using namespace std;

const int TAMANHO_MAXIMO = 1e5 + 9; // constante genérica (não tá usando aqui)
const int MODULO = 1e9 + 7;         // idem

void resolverProblema()
{
    int quantidade;
    cin >> quantidade; // lê quantos números vão ser lidos

    vector<inteiro_longo> numeros(quantidade); // vetor dos números

    for (int i = 0; i < quantidade; i++) {
        cin >> numeros[i]; // preenche o vetor
    }

    string resultado = ""; // aqui vai guardar a resposta final
    inteiro_longo deslocamento = 0; // tipo um contador de "tempo" ou de mudanças

    // enquanto ainda tiver número no vetor
    while (!numeros.empty())
    {
        // se o número (ajustado) for 1
        if ((numeros.back() + deslocamento) == 1) {
            resultado += '1';
            numeros.pop_back(); // tira esse número do vetor
        }
        // se for par
        else if ((numeros.back() + deslocamento) % 2 == 0) {
            inteiro_longo novo_valor = (numeros.back() + deslocamento) / 2;
            numeros.pop_back();

            resultado += "+d"; // marca essa operação
            deslocamento++; // passou mais uma "etapa"
            novo_valor -= deslocamento;
            numeros.push_back(novo_valor); // coloca o novo valor
        }
        // se for ímpar (e diferente de 1)
        else {
            resultado += '+';
            numeros.back() -= 2;
            deslocamento++;
            numeros.push_back(1 - deslocamento); // estratégia pra forçar chegar no 1 depois
        }
    }

    reverse(resultado.begin(), resultado.end()); // inverte a string (porque construiu ao contrário)

    cout << resultado; // mostra a resposta
}

int main()
{
    OTIMIZAR_ENTRADA_SAIDA

    int testes = 1;
    // cin >> testes; // se quiser fazer com vários casos, descomenta isso

    for (int caso = 1; caso <= testes; caso++) {
        resolverProblema(); // chama a função principal
    }
}