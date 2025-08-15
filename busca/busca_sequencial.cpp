#include <iostream>

using namespace std;

const int TAM  = 10;

int vetor[TAM] = {25,5,23,10,9,7,4,18,12,34};
int vetor1[TAM + 1] = {25,5,23,10,9,7,4,18,12,34};

void sequencial (int chave){
	int i = 0;
	while (i < TAM && chave!= vetor[i]){
		i++;
	}
	if (i != TAM){
		cout << "Encontrei na posicao " << i << endl;
	} else {
		cout << "Nao encontrei";
	}
}


void sequencialMoverFrente (int chave){
	int j, i = 0;
	while (i < TAM && vetor[i] != chave){
		i++;
	}
	if (i != TAM){
		cout << "Encontrei na posicao " << i << endl;
		if (i != 0){
			for (j = 1; j >= 0 ; j--){
				vetor[j] = vetor[j-1];
			}
			vetor[0] = chave;					
		}		
	} else {
		cout << "Nao encontrei";
	}
}

void sequencialTransposicao (int chave){
	int j, i = 0;
	while (i < TAM && vetor[i] != chave){
		i++;
	}
	if (i != TAM){
		cout << "Encontrei na posicao " << i << endl;
		if (i != 0){
			j = vetor[i];
			vetor[i] = vetor[i-1];
			vetor[i-1] = j;					
		}		
	} else {
		cout << "Nao encontrei";
	}
}

void sequencialSentinela (int chave){ // TAM + 1;
	int i = 0;
	vetor1[TAM] = chave;
	while (vetor[i] != chave){
		i++;
	}
	if (i != TAM){
		cout << "Encontrei na posicao " << i << endl;
	} else {
		cout << "Nao encontrei";
	}
}


int main(){
	
	//sequencial(34);
	//sequencialSentinela(34);
	//sequencialTransposicao(34);
	//sequencialTransposicao(34);
	sequencialMoverFrente(34);
	sequencialMoverFrente(34);
	//sequencialMoverFrente(34);
	
	
}
