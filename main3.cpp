// Alejandro Corpas Calvo
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "complejo.h"

using namespace std;

// funcion que resuelve el problema
bool resolver(Complejo<float> c, int num) {
    bool sol = true;
    Complejo<float> z;
    for (int i = 0; i < num && sol; i++) {
        z = (z * z) + c;
        if (z.mod() > 2) sol = false;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Complejo<float> cmpx;
    int num;
    cin >> cmpx >> num;
    bool sol = resolver(cmpx, num);
    // escribir sol
    if (sol) cout << "SI" << endl;
    else cout << "NO" << endl;
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