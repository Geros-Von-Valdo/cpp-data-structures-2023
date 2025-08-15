#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 40;

int vetor[TAM];    /* Arquivo */


//Cria vetor randômico
void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i]=rand()%(TAM*10);
}

void insertionSort(){
	for (int k = 1; k <= TAM-1; k++){
		int x = vetor[k];
		int i = k - 1;
		bool found = false;
		while (not found && i >= 0){
			if (vetor[i] > x) {
				int aux = vetor[i + 1];
    			vetor[i + 1] = vetor[i];
    			vetor[i] = aux;
    			i = i - 1;  
			} else {
				found = true;
			}
			  		
		}
	}
}

/*
INSERTION_SORT ( )
1. for k <- 1 to n-1
2.       x <- A[k]
3.       i <- k - 1
4.       found <- false
5.       while (not found) and (i >= 0)
6.             if A[i] > x
7.                then troque A[i+1] <-> A[i]
8.                     i <- i - 1
9.                else found <- true */

void imprime(){
	for (int i=0; i<TAM; i++) {
		cout << vetor[i] << " ";
	}
}

int main() {

    clock_t tempo1;
    clock_t tempo2;
    // Marca o tempo de execução do algoritmo bubbleSort()
    gera();
    imprime();
    tempo1 = clock();
	insertionSort();
	cout << endl << endl;
	imprime();
    tempo2 = clock() - tempo1;
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
