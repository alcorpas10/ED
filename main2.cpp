// Alejandro Corpas Calvo
// alcorpas10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "pelicula.h"

using namespace std;

/*bool comp(const Peliculas& p1, const Peliculas& p2) {
    return p1 < p2;
}*/

// funcion que resuelve el problema
void resolver(vector<Peliculas>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioon, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numP;
    string nombre;
    Horas horaIni, duracion;
    Peliculas pelicula;
    cin >> numP;
    if (numP == 0) return false;
    vector<Peliculas> v(numP);
    for (int i = 0; i < numP; i++) cin >> v[i];
    resolver(v);

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
