#include <iostream>
#include <stdlib.h>

using namespace std;

const int TAM = 10;

int vetor[TAM];

int colisoes = 0;

void inicia(){
	for (int i = 0; i<TAM; i++){
		vetor[i] = -1;
	}
}

int espalha (int chave) {
	return chave % TAM;
}

int reespalha (int pos){
	return (pos+1) % TAM;
}

void insere (int chave){
	int cont = 0;
	int pos;
	pos = espalha(chave);
	while(vetor[pos] != -1 && cont != TAM){
		pos = reespalha(pos);
		cont++;
	}
	if (cont == TAM){
		cout << "Tabela Cheia";
	} else {
		vetor [pos] = chave;
	}
}

void busca (int chave){
	int cont = 0;
	int pos;
	pos = espalha(chave);
	while(vetor[pos] != -1 && cont != TAM && vetor[pos] != chave){
		pos = reespalha(pos);
		cont++, colisoes++;
	}
	if (vetor[pos] == chave){
		cout << "Encontrei a chave" << endl;
	} else {
		cout << "Nao encontrei a chave" << endl;
	}
}

void avaliar(int total) {
	colisoes = 0;
	inicia();
	for (int i = 0; i < total; i++){
		insere (rand()%(TAM*2));
	}
	for (int i = 0; i < 100; i++){
		busca (rand()%(TAM*2));
	}
	cout << (float) colisoes / 100;
	
}

void imprime(){
	for (int i = 0; i < TAM; i++){
		cout << vetor[i] << " ";
	}
	
}

int main() {
	inicia();
	insere(2);	
	insere(50);
	insere(25);
	insere(33);
	insere(12);
	busca(55);
	busca(33);
	imprime();
	//avaliar(8);
	
}
