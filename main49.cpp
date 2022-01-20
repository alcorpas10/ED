//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include "autoescuela.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    autoescuela autoescuela;
    string tipo, a, p;
    int puntos;
    cin >> tipo;
    if (!std::cin)
        return false;
    while (tipo != "FIN") {
        try {
            if (tipo == "alta") {
                cin >> a >> p;
                autoescuela.alta(a, p);
            }
            else if (tipo == "es_alumno") {
                cin >> a >> p;
                if (autoescuela.es_alumno(a, p))
                    cout << a << " es alumno de " << p << endl;
                else
                    cout << a << " no es alumno de " << p << endl;
            }
            else if (tipo == "examen") {
                cin >> p >> puntos;
                list<string> l;
                l = autoescuela.examen(p, puntos);
                cout << "Alumnos de " << p << " a examen:" << endl;
                for (string s : l)
                    cout << s << " " << endl;
            }
            else if (tipo == "actualizar") {
                cin >> a >> puntos;
                autoescuela.actualizar(a, puntos);
            }
            else if (tipo == "puntuacion") {
                cin >> a;
                int punt = autoescuela.puntuacion(a);
                cout << "Puntuacion de " << a << ": " << punt << endl;
            }
            else if (tipo == "aprobar") {
                cin >> a;
                autoescuela.aprobar(a);
            }
        }
        catch (domain_error& d) {
            cout << "ERROR" << endl;
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