

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 20;

int vetor[TAM];    /* Arquivo */


//Cria vetor randômico
void gera() {
    int i;
    for (i=0; i<TAM; i++)
        vetor[i]=rand()%(TAM*10);
}

//int p, r;

int partition(int p, int r){
	int piv = vetor[p];
	int i = p - 1;
	int j = r + 1;
	while (true){
		do {
			j = j - 1;
		} while (vetor[j] > piv);
		
		do{
			i = i + 1;			
		} while (vetor[i] < piv);
		
		if (i < j){
			int aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		} else {
			return j;
		}		
	}
}

void quickSort(int p, int r){
	if (p < r) {
		int q = partition(p,r);
			quickSort(p,q);
			quickSort(q + 1, r);
	}
}

/*QUICKSORT (p, r)
1. if p < r
2.    then q <- PARTITION (p, r)
3.         QUICKSORT (p, q)
4.         QUICKSORT (q+1, r)

PARTITION (p, r)
 1. piv <- A[p]
 2. i <- p - 1
 3. j <- r + 1
 4. while (true)
 5.       do j <- j - 1
 6.       while A[j] > piv
 7.       do i <- i + 1
 8.       while A[i] < piv
 9.       if i < j
10.          then troque A[i] <-> A[j]
11.          else return j */

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
	quickSort(0,TAM - 1);
	cout << endl << endl;
	imprime();
    tempo2 = clock() - tempo1;
    cout << "Tempo: " << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
}
