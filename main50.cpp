//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include "iPud.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    iPud iPud;
    string tipo, cancion, cantante;
    int duracion, numCanciones;
    cin >> tipo;
    if (!std::cin)
        return false;
    while (tipo != "FIN") {
        try {
            if (tipo == "addSong") {
                cin >> cancion >> cantante >> duracion;
                iPud.addSong(cancion, cantante, duracion);
            }
            else if (tipo == "addToPlaylist") {
                cin >> cancion;
                iPud.addToPlaylist(cancion);
            }
            else if (tipo == "play") {
                cancion = iPud.play();
                if (cancion == "")
                    cout << "No hay canciones en la lista" << endl;
                else
                    cout << "Sonando " << cancion << endl;
            }
            else if (tipo == "totalTime") {
                duracion = iPud.totalTime();
                cout << "Tiempo total " << duracion << endl;
            }
            else if (tipo == "deleteSong") {
                cin >> cancion;
                iPud.deleteSong(cancion);
            }
            else if (tipo == "recent") {
                cin >> numCanciones;
                list<string> l = iPud.recent(numCanciones);
                if (!l.empty()) {
                    cout << "Las " << l.size() << " mas recientes" << endl;
                    for (string s : l)
                        cout << "    " << s << endl;
                }
                else
                    cout << "No hay canciones recientes" << endl;
            }
            else if (tipo == "current") {
                cancion = iPud.current();
                cout << cancion << endl;
            }
        }
        catch (domain_error& d) {
            cout << d.what() << " " << tipo << endl;
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