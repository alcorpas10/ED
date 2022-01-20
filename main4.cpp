// ALEJANDRO CORPAS CALVO
// alcorpas10

#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"

using namespace std;

// funcion que resuelve el problema
int resolver(const Polinomio& datos, int i) {
    return datos.calcularPolinomio(i);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Polinomio p;
    int coe, exp, numC, valor;
    cin >> coe;
    if (!std::cin)
        return false;
    cin >> exp;
    while (coe != 0 || exp != 0) {
        p.anadirMonomio(coe, exp);
        cin >> coe;
        cin >> exp;
    }
    cin >> numC;

    for (int i = 0; i < numC - 1; i++) {
        cin >> valor;
        int sol = resolver(p, valor);

        // escribir sol
        cout << sol << " ";
    }
    cin >> valor;
    int sol = resolver(p, valor);
    // escribir sol
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