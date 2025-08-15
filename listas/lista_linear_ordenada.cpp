#include <iostream>

using namespace std;

const int TAM = 10;

int lista [TAM];

int tamanho = 0;

void insereLista (int valor) {
	int i;
	if ( tamanho == TAM) {
		cout << "Lista Cheia" << endl;
		return;
	}
	for (i = tamanho; i > 0 && valor < lista[i-1]; i--) {	
		lista[i] = lista[i-1];
	}
	lista[i] = valor;
	cout << "Valor " << lista[i] << " inserido" << endl;
	tamanho++;
}

void recuperaLista(int posicao) {
	if (posicao < 0 || posicao >= tamanho) {
		cout << "Posicao invalida" << endl;
		return;
	}
	cout << "Numero e: " << lista[posicao] << endl;
}

void removeLista(int valor) {
	int i, j;
	if (tamanho == 0) {
		cout << "Lista Vazia" << endl;
		return;
	}
	for (i = 0; i < tamanho && valor >= lista[i]; i++) { // Dá pra buscar de trás pra frente se quiser
		if (lista[i] == valor) {
			for (j = i; j < tamanho-1 ; j++) { // Dava pra usar apenas o i
			lista[j] = lista [j+1];	
			}
			tamanho--;
			cout << "Valor Removido" << endl;
			return;
			
		}
	}
	cout << "Nao Achei" << endl;
}

void buscaLista(int valor) {
	int i, j;
	if (tamanho == 0) {
		cout << "Lista Vazia" << endl;
		return;
	}
	for (i = 0; i < tamanho && valor >= lista[i]; i++) { // Dá pra buscar de trás pra frente se quiser
		if (lista[i] == valor) {
			cout << "Encontrei Valor" << endl;
			return;
			
		}
	}
	cout << "Nao Encontrei" << endl;
}

void imprime (){
	if (tamanho == 0) {
		cout << "Lista Vazia"<< endl;
	}
	int i = 0;
	cout << "A lista: ";
	for (i = 0; i < tamanho; i++) {
		cout << lista[i] << " ";
	}
	cout << endl;
}

int main (){
	
	removeLista(10);
	insereLista(30);
	insereLista(10);
	insereLista(20);
	imprime();
	
	cout << endl;
	
	recuperaLista(1);
	removeLista(20);
	buscaLista(20);
	insereLista(40);
	imprime();
	
	cout << endl; 
	
	removeLista(10);
	removeLista(15);
	buscaLista(40);
	recuperaLista(1);
	imprime();
	
	
	
	
	return 0;
}
