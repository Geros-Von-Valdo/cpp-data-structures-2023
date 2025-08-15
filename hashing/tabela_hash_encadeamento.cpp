#include <iostream>

using namespace std;

const int TAM = 10;

struct no{
	int dado;
	struct no *prox;
};

struct no *vetor [TAM];

void inicia(){
	for (int i=0; i<TAM; i++){
		vetor[i] = NULL;	
	}
}

int espalha(int chave){
	return chave % TAM;
}

void insere(int chave){
	int pos;
	struct no *atual, *anterior, *novo;
	pos = espalha(chave);
	atual = vetor[pos];
	while (atual != NULL ){
		if (atual -> dado == chave){
			cout << "Repetido" << endl;
			return;
		}
		anterior = atual;
		atual = atual -> prox;
	}
	novo = new (struct no);
	novo -> dado = chave;
	novo -> prox = NULL;
	if (vetor[pos] == NULL){
		vetor[pos] = novo;
	} else {
		anterior -> prox = novo;
	}
}

void busca(int chave){
	int pos;
	struct no *atual;
	pos = espalha (chave);
	atual = vetor[pos];
	while (atual != NULL){
		if (atual -> dado == chave){
			cout << "Encontrei";
			return;			
		}
		atual = atual -> prox;
	}
	cout<< "Nao econtrei" << endl;
}



void imprime(){
	struct no *atual;
	int pos;
	for (pos = 0; pos < TAM; pos++){
		cout << pos << " -> ";
		atual = vetor[pos];
		while(atual != NULL){
			cout << atual -> dado << " ";
			atual  = atual -> prox;
		}
		cout << endl;
	}
}

int main(){
	
	inicia();
	insere(30);
	insere(29);
	insere(49);
	insere(22);
	insere(45);
	insere(4259);
	insere(35);
	insere(35);
	busca(99);
	insere(99);
	imprime();
	busca(99);
	
	
}
