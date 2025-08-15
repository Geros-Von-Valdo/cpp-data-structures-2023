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

void selectionSort() {
	int current;
	for (int i=0; i <= TAM-2; i++) {
		current = i;
    	for (int k = i+1; k <= TAM-1; k++) {
    		if (vetor[current] > vetor[k]) {
    			current = k;
			}		
		}
		int aux = vetor[i];
		vetor[i] = vetor[current];
		vetor[current] = aux;
	}	
}

/*SELECTION_SORT ( )
1. for i <- 0 to n-2
2.       current <- i
3.       for k <- i+1 to n-1
4.             if A[current] > A[k]
5.                then current <- k
6.       troque A[i] <-> A[current]*/

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
    selectionSort();
    tempo2 = clock() - tempo1;
    cout << endl << endl;
    imprime();
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
