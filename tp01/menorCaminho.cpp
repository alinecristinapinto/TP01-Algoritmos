#include "menorCaminho.hpp"
#include <iostream>
#include <queue>

using namespace std;

MenorCaminho::MenorCaminho(){}

void MenorCaminho::calcular(Graph grafo){
    int distancia[grafo.getNumeroVertices()]; // vetor para calcular a menor distancia para cada vertice
    bool visitados[grafo.getNumeroVertices()]; // vetor que guarda os vertices ja visitados para nao expandir

    // fila de prioridade por par(distancia, vertice) - melhor que o min heap por ser mais rapida
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila; 

    // inicializa antecessores e estimativa do caminho (distancia)
    for (int i = 0; i < grafo.getNumeroVertices(); i++){
        distancia[i] = INF;
        visitados[i] = false;
    }

    // distancia para o vertice de origem s eh 0
    distancia[INDEX_VERTICE_ORIGEM] = 0; 

    // para cada vertice pertencente ao Grafo, adiciona-se a estimativa do caminho (distancia) e sua posicao (vertice). 
    // como inicialmente todos os vertices (exceto o de origem) possuem distancia infinita, pode-se inserir apenas o de origem.
    fila.push(make_pair(distancia[INDEX_VERTICE_ORIGEM], VERTICE_ORIGEM));

    while(!fila.empty()){
        pair<int, int> minimo = fila.top(); // pega o min heap da fila
        fila.pop(); // remove minimo da fila

        int u = minimo.second; // pega o vertice u
        int indexU = u - 1; // os vertices se iniciam de 1, mas os vetores de 0

        if(!visitados[indexU]){ 
            visitados[indexU] = true;

            // para cada aresta e = (u, v) pertencente a E deixando u (vertices v adjacentes de u)
            for(Aresta aresta : grafo.getListaAdj()[indexU]){
                cout << aresta.fonte << " " << aresta.peso << " " << aresta.destino << endl;
                int indexDestino = aresta.destino - 1; // os vertices se iniciam de 1, mas os vetores de 0

                // relaxamento (u, v), sendo v = aresta.destino
                if(distancia[indexDestino] > (distancia[indexU] + aresta.peso)){
                    distancia[indexDestino] = distancia[indexU] + aresta.peso;
                    fila.push(make_pair(distancia[indexDestino], aresta.destino));
                }
            }
        }

    }

    cout << "Menor caminho " << distancia[grafo.getNumeroVertices()-1] << endl;
}

MenorCaminho::~MenorCaminho(){}

// for (int i = 0; i < grafo.getNumeroVertices(); i++){
//     cout << "Distancia " << i + 1 << " " << distancia[i] << endl;
//     cout << "Visitado " << i + 1 << " " << visitados[i] << endl;
// }

// while (! fila.empty() ) {
//     pair<int, int> minimo = fila.top(); 
//     cout << "Vertice " << minimo.second << " distancia: " << minimo.first << endl;
//     fila.pop();
// }
