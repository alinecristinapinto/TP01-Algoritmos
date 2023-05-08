#include <iostream>
#include "graph.hpp"
#include "leitorDados.hpp"
#include "menorCaminho.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Leitor leitor = Leitor();
    MenorCaminho menorCaminho = MenorCaminho();
    Graph grafo;

    leitor.ler(grafo);

    cout << menorCaminho.calcularCaminhoPar(grafo) << endl;

    return 0;
}