//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using clave = string;
using deportes = string;
using numAlumnos = int;

struct comp {
    bool operator() (const pair<deportes, numAlumnos>& l, const pair<deportes, numAlumnos>& r) const
    {
        if (l.second < r.second)
            return false;
        else if (l.second > r.second)
            return true;
        else
            return l.first < r.first;
    }
} tComparador;

// funcion que resuelve el problema
void resolver(unordered_map<clave, deportes>& mapa, const vector<clave>& aBorrar, const vector<deportes>& vDep) {
    unordered_map<deportes, numAlumnos> mapaSol;
    vector<pair<deportes, numAlumnos>> vSol;
    for (clave c : aBorrar)
        mapa.erase(c);

    for (deportes d : vDep)
        mapaSol[d] = 0;

    for (pair<clave, deportes> par : mapa)
        mapaSol[par.second]++;

    for (pair<deportes, numAlumnos> par : mapaSol)
        vSol.push_back(par);

    sort(vSol.begin(), vSol.end(), tComparador);

    for (pair<deportes, numAlumnos> par : vSol)
        cout << par.first << " " << par.second << endl;
    cout << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    unordered_map<clave, deportes> mapa;
    vector<clave> aBorrar;
    vector<deportes> vDep;
    string nombre;
    clave alumno;
    deportes deporte;
    cin >> nombre;
    if (!std::cin)
        return false;
    while(nombre != "_FIN_") {
        if (isupper(nombre[0])) {
            deporte = nombre;
            vDep.push_back(deporte);
        }
        else {
            alumno = nombre;
            if (mapa.count(alumno)) {
                if (mapa.at(alumno) != deporte)
                    aBorrar.push_back(alumno);
            }
            else
                mapa.insert({ alumno, deporte });
        }
        cin >> nombre;
    }
    resolver(mapa, aBorrar, vDep);
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
