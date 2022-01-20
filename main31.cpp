//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int altura;
    int tipo;
};

tSol tipoArbol(const bintree<char> & arbol) {
    if (arbol.empty())
        return { 0, 2 };
    else {
        tSol left = tipoArbol(arbol.left()), right = tipoArbol(arbol.right());
        if (left.tipo != 0 && right.tipo != 0) {
            if (left.tipo == 2 && right.tipo == 2) {
                if (left.altura == right.altura) return { left.altura + 1, 2 };
                else if (left.altura == right.altura + 1) return { right.altura + 1, 1 };
                else return { max(left.altura, right.altura), 0 };
            }
            else if ((left.tipo == 2 && right.tipo == 1 && left.altura == right.altura + 1) || (left.tipo == 1 && right.tipo == 2 && left.altura == right.altura))
                return { right.altura + 1, 1 };
            else return { max(left.altura, right.altura), 0 };
        }
        else return { max(left.altura, right.altura), 0 };
    }
}

// funcion que resuelve el problema
int resolver(const bintree<char>& arbol) {
    return tipoArbol(arbol).tipo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    int sol = resolver(arbol);
    if (sol == 0) cout << "NADA" << endl;
    else if (sol == 1) cout << "SEMICOMPLETO" << endl;
    else cout << "COMPLETO" << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
