// ALEJANDRO CORPAS CALVO
// alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <deque>
#include <tuple>

using namespace std;

// funcion que resuelve el problema
void resolver(int n, int k) {
    deque<pair<int, int>> cola;
    pair<int, int> par;
    int valor, tam;
    cin >> valor;
    cola.push_back({0, valor});
    for (int i = 1; i < n; i++) {
        cin >> valor;
        if (i < k) {
            if (cola.front().second <= valor) {
                for (; !cola.empty() && cola.front().second <= valor;) {
                    cola.pop_front();
                }
            }
        }
        else {
            cout << cola.front().second << " ";
            if (i - cola.front().first >= k) {
                cola.pop_front();
            }
            if (!cola.empty() && cola.front().second <= valor) {
                for (; !cola.empty() && cola.front().second <= valor;) {
                    cola.pop_front();
                }
            }
        }
        cola.push_back({i, valor});
    }
    cout << cola.front().second << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
        return false;
    resolver(n, k);
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