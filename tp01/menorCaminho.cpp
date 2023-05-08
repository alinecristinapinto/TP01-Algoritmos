#include "menorCaminho.hpp"
#include <iostream>
#include <queue>

using namespace std;

MenorCaminho::MenorCaminho(){}

int MenorCaminho::calcularCaminhoPar(Graph grafo){
    // guarda o menor caminho para dado vertice u considerando que da origem a ele foram percorridos um numero de vertices pares com pesos pares
    int distanciaComNumArestasPar[grafo.getNumeroVertices()]; 
    // guarda o menor caminho para dado vertice u considerando que da origem a ele foram percorridos um numero de vertices impares com pesos pares
    int distanciaComNumArestasImpar[grafo.getNumeroVertices()];

    // fila de prioridade por par(distancia, vertice) ordenado de forma crescente - melhor que o min heap por ser mais rapida
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila; 

    // inicializa as estimativas de caminho (distancias)
    for (int i = 0; i < grafo.getNumeroVertices(); i++){
        distanciaComNumArestasPar[i] = INF;
        distanciaComNumArestasImpar[i] = INF;
    }

    // a distancia para o vertice de origem s eh 0
    distanciaComNumArestasPar[INDEX_VERTICE_ORIGEM] = 0;

    // para cada vertice pertencente ao Grafo, adiciona-se a estimativa do caminho e sua posicao. 
    // como inicialmente todos os vertices (exceto o de origem) possuem distancia infinita, pode-se inserir apenas o de origem.
    fila.push(make_pair(distanciaComNumArestasPar[INDEX_VERTICE_ORIGEM], VERTICE_ORIGEM));

    while(!fila.empty()){
        pair<int, int> minimo = fila.top(); // pega o min heap da fila
        fila.pop(); // remove minimo da fila

        int u = minimo.second; // pega o vertice u
        int indiceU = u - 1; // os vertices se iniciam de 1, mas os vetores de 0

        // para cada aresta e = (u, v) pertencente a E deixando u (vertices v adjacentes de u)
        for(Aresta aresta : grafo.getListaAdj()[indiceU]){
            // verifica se peso ate o vizinho eh par, caso seja impar o vertice eh desconsiderado das estimativas de caminho
            if(aresta.peso % 2 == 0){
                int indiceDestino = aresta.destino - 1; // os vertices se iniciam de 1, mas os vetores de 0

                // para se ter uma distancia de arestas par de um ponto, eh preciso olhar para o vertice que veio de uma distancia
                // de arestas impar, visto que ao adicionar a distancia, estamos somando + 1 aresta ao conjunto, logo um numero
                // impar + 1 = numero par de arestas
                // se a distancia futura eh maior que a distancia atual impar + peso, entao atualiza, e o numero de arestas se mantem par
                if(distanciaComNumArestasPar[indiceDestino] > (distanciaComNumArestasImpar[indiceU] + aresta.peso)){
                    distanciaComNumArestasPar[indiceDestino] = distanciaComNumArestasImpar[indiceU] + aresta.peso;
                    fila.push(make_pair(distanciaComNumArestasPar[indiceDestino], aresta.destino));
                }

                // mesma explicacao do if anterior, um numero par + 1 = numero impar
                // se a distancia futura eh maior que a distancia atual par + peso, entao atualiza, e o numero de arestas se mantem impar
                if(distanciaComNumArestasImpar[indiceDestino] > (distanciaComNumArestasPar[indiceU] + aresta.peso)){
                    distanciaComNumArestasImpar[indiceDestino] = distanciaComNumArestasPar[indiceU] + aresta.peso;
                    fila.push(make_pair(distanciaComNumArestasImpar[indiceDestino], aresta.destino));
                }
            }
        }
    }

    // pega a ultima posicao do vetor que corresponde ao vertice de chegada
    int distanciaDestinoFinal = distanciaComNumArestasPar[grafo.getNumeroVertices()-1];

    // se a distancia final eh infinito, entao nao foi possivel encontrar um caminho com arestas e distancias pares para o destino
    return distanciaDestinoFinal == INF ? -1 : distanciaDestinoFinal;
}

MenorCaminho::~MenorCaminho(){}
