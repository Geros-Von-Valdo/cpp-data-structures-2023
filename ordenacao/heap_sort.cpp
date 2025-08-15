#include <iostream>

using namespace std;

const int TAM = 5;
int heap[TAM] {3,10,5,7,10};
int tamanho = 5;


void insereHeap(int valor){
	int i;
	if (tamanho == TAM){
		cout << "Heap cheia ";
		return;
	}
	heap[tamanho] = valor;
	i = tamanho;
	while ( i > 0 && valor > heap[i-1]/2) {
		heap[i] = heap[(i-1)/2];
		i = (i-1)/2;
	}
	heap[i] = valor;
	tamanho++;
}

void heapify(int i){
	int max;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < tamanho && heap[l] > heap[i]){
		max = l;
	} else {
		max = i;
	}
	if (r < tamanho && heap[r] > heap[max]){
		max = r;		
	}
	if (max != i){
		int aux = heap[i];
		heap[i] = heap[max];
		heap[max] = aux;
		heapify(max);
	}
	
}

/*
HEAPIFY (i)
 1. l = 2 * i + 1
 2. r = 2 * i + 2
 3. if l < tam-heap and A[l] > A[i]
 4.    then max <- l
 5.    else max <- i
 6. if r < tam-heap and A[r] > A[max]
 7.    then max <- r
 8. if max != i
 9.    then troque A[i] <-> A[max]
10.         HEAPIFY (max */

void buildHeap(){
	tamanho = TAM;
	for (int j = (TAM/2) - 1; j >= 0; j--){
		heapify(j);
	}
}

/*BUILD-HEAP ( )
1. tam-heap <- n
2. for j <- (n div 2) - 1 downto 0
3.       HEAPIFY (j)*/


void heapSort(){
	buildHeap();
	for (int k = TAM - 1; k >= 1; k--){
		int aux = heap[0];
		heap[0] = heap[k];
		heap[k] = aux;
		tamanho = tamanho - 1;
		heapify(0);
	}
}

/*HEAPSORT ( )
1. BUILD-HEAP ( )
2. for k <- n - 1 downto 1
3.       troque A[0] <-> A[k]
4.       tam-heap <- tam-heap - 1
5.       HEAPIFY (0)*/

void removeMaximo(){
	if (tamanho == 0){
		cout << "Heap Vazia ";
		return;
	}
	heap[0] = heap[tamanho-1];
	heapify(0);
	tamanho--;
}


void imprime(){
	for (int i = 0; i < TAM; i++){
		cout << heap[i] << " ";
	}
}


int main(){
	imprime();
	cout << endl << endl;
	heapSort();
	imprime();
	
}
