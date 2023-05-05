#include "menorCaminho.hpp"
#include <iostream>
#include <queue>

using namespace std;

MenorCaminho::MenorCaminho(/* args */) {
}

void MenorCaminho::calcular(Graph grafo){
    int antecessor[grafo.getNumeroVertices()]; // vetor para armazenar os vertices inclusos
    int distancia[grafo.getNumeroVertices()]; // vetor para calcular a menor distancia para cada vertice
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila; // fila de prioridade por par(distancia, vertice) - melhor que o min heap por ser mais rapida

    // inicializa antecessores e estimativa do caminho (distancia)
    for (int i = 1; i <= grafo.getNumeroVertices(); i++){
        distancia[i] = INF;
        antecessor[i] = -1;
    }

    distancia[VERTICE_ORIGEM] = 0; // distancia para o vertice de origem s eh 0

    // para cada vertice pertencente ao Grafo, adiciona-se a estimativa do caminho (distancia) e sua posicao (vertice). 
    // como inicialmente todos os vertices (exceto o de origem) possuem distancia infinita, pode-se inserir apenas o de origem.
    fila.push(make_pair(distancia[VERTICE_ORIGEM], VERTICE_ORIGEM));

    while(!fila.empty()){
        pair<int, int> minimo = fila.top(); // pega o min heap da fila
        fila.pop(); // remove minimo da fila

        // para cada aresta e = (u, v) pertencente a E deixando u (vertices v adjacentes de u)
        int u = minimo.second; // pega o vertice u
        for(Aresta aresta : grafo.getListaAdj()[u]){
            // relaxamento (u, v), sendo v = aresta.destino
            if(distancia[aresta.destino] > (distancia[u] + aresta.peso)){
                distancia[aresta.destino] = distancia[u] + aresta.peso;
                fila.push(make_pair(distancia[aresta.destino], aresta.destino));
                antecessor[aresta.destino] = u;
            }
        }
    }

    cout << "Menor caminho " << distancia[grafo.getNumeroVertices()] << endl;
}

MenorCaminho::~MenorCaminho() {
}
