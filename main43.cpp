// ALEJANDRO CORPAS CALVO
// alcorpas10

#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;
using numero = int;
using cantidad = int;

void mostrarCaso(const unordered_map<numero, cantidad>& mapa, queue<numero>& cola) {
    numero n;
    cantidad c;
    while (!cola.empty()) {
        n = cola.front();
        cola.pop();
        c = mapa.at(n);
        cout << n << " " << c << endl;
    }
    cout << "---" << endl;
}

bool resuelveCaso() {
    unordered_map<numero, cantidad> mapa;
    queue<numero> cola;
    int n;
    numero num;
    cin >> n;
    if (!std::cin)
        return false;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mapa[num]++;
        if (mapa[num] == 1)
            cola.push(num);
    }
    mostrarCaso(mapa, cola);
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
    system("PAUSE");
#endif
    return 0;
}
