//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_practica.h"

using namespace std;

// funcion que resuelve el problema
void resolver(dequep<int>& cola, dequep<int>& colaAux) {
    cola.combinar(colaAux);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    dequep<int> cola, colaAux;
    int nElems, num;
    cin >> nElems;
    for (int i = 0; i < nElems; i++) {
        cin >> num;
        cola.push_back(num);
    }
    cin >> nElems;
    for (int i = 0; i < nElems; i++) {
        cin >> num;
        colaAux.push_back(num);
    }
    resolver(cola, colaAux);
    // escribir sol
    cola.print();
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