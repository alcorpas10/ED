//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    bool valido;
    int min;
    int max;
};

// funcion que resuelve el problema
bintree<int> resolver(const vector<int>& preV, int ini, int fin) {
    if (ini > fin)
        return {};
    else {
        int raiz = preV[ini], i = ini + 1;
        while (i <= fin && preV[i] < raiz) { i++; }
        return { resolver(preV, ini + 1, i - 1), raiz, resolver(preV, i, fin) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    vector<int> preV;
    string linea;

    // leer los datos de la entrada
    getline(cin, linea);
    if (!std::cin)
        return false;
    stringstream ss(linea);
    int valor;
    while (ss >> valor) {
        preV.push_back(valor);
    }

    //resolver el problema
    bintree<int> arbol = resolver(preV, 0, preV.size() - 1);
    vector<int> postV = arbol.postorder();

    // escribir sol
    for (int i : postV)
        cout << i << " ";
    cout << endl;
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