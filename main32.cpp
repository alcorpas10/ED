//ALEJANDRO CORPAS CALVO
//alcorpas10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "set_32.h"

using namespace std;

// funcion que resuelve el problema
void resolver(int numElems) {
    set_ext<int> set;
    int num, numPreg;
    for (int i = 0; i < numElems; i++) {
        cin >> num;
        set.insert(num);
    }
    cin >> numPreg;
    for (int i = 0; i < numPreg; i++) {
        cin >> num;
        set_ext<int>::tSol sol = set.cotaSuperior(num);
        if (sol.cotaEnc) cout << sol.cota << endl;
        else cout << "NO HAY" << endl;
    }
    cout << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0)
        return false;
    resolver(num);
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
