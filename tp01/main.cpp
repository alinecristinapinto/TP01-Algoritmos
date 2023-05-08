#include <iostream>
#include "graph.hpp"
#include "leitorDados.hpp"
#include "menorCaminho.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
    Leitor leitor = Leitor();
    MenorCaminho menorCaminho = MenorCaminho();
    Graph grafo;
    int menorCaminhoPar;

    leitor.ler(grafo);

    menorCaminhoPar = menorCaminho.calcularCaminhoPar(grafo);

    cout << menorCaminhoPar << endl;

    return 0;
}