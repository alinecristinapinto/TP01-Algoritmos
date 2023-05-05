#ifndef MENORCAMINHO_HPP
#define MENORCAMINHO_HPP

#include "graph.hpp"

#define INF 0x3f3f3f3f
#define VERTICE_ORIGEM 1

// Classe baseada no algoritmo de Dijkstra com modificacoes necessarias para esse problema
class MenorCaminho {
public:
    MenorCaminho(/* args */);

    void calcular(Graph grafo);

    ~MenorCaminho();
};

#endif // MENORCAMINHO_HPP
