//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <fstream>
#include "deque_eda.h"
#include "queue_eda.h"

using namespace std;

// funcion que resuelve el problema
void resolver(int n) {
    deque<int> colaDoble;
    queue<int> cola;
    int num, tam;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cola.push(num);
    }
    for (int i = 0; i < n; i++) {
        num = cola.front();
        cola.pop();
        if (!colaDoble.empty() && num <= colaDoble.front())
            colaDoble.push_front(num);
        else
            colaDoble.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        cout << colaDoble.front() << " ";
        colaDoble.pop_front();
    }
    cout << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;
    resolver(n);
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