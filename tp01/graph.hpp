#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

// Representa uma aresta do grafo
typedef struct Aresta {
    int fonte;
    int destino;
    int peso; // Distancia entre duas cidades (peso > 0)
} Aresta;

class Graph {
public:
    Graph(int numeroVertices);

    void adicionarAresta(int fonte, int destino, int peso);

    void imprimir(); //funcao apenas para debug

    ~Graph();

private:
    int numeroVertices;
    std::vector<Aresta>* listaAdj;
};

#endif // GRAPH_HPP