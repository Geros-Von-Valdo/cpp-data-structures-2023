#include <iostream>

using namespace std;

struct no{  // Struct pra fica juntinho
	int dado;
	struct no *prox;
};

struct no *topo = NULL;

void push(int valor) {
	struct no *novo; // Auxiliar, struct local
	novo = new(struct no);
	novo -> dado = valor;
	novo -> prox = topo;
	topo = novo;
}

void pop() {
	struct no *apaga; // Auxiliar, struct local
	apaga = new (struct no);
	if (topo == NULL) {
		cout << "A pila esta vazia" << endl;
		return;
	}
	apaga = topo;
	topo = topo -> prox;
	delete(apaga);
}

void topoPilha(){
	if (topo == NULL) {
		cout << "Pilha Vazia" << endl;
		return;
	}
	cout << topo -> dado << endl;
}

void imprime(){
	struct no *aux; // Auxiliar, struct local
	if (topo == NULL) {
		cout << "Pila Vazia" << endl;
		return;
	}
	aux  = topo;
	while (aux != NULL) {
		cout << aux -> dado << " ";
		aux = aux -> prox;
	}
}

int main(){
	
	push(3);
	push(17);
	push(99);
	imprime();
	cout << endl;
	pop();
	pop();
	topoPilha();
	push(5);
	imprime();
	
	return 0;
}


