// ALEJANDRO CORPAS CALVO
// alcorpas10

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

struct tSol {
    int max;
    int rel;
};

tSol obtenerCamino(const bintree<int>& arbol) {
    if (!arbol.empty()) {
        tSol izq = obtenerCamino(arbol.left()), der = obtenerCamino(arbol.right());
        int nuevoMax = max(izq.max, der.max);
        if (arbol.root() % 2 == 0) {
            int nuevoRel = izq.rel + der.rel + 1;
            if (nuevoRel > nuevoMax)
                nuevoMax = nuevoRel;
            return { nuevoMax, max(izq.rel, der.rel) + 1 };
        }
        else
            return { nuevoMax, 0 };
    }
    else
        return { 0 , 0 };
}

int caminoPares(const bintree<int>& arbol) {
    return obtenerCamino(arbol).max;
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    cout << caminoPares(arbol) << '\n';
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
