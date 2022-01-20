// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "deque_invierte.h"

using namespace std;

// funcion que resuelve el problema
void resolver(dequei<int>& cola) {
    cola.invertir();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    dequei<int> cola;
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (!std::cin)
        return false;
    while (num != 0) {
        cola.push_back(num);
        cin >> num;
    }
    resolver(cola);
    // escribir sol
    cola.print();

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif*/ 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif*/

    return 0;
}