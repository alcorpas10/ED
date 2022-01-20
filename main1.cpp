// Alejandro Corpas Calvo
// alcorpas10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "horas.h"
//#include "pelicula.h"

using namespace std;

// funcion que resuelve el problema
void resolver(const vector<Horas> & v, int numH) {
    Horas hora;
    for (int i = 0; i < numH; i++) {
        try {
            int e = 0;
            cin >> hora;
            while (e < v.size() && hora > v[e]) {
                e++;
            }
            if (e == v.size()) cout << "NO" << endl;
            else cout << v[e] << endl;
        }
        catch (invalid_argument & e) {
            cout << e.what() << endl;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numT, numH;
    cin >> numT >> numH;
    if (numT == 0 && numH == 0) return false;
    vector<Horas> v(numT);
    for (int i = 0; i < numT; i++) cin >> v[i];
    resolver(v, numH);

    // escribir sol
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
    //system("PAUSE");
#endif

    return 0;
}