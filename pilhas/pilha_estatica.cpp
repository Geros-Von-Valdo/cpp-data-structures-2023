#include <iostream>
using namespace std;

const int TAM = 10;

int pilha [TAM];

int topo = -1;

void push (int valor) {
    if (topo == TAM-1) {
        cout << "A pilha esta cheia"<< endl;
        return;
    }
    topo++;
    pilha [topo] = valor;
    cout << "O valor foi inserido: " << valor << endl;
}

void pop () {
    if (topo == -1) {
        cout << "A pilha esta vazia" << endl;
        return;
    }
    topo = topo -1;
    cout << "Valor Removido" << endl;
}

void verTopo() {
    if (topo == -1) {
        cout << " A pilha esta vazia" << endl;
        return;
    }
    cout << "O valor que esta no topo e: " << pilha [topo] << endl;
}

void imprime() {
    if (topo == -1) {
        cout << " A pilha esta vazia" << endl;
        return;
    }
    cout << "Os valores da pilha sao: " << endl;
    for (int i = 0; i <= topo; i++) {
        cout << pilha [i] << " ";
    }

}


int main() {

    push(10);
    push(20);
    push(30);
    verTopo();
    pop();
    imprime();

    return 0;
}
