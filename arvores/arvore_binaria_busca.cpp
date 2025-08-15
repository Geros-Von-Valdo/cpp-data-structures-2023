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
	while (atual != NULL){ 
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
	}
	cout << "Elemento Inserido" << endl;	
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
	while (atual != NULL){ 
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
	cout << "Nao achei" << endl;
}


int main(){
	insere(70);
	insere(90);
	insere(8);
	insere(15);
	emOrdem(raiz);
	cout << endl;
	insere(35);
	insere(5);
	busca(72);
	busca(8);
	cout << endl;
	emOrdem(raiz);
	
	
	
	
}
