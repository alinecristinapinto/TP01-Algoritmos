#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(){}

Graph::Graph(int numeroVertices){
    this->numeroVertices = numeroVertices;
    this->listaAdj = new std::vector<Aresta>[numeroVertices];
}

void Graph::adicionarAresta(int fonte, int destino, int peso){
    Aresta aresta = Aresta();

    aresta.fonte = fonte;
    aresta.destino = destino;
    aresta.peso = peso;

    this->listaAdj[fonte].push_back(aresta);
}

int Graph::getNumeroVertices(){
    return this->numeroVertices;
}

vector<Aresta>* Graph::getListaAdj(){
    return this->listaAdj;
}

void Graph::imprimir(){
    for(int i = 1; i <= this->numeroVertices-1; i++){
        for (Aresta v: this->listaAdj[i]) {
            cout << "Fonte: " << v.fonte << ", Destino: " << v.destino << ", Peso: " << v.peso << endl;
        }
    }
}

Graph::~Graph(){}
