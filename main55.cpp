//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include "SmartFarming.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    farming granja;
    string tipo;
    string plaga, sector;
    vector<string> l;
    cin >> tipo;
    if (!std::cin)
        return false;
    while(tipo != "FIN"){
        try {
            if (tipo == "alta") {
                cin >> sector;
                granja.alta(sector);
            }
            else if (tipo == "datos") {
                cin >> sector >> plaga;
                granja.datos(sector, plaga);
            }
            else if (tipo == "fumigar") {
                cin >> plaga;
                l = granja.fumigar(plaga);
                cout << "Fumigar la plaga " << plaga << " en los sectores : ";
                for (string s : l)
                    cout << s << " ";
                cout << endl;
            }
            else if (tipo == "plagas") {
                cin >> sector;
                l = granja.plagas(sector);
                cout << "Plagas del sector " << sector << " : ";
                for (string s : l)
                    cout << s << " ";
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
