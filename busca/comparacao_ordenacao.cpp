#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAM = 9999;

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

int scratch[TAM];
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

void imprime(){
	for (int i=0; i<TAM; i++) {
		cout << vetor[i] << " ";
	}
}



int main() {
	
	clock_t tempo1;
    clock_t tempo2;
	
	//Bubble
    gera();
    tempo1 = clock();
	bubbleSort();
    tempo2 = clock() - tempo1;
    cout << "Bubble Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    //Insertion
    gera();
    tempo1 = clock();
	insertionSort();
    tempo2 = clock() - tempo1;
    cout << "Insertion Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    //Selection
    gera();
    tempo1 = clock();
	selectionSort();
    tempo2 = clock() - tempo1;
    cout << "Selection Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    //Shell
    gera();
    tempo1 = clock();
	shellSort();
    tempo2 = clock() - tempo1;
    cout << "Shell Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    //Merge
    gera();
    tempo1 = clock();
	mergeSort(0, TAM - 1);
    tempo2 = clock() - tempo1;
    cout << "Merge Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    //Quicksort
    gera();
    tempo1 = clock();
	quickSort(0, TAM - 1);
    tempo2 = clock() - tempo1;
    cout << "Quick Sort: ";
    cout << (float) tempo2/CLOCKS_PER_SEC << " s" << endl;
    
    
    
}
