#include <iostream>

using namespace std;

struct no{
	int dado;
	struct no *prox;
};

struct no *lista = NULL;

void insereLista(int valor){
	struct no *atual;
	struct no *anterior;
	struct no *novo;
	atual = lista;
	novo = new (struct no);
	novo -> dado = valor;
	while (atual != NULL && atual -> dado < valor){
		anterior = atual;
		atual = atual -> prox;	
	}
	if (atual == lista) {
		novo -> prox = atual;
		lista = novo;
		
	} else {
		novo -> prox = atual;
		anterior -> prox = novo;
	}
}

void removeLista(int valor){ // Remove baseado no valor
	struct no *atual;
	struct no *anterior;
	atual = lista;
	while (atual != NULL && atual -> dado <= valor) {
		if (valor == atual -> dado) {
			if (atual == lista) {
				lista = lista -> prox;
			} else {
				anterior -> prox = atual -> prox; 
			}
			delete(atual);
			return;
		}
		anterior = atual;
		atual = atual -> prox;
	}
}	


void imprime(){
	struct no *atual;
	atual = lista;
	while (atual != NULL){
		cout << atual -> dado << " ";
		atual = atual -> prox;
	}
}

void buscaLista(int valor){
	struct no *atual;
	atual = lista;
	while(atual != NULL && atual -> dado <= valor) {
		if (valor == atual -> dado){
			cout << "Achei" << endl;
			return;
		}
		atual = atual -> prox;
	}
	cout << "Nao Achei!" << endl;
}

int main(){
	
	insereLista(30);
	insereLista(10);
	insereLista(15);
	buscaLista(5);
	buscaLista(10);
	imprime();
	removeLista(15);
	insereLista(45);
	cout << endl;
	imprime();
}
