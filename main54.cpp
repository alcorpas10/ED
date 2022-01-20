//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int aSalvo;
    int caballeros;
};

tSol resolver(const bintree<char>& arbol, int monstruos) {
    if (arbol.empty())
        return { 0, 0 };
    else {
        tSol left, right;
        int caballeros, aSalvo;
        if (arbol.root() == 'M') {
            left = resolver(arbol.left(), monstruos + 1), right = resolver(arbol.right(), monstruos + 1);
            return { left.aSalvo + right.aSalvo, left.caballeros + right.caballeros };
        }
        else {
            left = resolver(arbol.left(), monstruos), right = resolver(arbol.right(), monstruos);
            caballeros = left.caballeros + right.caballeros;
            aSalvo = left.aSalvo + right.aSalvo;
            if (arbol.root() == 'D') {
                if (caballeros >= monstruos)
                    return { aSalvo + 1, caballeros };
                else
                    return { aSalvo, caballeros };
            }
            else if (arbol.root() == 'C')
                return { aSalvo, caballeros + 1 };
            else
                return { aSalvo, caballeros };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');

    // resolver el problema
    tSol sol = resolver(arbol, 0);

    // mostrar el resultado
    cout << sol.aSalvo << endl;
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