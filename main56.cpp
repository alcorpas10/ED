//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include "SmartFarming2.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    farming2 granja;
    string tipo;
    string plaga, sector;
    vector<pair<string, int>> l1;
    vector<pair<string, string>> l2;
    int n;
    cin >> tipo;
    if (!std::cin)
        return false;
    while (tipo != "FIN") {
        try {
            if (tipo == "alta") {
                cin >> sector >> n;
                granja.alta(sector, n);
            }
            else if (tipo == "datos") {
                cin >> sector >> plaga >> n;
                granja.datos(sector, plaga, n);
            }
            else if (tipo == "fumigar") {
                l2 = granja.fumigar();
                for (const auto& par : l2)
                    cout << "Fumigar la plaga " << par.second << " del sector : " << par.first << endl;
            }
            else if (tipo == "plagas") {
                cin >> sector;
                l1 = granja.plagas(sector);
                cout << "Plagas del sector " << sector << " : ";
                for (const auto& par : l1)
                    cout << par.first << " " << par.second << " ";
                cout << endl;
            }
        }
        catch (domain_error& d) {
            cout << "ERROR: " << d.what() << endl;
        }
        cin >> tipo;
    }
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
    system("PAUSE");
#endif

    return 0;
}
