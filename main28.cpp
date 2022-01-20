//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include "bintree_28.h"

using namespace std;

// funcion que resuelve el problema
void resolver(bintree_ext<int>& arbol) {
    bintree_ext<int>::tSol sol = arbol.divisor7();
    if (sol.enc) cout << sol.num << " " << sol.nivel << endl;
    else cout << "NO HAY" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree_ext<int> arbol = leerArbol_ext(-1);
    resolver(arbol);
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

/*
struct tSol {
    bool enc;
    int num;
    int alt;
};

bool primo(int n) {
    if (n == 0 || n == 1 || n == 4) return false;
    for (int x = 2; x < n / 2; x++) {
        if (n % x == 0) return false;
    }
    return true;
}

// funcion que resuelve el problema
tSol resolver(const bintree<int>& arbol) {
    if (!arbol.empty() && !primo(arbol.root())) {
        queue<pair<int, bintree<int>>> pendientes;
        pendientes.push({ 1, arbol });
        while (!pendientes.empty()) {
            bintree<int> sig = pendientes.front().second;
            int alt = pendientes.front().first;
            pendientes.pop();
            if (sig.root() % 7 == 0)
                return { true, sig.root(), alt };
            if (!sig.left().empty() && !primo(sig.left().root()))
                pendientes.push({ alt + 1, sig.left() });
            if (!sig.right().empty() && !primo(sig.right().root()))
                pendientes.push({ alt + 1, sig.right() });
        }
        return { false, 0, 0 };
    }
    else
        return { false, 0, 0 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    //resolver el problema
    tSol sol = resolver(arbol);

    // escribir sol
    if (sol.enc)
        cout << sol.num << " " << sol.alt << endl;
    else
        cout << "NO HAY" << endl;
}*/
