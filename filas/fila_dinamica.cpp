#include <iostream>

using namespace std;

struct no{
	int dado;
	struct no* prox;
};

struct no *inicio = NULL;
struct no *fim = NULL;

void enqueue(int valor){
	struct no *novo;
	
	novo = new (struct no);
	novo -> dado = valor;
	novo -> prox = NULL;
	
	if (fim == NULL){
		fim = novo;
		inicio = novo;
	} else {
		fim -> prox = novo;
		fim = novo;
	}	
}

void dequeue(){
	struct no *apaga;
	if (inicio == NULL) {
		cout << "A fila esta vazia" << endl;
		return;
	}
	apaga = inicio;
	inicio = inicio -> prox; // Atualiza pro proximo valor dele mesmo
	delete(apaga);
	if (inicio == NULL) {
		fim = NULL;
	}	
}

void inicioFila(){
	if (inicio == NULL) {
		cout << "Fila vazia " << endl;
		return;
	}
	cout << "Inicio e " << inicio->dado << endl;
}

void imprime() {
	struct no *aux;
	
	if (inicio == NULL){
		cout << "Fila Vazia" << endl;
		return;
	}
	for ( aux = inicio; aux != NULL;aux = aux -> prox) {
		cout << aux -> dado << " ";
	}
}

int main(){
	
	enqueue(50);
	enqueue(20);
	enqueue(10);
	inicioFila();
	imprime();
	dequeue();
	dequeue();
	enqueue(40);
	enqueue(7);
	cout << endl;
	imprime();
	
	
}
