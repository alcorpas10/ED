//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_ext20.h"

using namespace std;

// funcion que resuelve el problema
template <typename T>
T resolver(bintree_ext<T>& arbol, T nullElem) {
    return arbol.buscarMinimo(nullElem);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    string s;
    cin >> c;
    if (!std::cin)
        return false;
    if (c == 'N') {
        bintree_ext<int> arbol = leerArbol_ext(-1);
        cout << resolver(arbol, -1) << endl;
    }
    else {
        s = "#";
        bintree_ext<string> arbol = leerArbol_ext(s);
        cout << resolver(arbol, s) << endl;
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}