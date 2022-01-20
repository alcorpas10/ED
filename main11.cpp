// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "queue_ordenada.h"

using namespace std;

// funcion que resuelve el problema
void resolver(queueo<int>& cola) {
    queueo<int> colaAux;
    int num;
    cin >> num;
    for (; num != 0;) {
        colaAux.push(num);
        cin >> num;
    }
    cola.insertarOrdenado(colaAux);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    queueo<int> cola;
    // leer los datos de la entrada
    int num;
    cin >> num;
    for (; num != 0;) {
        cola.push(num);
        cin >> num;
    }
    resolver(cola);
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
    //system("PAUSE");
#endif

    return 0;
}