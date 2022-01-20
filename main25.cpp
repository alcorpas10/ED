//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int numT;
    int caudal;
};

// funcion que resuelve el problema
tSol resolver(const bintree<int>& arbol) {
    if (arbol.empty())
        return { 0, 0 };
    else {
        if (arbol.left().empty() && arbol.right().empty())
            return { 0, 1 };
        else {
            int sum;
            tSol left = resolver(arbol.left()), right = resolver(arbol.right());
            sum = max(0, left.caudal + right.caudal - arbol.root());
            if (sum >= 3)
                return { left.numT + right.numT + 1, sum };
            else
                return { left.numT + right.numT, sum };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    //resolver el problema
    tSol sol = resolver(arbol);
    if (sol.caudal >= 3) sol.numT--;

    // escribir sol
    cout << sol.numT << endl;
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