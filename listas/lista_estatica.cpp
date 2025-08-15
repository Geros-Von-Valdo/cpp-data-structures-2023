#include <iostream>

using namespace std;

const int TAM = 10;

int lista [TAM];

int tamanho = 0;

void inserLista(int valor, int posicao) {
	if (tamanho == TAM) {
		cout << "Lista Cheia" << endl;
		return;
	}
	if (poiscao < 0 || posicao > tamanho) {
		cout << "Posicao Invalida" << endl;
		return;
	}
	for (i = tamanho; i < posicao; i--) {
		lista[i] = lista [i-1];
	}
	lista [posicao]
}




