//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include "carnet_puntos.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    string tipo, dni;
    int puntos, sol;
    carnet_puntos cPuntos;
    cin >> tipo;
    if (!std::cin)
        return false;
    while (tipo != "FIN") {
        try {
            if (tipo == "nuevo") {
                cin >> dni;
                try {
                    cPuntos.nuevo(dni);
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            else if (tipo == "cuantos_con_puntos") {
                cin >> puntos;
                try {
                    sol = cPuntos.cuantos_con_puntos(puntos);
                    cout << "Con " << puntos << " puntos hay " << sol << endl;
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            else if (tipo == "lista_por_puntos") {
                cin >> puntos;
                try {
                    list<string> l = cPuntos.lista_por_puntos(puntos);
                    cout << "Tienen " << puntos << " puntos: ";
                    for (string a : l)
                        cout << a << " ";
                    cout << endl;
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            else if (tipo == "recuperar") {
                cin >> dni >> puntos;
                try {
                    cPuntos.recuperar(dni, puntos);
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            else if (tipo == "quitar") {
                cin >> dni >> puntos;
                try {
                    cPuntos.quitar(dni, puntos);
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            else if (tipo == "consultar") {
                cin >> dni;
                try {
                    sol = cPuntos.consultar(dni);
                    cout << "Puntos de " << dni << ": " << sol << endl;
                }
                catch (domain_error& d) {
                    cout << "ERROR: " << d.what() << endl;
                }
            }
            cin >> tipo;
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