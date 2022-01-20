//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct maximos{
    int max;
    int maxRel;
};

maximos diametro(const bintree<char>& arbol) {
    if (arbol.empty()) {
        return { 0, 0 };
    }
    else {
        maximos left = diametro(arbol.left()), right = diametro(arbol.right());
        if (left.maxRel + right.maxRel + 1 > left.max&& left.maxRel + right.maxRel + 1 > right.max) return { left.maxRel + right.maxRel + 1 , max(left.maxRel, right.maxRel) + 1 };
        else return { max(max(left.max, right.max), max(left.maxRel, right.maxRel) + 1) , max(left.maxRel, right.maxRel) + 1 };
    }
}

// funcion que resuelve el problema
int resolver(const bintree<char>& arbol) {
    return diametro(arbol).max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    int sol = resolver(arbol);
    cout << sol << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
