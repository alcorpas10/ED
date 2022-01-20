//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    bool valido;
    int min;
    int max;
};

// funcion que resuelve el problema
tSol resolver(const bintree<int>& arbol) {
    if (arbol.empty())
        return { true, 0, 0 };
    else {
        tSol left = resolver(arbol.left()), right = resolver(arbol.right());
        if (left.valido && right.valido) {
            if (!arbol.left().empty() && !arbol.right().empty())
                return { left.max < arbol.root() && right.min > arbol.root(), left.min, right.max };
            else {
                if (arbol.left().empty() && arbol.right().empty())
                    return { true, arbol.root(), arbol.root() };
                else if (arbol.left().empty())
                    return { right.min > arbol.root(), arbol.root(), right.max };
                else
                    return { left.max < arbol.root(), left.min, arbol.root() };
            }
        }
        else
            return { false, 0, 0 };
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
    if (sol.valido)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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