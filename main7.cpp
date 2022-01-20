//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <sstream>
#include "fecha.h"

using namespace std;

// funcion que resuelve el problema
void resolver(int n) {
    fecha f;
    int p;
    stack<pair<fecha, int>> pila;
    for (int i = 0; i < n; i++) {
        cin >> f >> p;
        if (pila.empty()) {
            pila.push({ f, p });
            cout << "NO HAY" << endl;
        }
        else {
            while (!pila.empty() && pila.top().second <= p) {
                pila.pop();
            }
            if (pila.empty())
                cout << "NO HAY" << endl;
            else {
                cout << pila.top().first;
            }
            pila.push({ f, p });
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (!cin)
        return false;
    resolver(n);
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
    system("PAUSE");
#endif

    return 0;
}