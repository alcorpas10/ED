//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

int numBecarios(int k, int jefes) {
    int raiz;
    std::cin >> raiz;
    if (raiz == 0) { // es un arbol vacio
        if (jefes >= k) return 1;
        else return 0;
    }
    else { // leer recursivamente los hijos
        int numBec = 0;
        for (int i = 0; i < raiz; ++i) {
            numBec += numBecarios(k, jefes + 1);
        }
        return numBec;
    }
}

// funcion que resuelve el problema
int resolver(int k) {
    return numBecarios(k, 0);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;
    cin >> k;
    if (!std::cin)
        return false;
    int sol = resolver(k);
    cout << sol << endl;
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
    //system("PAUSE");
#endif

    return 0;
}
