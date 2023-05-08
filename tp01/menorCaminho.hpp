#ifndef MENORCAMINHO_HPP
#define MENORCAMINHO_HPP

#include "graph.hpp"

#define INF 0x3f3f3f3f
#define VERTICE_ORIGEM 1
#define INDEX_VERTICE_ORIGEM 0

// Classe baseada no algoritmo de Dijkstra com modificacoes necessarias para esse problema
class MenorCaminho {
public:
    MenorCaminho();

    void calcular(Graph grafo);

    ~MenorCaminho();
};

#endif // MENORCAMINHO_HPP
