//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include "ParqueNatural.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    string tipo, ecosistema, especie;
    int ejemplares, n;
    pNatural parque;
    cin >> tipo;
    while (tipo != "FIN" /*!cin Con esto no me funcionaba*/) {
        try {
            if (tipo == "an_ecosistema") {
                cin >> ecosistema;
                parque.an_ecosistema(ecosistema);
            }
            else if (tipo == "an_ejemplares") {
                cin >> ecosistema >> especie >> ejemplares;
                parque.an_ejemplares(ecosistema, especie, ejemplares);
            }
            else if (tipo == "lista_especies_ecosistema") {
                cin >> ecosistema >> n;
                list<string> l = parque.lista_especies_ecosistema(ecosistema, n);
                for (string s : l)
                    cout << s << " ";
                cout << endl;
            }
            else if (tipo == "numero_ejemplares_en_ecosistema") {
                cin >> ecosistema >> especie;
                ejemplares = parque.numero_ejemplares_en_ecosistema(ecosistema, especie);
                cout << ejemplares << endl;
            }
            else if (tipo == "lista_especies_parque") {
                list<string> l = parque.lista_especies_parque();
                for (string s : l)
                    cout << s << " ";
                cout << endl;
            }
            else if (tipo == "numero_ejemplares_en_parque") {
                cin >> especie;
                ejemplares = parque.numero_ejemplares_en_parque(especie);
                cout << ejemplares << endl;
            }
        }
        catch (domain_error& d) {
            cout << d.what() << endl;
        }
        cin >> tipo;
    }
    cout << "---" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}