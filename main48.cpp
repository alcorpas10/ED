//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include <tuple>
#include "fecha2.h"
#include "consultorio.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numI, dia;
    string tipo, med, pac;
    Horas f;
    consultorio cons;
    cin >> numI;
    if (!std::cin)
        return false;
    for (int i = 0; i < numI; i++) {
        cin >> tipo;
        try {
            if (tipo == "nuevoMedico") {
                cin >> med;
                cons.nuevoMedico(med);
            }
            else if (tipo == "pideConsulta") {
                cin >> pac >> med >> f;
                cons.pideConsulta(pac, med, f);
            }
            else if (tipo == "listaPacientes") {
                cin >> med >> dia;
                list<pair<Horas, string>> l = cons.listaPacientes(med, dia);
                cout << "Doctor " << med << " dia " << dia << endl;
                for (auto a : l)
                    cout << a.second << " " << a.first << endl;
            }
            else if (tipo == "siguientePaciente") {
                cin >> med;
                pac = cons.siguientePaciente(med);
                cout << "Siguiente paciente doctor " << med << endl;
                cout << pac << endl;
            }
            else if (tipo == "atiendeConsulta") {
                cin >> med;
                cons.atiendeConsulta(med);
            }
        }
        catch (domain_error& d) {
            cout << d.what() << endl;
        }
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