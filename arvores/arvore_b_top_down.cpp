#include <iostream>
#include <cstdlib>

using namespace std;

const int ORDEM = 10;
const int MAX_CHAVES = ORDEM-1;

struct no {
    int dado[ORDEM-1];
    struct no *filhos[ORDEM];
    int n_chaves;
};

struct no *raiz = NULL;

// Cria um novo nó folha com uma chave
struct no* cria_no(int valor) {
    struct no *novo = new no;
    novo->dado[0] = valor;
    for (int i = 0; i < ORDEM; i++)
        novo->filhos[i] = NULL;
    novo->n_chaves = 1;
    return novo;
}

// Encontra a posição de inserção da chave dentro do nó
int encontra_chave(struct no *atual, int valor) {
    int i = 0;
    while (i < atual->n_chaves && valor > atual->dado[i])
        i++;
    return i;
}

// Insere valor em um nó folha que ainda tem espaço
void insere_folha(struct no *atual, int valor) {
    int i;
    for (i = atual->n_chaves; i > 0 && valor < atual->dado[i-1]; i--)
        atual->dado[i] = atual->dado[i-1];
    atual->dado[i] = valor;
    atual->n_chaves++;
}

// Percurso em ordem da árvore
void percurso(struct no *atual) {
    if (atual != NULL) {
        for (int i = 0; i < atual->n_chaves; i++) {
            percurso(atual->filhos[i]);
            cout << atual->dado[i] << " ";
        }
        percurso(atual->filhos[atual->n_chaves]);
    }
}

// Função para encontrar nó e posição
struct no* encontra_no(int valor, int &posicao) {
    struct no *atual = raiz;
    struct no *anterior = NULL;
    while (atual != NULL) {
        posicao = encontra_chave(atual, valor);
        anterior = atual;
        if (posicao < atual->n_chaves && valor == atual->dado[posicao])
            return atual; // valor já existe
        atual = atual->filhos[posicao];
    }
    return anterior;
}

// Insere valor na árvore (simplificado, sem split)
void insere(int valor) {
    if (raiz == NULL) {
        raiz = cria_no(valor);
        return;
    }
    int posicao;
    struct no *atual = encontra_no(valor, posicao);

    // valor já existe
    if (atual->dado[posicao] == valor)
        return;

    // se ainda há espaço no nó
    if (atual->n_chaves < MAX_CHAVES) {
        insere_folha(atual, valor);
        return;
    }

    // simplificação: cria novo nó e coloca como filho
    struct no *novo = cria_no(valor);
    atual->filhos[posicao] = novo;
}

// Busca valor na árvore
void busca(int valor) {
    int posicao;
    struct no *atual = encontra_no(valor, posicao);
    if (atual != NULL && atual->dado[posicao] == valor)
        cout << "Achei " << valor << endl;
    else
        cout << "Nao achei " << valor << endl;
}

int main() {
    setlocale(LC_ALL, "");

    insere(50);
    insere(20);
    insere(70);
    insere(80);
    insere(10);
    insere(30);
    insere(90);
    insere(40);

    cout << "Percurso em ordem: ";
    percurso(raiz);
    cout << endl;

    busca(30);
    busca(100);

    return 0;
}
