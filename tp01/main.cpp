#include <iostream>
#include <fstream>
#include "graph.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    string nomeArquivo = argc > 1 ? argv[1] : "";

    ifstream arquivo(nomeArquivo);
    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo com entrada - encerrando programa." << endl;
        return 0;
    }

    int numCidades, numEstradas;
    arquivo >> numCidades >> numEstradas;

    Graph grafo = Graph(numCidades);
    int fonte, destino, peso;

    while (arquivo >> fonte >> destino >> peso) {
        grafo.adicionarAresta(fonte, destino, peso);
    }

    grafo.imprimir();
    
    arquivo.close();
    return 0;
}