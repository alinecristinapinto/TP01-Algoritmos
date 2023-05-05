#ifndef LEITOR_HPP
#define LEITOR_HPP

#include "graph.hpp"

class Leitor {
public:
    Leitor();

    void ler(Graph& grafo);

    virtual ~Leitor();
};

#endif //LEITOR_HPP
