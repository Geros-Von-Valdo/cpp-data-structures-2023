#include <iostream>

using namespace std;

struct no {
	int dado;
	struct no  *esq;
	struct no *dir;
};

struct no *raiz = NULL;

void insere(int valor){
	struct no *novo, *atual, *anterior;
	novo = new (struct no);
	novo -> dado = valor;
	novo -> esq = NULL;
	novo -> dir = NULL;
	atual = raiz;
	if (raiz == NULL){
		raiz = novo;
		return;
	}
	atual = raiz;
	while (atual != NULL){ // Conserta isos tlavez
		anterior = atual;
		if (valor < atual -> dado){
			atual = atual -> esq;
		} else {
			atual = atual -> dir;
		}
	}
	if (valor < anterior -> dado){
		anterior -> esq = novo;
	} else {
		anterior -> dir = novo;
		cout << "Elemento Inserido";
	}
}

void emOrdem(struct no *atual){
	if (atual != NULL){
		emOrdem(atual -> esq);
		cout << atual -> dado << " ";
		emOrdem (atual -> dir);
	}
}

void busca(int valor){
	struct no *atual;
	atual = raiz;
	while (atual != NULL){ // Conserta isos tlavez
		if (valor == atual -> dado){
			cout << "Achei";
			return;
		}
		if (valor < atual -> dado) {
			atual = atual -> esq;
		} else {
			atual = atual -> dir;
		}
	}
	cout << "Nao achei";	
}

void insereSemRepetidos(int valor){
	struct no *novo, *atual, *anterior;
	novo = new (struct no);
	novo -> dado = valor;
	novo -> esq = NULL;
	novo -> dir = NULL;
	atual = raiz;
	if (raiz == NULL){
		raiz = novo;
		cout << "Elemento Inserido";
		return;
	}
	atual = raiz;
	while (atual != NULL){ // Conserta isos tlavez
		if (valor == atual -> dado){
			cout << "Numero repetido";
			return;
		}
		anterior = atual;
		if (valor < atual -> dado){
			atual = atual -> esq;
		} else {
			atual = atual -> dir;
		}
	}
	if (valor < anterior -> dado){
		anterior -> esq = novo;
		cout << "Elemento Inserido";
	} else {
		anterior -> dir = novo;
		cout << "Elemento Inserido";
	}
	
}

int main(){
	insereSemRepetidos(35);
	insereSemRepetidos(50);
	insereSemRepetidos(15);
	insereSemRepetidos(25);
	insereSemRepetidos(15);
	insereSemRepetidos(50);
	
	
}
