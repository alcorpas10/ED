// ALEJANDRO CORPAS CALVO
// alcorpas10

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <tuple>

using namespace std;
using pelicula = string;
using cantidad = int;
using actor = string;
using tiempo = int;
using posicion = int;

struct tActor {
    actor a;
    tiempo t;
};

struct datosEmision {
    unordered_map<actor, tiempo> vA;
    cantidad c;
};

bool resuelveCaso() {
    unordered_map<pelicula, datosEmision> mapa1;
    map<actor, tiempo> mapa2;
    pelicula p, pMax;
    actor a;
    tiempo t;
    int numP, numA, numPC, maxPelis = 0, maxActor = 0;
    cin >> numP;
    if (numP == 0)
        return false;
    for (int i = 0; i < numP; i++) {
        cin >> p;
        cin >> numA;
        for (int e = 0; e < numA; e++) {
            cin >> a;
            cin >> t;
            mapa1[p].vA[a] = t;
        }
    }
    cin >> numPC;
    for (int i = 0; i < numPC; i++) {
        cin >> p;
        mapa1[p].c++;
        if (mapa1[p].c >= maxPelis) {
            pMax = p;
            maxPelis = mapa1[p].c;
        }
        for (const auto& a : mapa1[p].vA) {
            mapa2[a.first] += a.second;
            if (mapa2[a.first] > maxActor)
                maxActor = mapa2[a.first];
        }
    }
    cout << maxPelis << " " << pMax << endl;
    cout << maxActor;
    for (const auto& a : mapa2) {
        if (a.second == maxActor)
            cout << " " << a.first;
    }
    cout << endl;
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif
    return 0;
}
