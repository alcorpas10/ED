//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

using namespace std;
using capitulo = int;
using dia = int;

// funcion que resuelve el problema
void resolver(capitulo num) {
    map<capitulo, dia> mapa;
    dia d;
    int max = 0, rel = 0, pos;
    for (int i = 0; i < num; i++) {
        cin >> d;
        if (!mapa.count(d)) {
            mapa.insert({ d, i });
            rel++;
            if (rel > max)
                max = rel;
        }
        else {
            pos = mapa.at(d);
            mapa[d] = i;
            if (rel > max)
                max = rel;
            if (pos < (i - rel))
                rel++;
            else {
                rel = i - pos;
            }
        }
    }
    if (rel > max)
        max = rel;
    cout << max << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    capitulo cap;
    cin >> cap;
    resolver(cap);
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
