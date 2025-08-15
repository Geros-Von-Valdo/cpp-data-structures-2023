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

void shellSort(){
	int k = 1;	
	while (k < TAM){
		k = k * 2 + 1;		
	}
	while (k != 1) {
		k = k/2;
		for (int i = k; i <= TAM-1; i++){
			int j = i - k;
			bool found = false;
			while (j >= 0 && not found){
				if (vetor[j] > vetor[j+k]){
					int aux = vetor[j];
    				vetor[j] = vetor[j+k];
    				vetor[j+k] = aux;
            		j = j - k;
					
				} else {
					found = true;
				}					
			}		
		}		
	}	
}

/*
SHELLSORT ( )
1. k <- 1
2. do k <- k * 2 + 1
3. while k < n
4. do
5.    k <- k div 2
6.    for i <- k to n-1
7.          j <- i - k
8.          found <- false
9.          while (j >= 0) and (not found)
10.                if A[j] > A[j+k]
11.                   then troque A[j] <-> A[j+k]
12.                        j <- j - k
13.                   else found <- true
14. while k != 1 */

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
	shellSort();
	cout << endl << endl;
	imprime();
    tempo2 = clock() - tempo1;
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
