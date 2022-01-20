//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int eq;
    int ex;
};

// funcion que resuelve el problema
template <typename T>
tSol resolver(const bintree<T>& arbol) {
    if (arbol.empty())
        return { 0, 0 };
    else {
        tSol left = resolver(arbol.left()), right = resolver(arbol.right());
        if (arbol.root() == 0)
            return { left.eq + right.eq, max(left.ex, right.ex) };
        else
            return { max(left.eq + right.eq, 1), max(left.ex, right.ex) + arbol.root() };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    //resolver el problema
    tSol sol = resolver(arbol);

    // escribir sol
    cout << sol.eq << " " << sol.ex << endl;
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