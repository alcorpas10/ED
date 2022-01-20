// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "deque_insertar.h"

using namespace std;

// funcion que resuelve el problema
void resolver(dequei<int>& cola) {
    int numElems, pos, num;
    cin >> numElems >> pos;
    dequei<int> colaAux;
    for (int i = 0; i < numElems; i++) {
        cin >> num;
        colaAux.push_back(num);
    }
    cola.insertar(colaAux, pos);
    cola.print();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    dequei<int> cola;
    // leer los datos de la entrada
    int numElems, num;
    cin >> numElems;
    if (!std::cin)
        return false;
    for (int i = 0; i < numElems; i++) {
        cin >> num;
        cola.push_back(num);
    }
    resolver(cola);

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