// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "lista_removeif.h"
#include "persona.h"

using namespace std;

// funcion que resuelve el problema
void resolver(int a, int b, int c) {
    Persona p;
    listr<Persona> lista;
    for (int i = 0; i < a; i++) {
        cin >> p;
        lista.push_back(p);
    }
    lista.remove_if([b, c](int a) {if (a < b || a > c) return false; else return true; });
    for (Persona p : lista) cout << p << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
        return false;
    resolver(a, b, c);
    cout << "---" << endl;
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