//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "bintree_eda.h"

using namespace std;

struct tSol {
    int max;
    int rel;
};

// funcion que resuelve el problema
bintree<int> resolver(const vector<int>& inO, const vector<int>& preO, int iniI, int finI, int iniP, int finP) {
    if (iniI > finI || iniP > finP)
        return {};
    else {
        int i = iniI;
        int raiz = preO[iniP];
        while (inO[i] != raiz) { i++; }
        return { resolver(inO, preO, iniI, i - 1, iniP + 1, iniP + 1 + (i - 1 - iniI)), raiz, resolver(inO, preO, i + 1, finI, iniP + 1 + (i - 1 - iniI + 1), finP) };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    vector<int> inO, preO;
    string linea;
    int valor;
    getline(cin, linea);
    if (!std::cin)
        return false;

    stringstream ss(linea);
    while (ss >> valor)
        preO.push_back(valor);

    getline(cin, linea);
    stringstream ss2(linea);
    while (ss2 >> valor)
        inO.push_back(valor);

    //resolver el problema
    bintree<int> arbol = resolver(inO, preO, 0, inO.size() - 1, 0, preO.size() - 1);

    // escribir sol
    vector<int> v = arbol.postorder();
    for (int i : v)
        cout << i << " ";
    cout << endl;
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