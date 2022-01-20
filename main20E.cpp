//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

using namespace std;

template <typename T>
T minimo(const bintree<T>& arbol, T nullElem) {
    if (arbol.empty()) {
        return nullElem;
    }
    else {
        T left = minimo(arbol.left(), nullElem), right = minimo(arbol.right(), nullElem);
        if (left != nullElem && right != nullElem) {
            return min(min(left, right), arbol.root());
        }
        else {
            if (left != nullElem) return min(arbol.root(), left);
            else if (right != nullElem) return min(arbol.root(), right);
            else return arbol.root();
        }
    }
}

// funcion que resuelve el problema
template <typename T>
T resolver(const bintree<T>& arbol, T nullElem) {
    return minimo(arbol, nullElem);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    string s;
    cin >> c;
    if (!std::cin)
        return false;
    if (c == 'N') {
        cout << resolver(leerArbol(-1), -1) << endl;
    }
    else {
        s = "#";
        cout << resolver(leerArbol(s), s) << endl;
    }
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

/*
// funcion que resuelve el problema
template <typename T>
T resolver(const bintree<T>& arbol) {
    T minimo = *arbol.begin();
    for (T t : arbol) {
        if (t < minimo)
            minimo = t;
    }
    return minimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    cin >> c;
    if (!std::cin)
        return false;

    //resolver el problema
    if (c == 'N') {
        int sol;
        bintree<int> arbol = leerArbol(-1);
        if (arbol.empty())
            sol = -1;
        else
            sol = resolver(arbol);
        // escribir sol
        cout << sol << endl;
    }
    else {
        string sol;
        bintree<string> arbol = leerArbol(string("#"));
        if (arbol.empty())
            sol = "#";
        else
            sol = resolver(arbol);
        // escribir sol
        cout << sol << endl;
    }
    return true;
}*/