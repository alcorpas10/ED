//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
using clave = string;
using valor = int;

// funcion que resuelve el problema
void resolver(map<clave, valor>& mapaIni, map<clave, valor>& mapaFin) {
    vector<clave> cambio, menos;
    for (pair<clave, valor> par : mapaIni) {
        if (mapaFin.count(par.first)) {
            if (par.second != mapaFin[par.first])
                cambio.push_back(par.first);
            mapaFin.erase(par.first);
        }
        else
            menos.push_back(par.first);
    }
    if (mapaFin.empty() && menos.empty() && cambio.empty()) {
        cout << "Sin cambios" << endl;
    }
    else {
        if (!mapaFin.empty()) {
            cout << "+ ";
            for (pair<clave, valor> c : mapaFin)
                cout << c.first << " ";
            cout << endl;
        }
        if (!menos.empty()) {
            cout << "- ";
            for (clave c : menos)
                cout << c << " ";
            cout << endl;
        }
        if (!cambio.empty()) {
            cout << "* ";
            for (clave c : cambio)
                cout << c << " ";
            cout << endl;
        }
    }
    cout << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    map<clave, valor> mapaIni, mapaFin;
    clave c;
    valor v;
    string linea;
    getline(cin, linea);
    stringstream ss1(linea);
    while (ss1 >> c) {
        ss1 >> v;
        mapaIni.insert({ c, v });
    }
    getline(cin, linea);
    stringstream ss2(linea);
    while (ss2 >> c) {
        ss2 >> v;
        mapaFin.insert({ c, v });
    }
    resolver(mapaIni, mapaFin);
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
    cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
