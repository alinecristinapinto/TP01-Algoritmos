#include "leitorDados.hpp"
#include <iostream>

using namespace std;

Leitor::Leitor(){}

void Leitor::ler(Graph& grafo){
    int numCidades, numEstradas;
    cin >> numCidades >> numEstradas;

    grafo = Graph(numCidades);

    int fonte, destino, peso;
    for(int i=0; i<numEstradas; i++){
        cin >> fonte >> destino >> peso;
        grafo.adicionarAresta(fonte, destino, peso);
    }
}

Leitor::~Leitor(){}