#include <iostream>
#include <cstdlib>

using namespace std;

const int TAM=10;

int vetor[TAM];

void geraVetor() {
    int i;
    cout <<  "Gerando vetor randomico...." << endl;
    for (i=0; i<TAM; i++) {
        vetor[i]=rand()%(TAM*10);
    }
}

struct noBB {
	int dadoBB;
	struct noBB  *esqBB;
	struct noBB *dirBB;
};

struct noBB *raizBB = NULL;

struct noAVL {
    int dado;
    struct noAVL *esq;
    struct noAVL *dir;
    int bal;
};

struct no *raizAVL = NULL;
      
void insere() {
    for (int valor = 0; valor<TAM; valor++) {
        struct noBB *novoBB, *atualBB, *anteriorBB;
		novoBB = new (struct noBB);
		novoBB -> dadoBB = vetor[valor];
		novoBB -> esqBB = NULL;
		novoBB -> dirBB = NULL;
		atualBB = raizBB;
		if (raizBB == NULL){
			raizBB = novoBB;
			return;
		}
		atualBB = raizBB;
		while (atualBB != NULL){ 
			anteriorBB = atualBB;
			if (vetor[valor] < atualBB -> dadoBB){
				atualBB = atualBB -> esqBB;			
			} else {
				atualBB = atualBB -> dirBB;		
			}	
		}
		if (vetor[valor] < anteriorBB -> dadoBB){
			anteriorBB -> esqBB = novoBB;	
		} else {
			anteriorBB -> dirBB = novoBB;		
		} 
    }
}

void emOrdem(struct noBB *atual){
	if (atual != NULL){
		emOrdem(atual -> esqBB);
		cout << atual -> dadoBB << " ";
		emOrdem (atual -> dirBB);
	}
} 


void imprime() {
    for (int i=0; i<TAM; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main() {
	geraVetor();
	imprime();
	insere();
	emOrdem(raizBB);
}
