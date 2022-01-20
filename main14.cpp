// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

void volcar_pila(stack<char>& pila, string& sol) {
    while (!pila.empty()) {
        sol.push_back(pila.top());
        pila.pop();
    }
}

// funcion que resuelve el problema
string resolver(stack<char>& pila) {
    deque<char> X;
    string resultado;
    int cont = pila.size();
    while (cont != 0) {
        if (cont % 2 == 0) {
            X.push_back(pila.top());
            pila.pop();
        }
        else {
            X.push_front(pila.top());
            pila.pop();
        }
        cont--;
    }
    for (char c : X) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            volcar_pila(pila, resultado);
            resultado.push_back(c);
        }
        else {
            pila.push(c);
        }
    }
    volcar_pila(pila, resultado);
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string frase;
    stack<char> pila;
    getline(cin, frase);
    if (!std::cin)
        return false;
    for (char c : frase) {
        pila.push(c);
    }
    string sol = resolver(pila);
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