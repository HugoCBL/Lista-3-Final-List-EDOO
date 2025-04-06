#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

// Estrutura pra guardar chave, valor e se a posição tá ocupada
struct Entrada {
    ll chave;
    int valor;
    bool ocupado;
};

// Hash com endereçamento aberto (linear probing)
struct TabelaHash {
    vector<Entrada> tabela;
    int capacidade;

    // construtor
    TabelaHash(int cap) {
        capacidade = cap;
        tabela.assign(capacidade, {0, 0, false});
    }

    // função hash pra long long
    unsigned long long hash_ll(ll x) const {
        unsigned long long z = x + 0x9e3779b97f4a7c15ULL;
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
        z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
        return z ^ (z >> 31);
    }

    // encontra onde colocar/buscar a chave
    int encontrarPosicao(ll chave) {
        unsigned long long h = hash_ll(chave);
        int pos = h & (capacidade - 1); // funciona bem se capacidade for potência de 2
        while (tabela[pos].ocupado && tabela[pos].chave != chave) {
            pos = (pos + 1) & (capacidade - 1);
        }
        return pos;
    }

    // pega valor da chave (frequência), se não tiver retorna 0
    int obter(ll chave) {
        int pos = encontrarPosicao(chave);
        if (tabela[pos].ocupado && tabela[pos].chave == chave)
            return tabela[pos].valor;
        return 0;
    }

    // adiciona ou atualiza a frequência da chave
    void atualizar(ll chave, int delta) {
        int pos = encontrarPosicao(chave);
        if (!tabela[pos].ocupado) {
            tabela[pos].ocupado = true;
            tabela[pos].chave = chave;
            tabela[pos].valor = delta;
        } else {
            tabela[pos].valor += delta;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // lê os valores de cada letra (a-z)
    vector<ll> valor(26);
    for (int i = 0; i < 26; i++){
        cin >> valor[i];
    }

    // lê a string
    string s;
    cin >> s;
    int n = s.size();

    // prefixo[i] = soma dos valores até a posição i-1
    vector<ll> prefixo(n + 1, 0);
    for (int i = 1; i <= n; i++){
        prefixo[i] = prefixo[i - 1] + valor[s[i - 1] - 'a'];
    }

    // cria uma tabela hash pra cada letra
    int cap = 1 << 18;
    vector<TabelaHash> hashLetra;
    for (int i = 0; i < 26; i++){
        hashLetra.push_back(TabelaHash(cap));
    }

    ll resposta = 0;

    // marca que o primeiro caractere já apareceu com prefixo[1]
    int letra = s[0] - 'a';
    hashLetra[letra].atualizar(prefixo[1], 1);

    // vai olhando a string a partir da posição 1
    for (int j = 1; j < n; j++){
        int letraJ = s[j] - 'a';

        // soma quantas vezes o prefixo atual já apareceu antes com essa mesma letra
        resposta += hashLetra[letraJ].obter(prefixo[j]);

        // registra esse novo prefixo pra essa letra
        hashLetra[letraJ].atualizar(prefixo[j + 1], 1);
    }

    cout << resposta << "\n";
    return 0;
}