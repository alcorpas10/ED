//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <sstream>

using namespace std;

// funcion que resuelve el problema
bool resolver(string s) {
    stringstream sstream = stringstream(s);
    char c;
    stack<char> pila;
    while (sstream >> c) {
        if (c == '(' || c == '[' || c == '{')
            pila.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (pila.empty())
                return false;
            else if (c == ')' && pila.top() == '(') {
                pila.pop();
            }
            else if (c == ']' && pila.top() == '[') {
                pila.pop();
            }
            else if (c == '}' && pila.top() == '{') {
                pila.pop();
            }
            else return false;
        }
        else
            cin >> c;
    }
    return pila.empty();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string s;
    getline(cin, s);
    if (!cin)
        return false;
    bool sol = resolver(s);
    if (sol)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
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