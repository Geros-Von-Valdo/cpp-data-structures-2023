#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 10;

int vetor[TAM];    /* Arquivo */


//Cria vetor randômico
void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i]=rand()%(TAM*10);
}

void bubbleSort(){
	int pass = 1;
 	bool sorted = false;
 	while (sorted == false and pass < TAM) {
		sorted = true;
    	for (int i=0; i <= TAM-pass-1; i++) {
    		if (vetor[i] > vetor[i+1]) {
    			int aux;
    			aux = vetor[i];
    			vetor[i] = vetor[i+1];
    			vetor[i+1] = aux;
            	sorted = false;
			}         		
		}
		pass = pass + 1;         
	}     
}

/*BUBBLE_SORT ( )
1. pass <- 1
2. sorted <- false
3. while (not sorted) and (pass < n)
4.       sorted <- true
5.       for i <- 0 to n-pass-1
6.             if A[i] > A[i+1]
7.                   troque A[i] <-> A[i+1]
8.                   sorted <- false
9.       pass <- pass + 1 */

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
    cout << endl;
	bubbleSort();
	imprime();
    tempo2 = clock() - tempo1;
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
