#include <iostream>
#include "graph.hpp"
#include "leitorDados.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Graph grafo;

    Leitor leitor = Leitor();
    leitor.ler(grafo);

    grafo.imprimir();

    return 0;
}