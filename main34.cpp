//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

int resolver() {
    int n;
    cin >> n;
    if (n == 0)
        return 1;
    else {
        int altura = 0;
        for (int i = 0; i < n; i++)
            altura = max(altura, resolver());
        return altura + 1;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    // resolver el ejercicio
    int sol = resolver();

    // escribir sol
    cout << sol << endl;
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