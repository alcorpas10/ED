//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;


// funcion que resuelve el problema
bool resolver(const bintree<char>& left, const bintree<char>& right) {
    if (left.empty() && right.empty())
        return true;
    else if ((left.empty() && !right.empty()) || (right.empty() && !left.empty()))
        return false;
    else {
        bool izq = resolver(left.left(), right.right()), der = resolver(left.right(), right.left());
        return izq && der;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bool sol = true;
    bintree<char> arbol = leerArbol('.');

    //resolver el problema
    if (!arbol.empty())
        sol = resolver(arbol.left(), arbol.right());

    // escribir sol
    if (sol)
        cout << "SI " << endl;
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