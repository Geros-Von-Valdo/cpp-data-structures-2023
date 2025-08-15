#include <iostream>

using namespace std;

const int TAM = 10;
int fila [TAM];
int inicio = 0;
int fim = 0;
int contador = 0;

void enqueue(int valor) {
	if (contador == TAM) {
		cout << "A fila esta cheia." << endl;
		return;
	}
	contador++;
	fila [fim] = valor;
	cout << "O valor " << valor << " foi inserido." << endl;
	if (fim == TAM-1) {
		fim = 0;
		return;
	}
	fim++;
}
void dequeue() {
	if (contador == 0) {
		cout << "A fila esta vazia." << endl;
		return;
	}
	contador--;
	cout << "O valor foi removido." << endl;
	if (inicio == TAM-1) {
		inicio = 0;
		return;
	}
	inicio++;
}

void frente () {
	if (contador == 0) {
		cout << "A fila esta vazia" << endl;
		return;
	}
	cout << "O valor da frente: " << fila [inicio] << endl;
	
}

void imprime() {
	int i = 0;
	int j = 0;
	
	if (contador == 0) {
		cout << "A fila esta vazia." << endl;
		return;
	}
	cout << "Os valores sao: " <<endl;
	j = inicio;
	while (i < contador) {
		cout << fila [j] << " ";
		if (j == TAM-1){
			j = 0;
		} else
		j++;
		i++;
	}
}

int main() {
	
	dequeue();
	enqueue(10);
	enqueue(20);
	enqueue(30);
	frente();
	dequeue();
	enqueue(40);
	frente();
	imprime();
	
	
	return 0;
}
