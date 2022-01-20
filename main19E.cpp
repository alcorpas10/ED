//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

void frontera(const bintree<int>& arbol, vector<int>& sol) {
    if (arbol.empty()) {} // No es hoja no hace nada
    else if (arbol.left().empty() && arbol.right().empty()) sol.push_back(arbol.root()); //es hoja lo añade
    else {
		frontera(arbol.left(), sol); //frontera del hijo izquierdo
        frontera(arbol.right(), sol); //frontera del hijo derecho
	}
}

// funcion que resuelve el problema
void resolver(const bintree<int>& arbol) {
    vector<int> v;
    frontera(arbol, v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
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
    system("PAUSE");
#endif

    return 0;
}