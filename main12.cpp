// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;

// funcion que resuelve el problema
int resolver(int a, int b) {
    queue<int> cola;
    int alumno = 0, sol;
    for (int i = 1; i <= a; i++) {
        cola.push(i);
    }
    while (cola.size() != 1) {
        for (int i = 0; i < b; i++) {
            alumno = cola.front();
            cola.pop();
            cola.push(alumno);
        }
        cola.pop();
    }
    sol = cola.front();
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
        return false;

    int sol = resolver(a, b);

    // escribir sol
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
    system("PAUSE");
#endif

    return 0;
}