//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int nodos;
    int hojas;
    int altura;
};

// funcion que resuelve el problema
tSol resolver(const bintree<char>& arbol) {
    if (!arbol.empty()) {
        tSol left = resolver(arbol.left()), right = resolver(arbol.right());
        if (left.nodos == 0 && right.nodos == 0)
            return { 1, 1, 1 };
        else
            return { left.nodos + right.nodos + 1, left.hojas + right.hojas, max(left.altura, right.altura) + 1 };
    }
    else 
        return { 0, 0, 0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');

    //resolver el problema
    tSol sol = resolver(arbol);
    
    // escribir sol
    cout << sol.nodos << " " << sol.hojas << " " << sol.altura << endl;
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