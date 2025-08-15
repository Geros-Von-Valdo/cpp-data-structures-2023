#include <iostream>

using namespace std;

const int TAM = 10;

struct no {
	int destino;
	struct no * prox;
};

int vertice [TAM];

struct no *arestas[TAM];

int n_vertices = 0;

void insereAresta (int orig, int dest){
	int i = 0, j = 0;
	struct no *atual, *novo, *anterior;
	while (i < n_vertices && vertice[i] != orig){
		i++;
	}
	if (i == n_vertices){
		cout << "Nao existe vertice origem" << endl;
		return;
	}
	while (j < n_vertices && vertice[j] != dest){
		j++;
	}
	if (j == n_vertices){
		cout << "Nao ha vertice destino" << endl;
		return;
	}
	atual =  arestas[i];
	while(atual != NULL){
		if (atual -> destino == dest){
			cout << "Aresta repetida";
			return;
		}
		anterior = atual;
		atual = atual -> prox;
	}
	novo = new (struct no);
	novo -> destino = dest;
	novo -> prox = NULL;
	if (arestas[i] == NULL){
		arestas[i] = novo;
		}else{
			anterior -> prox = novo;
		}
		
	}
	


void removeAresta (int orig, int dest){
	int i = 0, j = 0;
	struct no *atual, *novo, *anterior;
	while (i < n_vertices && vertice[i] != orig){
		i++;
	}
	if (i == n_vertices){
		cout << "Nao existe vertice origem" << endl;
		return;
	}
	while (j < n_vertices && vertice[j] != dest){
		j++;
	}
	if (j == n_vertices){
		cout << "Nao ha vertice destino" << endl;
		return;
	}
	atual =  arestas[i];
	while(atual != NULL){
		if (atual -> destino == dest){
			if (atual == arestas[i]){
				arestas[i] = arestas[i] -> prox;		
			} else {
				anterior -> prox = atual -> prox;
				delete(atual);
				return;			
			}
		}
		anterior = atual;
		atual = atual -> prox;
	}
	cout << "Aresta não encontrada";
}

void imprimeGrafo(){
	struct no *atual;
	for (int i=0; i < n_vertices; i++){
		cout << vertice[i] << "->";
		atual = arestas[i];
		while(atual != NULL){
			cout << "<" << vertice[i] << "," << atual->destino << ">";
			atual = atual -> prox;
		}
		cout << endl;
	}
}

void insereVertice(int valor){
	if (n_vertices < TAM){
		for (int i = 0; i < n_vertices; i++){
			if (vertice[i] == valor){
				cout << "Vertice repetido";
				return;
			}
		}
		vertice [n_vertices] = valor;
		n_vertices++;
	}
	else {
		cout << "Nao ha espaco no vetor";
	}
}

int main(){
	insereVertice(45);
	insereVertice(20);
	insereVertice(33);
	insereAresta(45,20);
	insereAresta(45,33);
	insereAresta(33,45);
	insereAresta(20,45);
	
	
	
	
	
	imprimeGrafo();
	removeAresta(20,45);
	imprimeGrafo();
	
	
	
	
	
}
