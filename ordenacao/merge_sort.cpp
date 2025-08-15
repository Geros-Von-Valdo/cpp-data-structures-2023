#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 40;

int vetor[TAM];    /* Arquivo */
int scratch[TAM];

//Cria vetor randômico
void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i]=rand()%(TAM*10);
}

void mergeSort(int lo, int hi){
	int L;
	int H;
	if (lo < hi) {
		int mid = (lo +hi) / 2;
		mergeSort(lo, mid);
		mergeSort(mid+1, hi);
		L = lo;
		H = mid + 1;
		for (int k = lo; k <= hi; k++){
			if (L <= mid && (H > hi || vetor[L] < vetor[H])){
				scratch[k] = vetor[L];
				L = L + 1;
			} else {
				scratch[k] = vetor[H];
				H = H + 1;			
			}
		}
		for (int k = lo; k <= hi; k++){
			vetor[k] = scratch[k];
		}
	}	
}

/*MERGESORT (lo, hi)
1. if lo < hi then
2.    mid <- (lo + hi) / 2
3.    MERGESORT (lo, mid)
4.    MERGESORT (mid+1, hi)
5.    L <- lo
6.    H <- mid + 1
7.    for k <- lo to hi
8.          if L <= mid and (H > hi or A[L] < A[H])
9.              then scratch[k] <- A[L]
10.                  L <- L + 1
11.             else scratch[k] <- A[H]
12.                  H <- H + 1
13.    for k <- lo to hi
14.          A[k] <- scratch[k]*/

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
	mergeSort(0, TAM-1);
    tempo2 = clock() - tempo1;
    cout << endl << endl;
    imprime();
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
