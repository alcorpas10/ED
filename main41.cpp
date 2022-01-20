//ALEJANDRO CORPAS CALVO
//alcorpas10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

using nomEquipo = string;
using nomEjercicio = string;

struct datosEjercicio {
    int intentos = 0;
    bool resuelto = false;
};

struct datosEquipo {
    unordered_map<nomEjercicio, datosEjercicio> dEj;
    int resEj = 0;
    int tiempo = 0;
};

struct solucion {
    nomEquipo nomEq;
    int resEj;
    int tiempo;
};

struct {
    bool operator() (const solucion& l, const solucion& r) const
    {
        if (l.resEj < r.resEj) return false;
        else if (l.resEj > r.resEj) return true;
        else {
            if (l.tiempo < r.tiempo) return true;
            else if (l.tiempo > r.tiempo) return false;
            else return l.nomEq < r.nomEq;
        }
    }
} comp;

// funcion que resuelve el problema
void resolver(unordered_map<nomEquipo, datosEquipo>& mapa) {
    vector<solucion> v;
    for (const auto& equipo : mapa)
        v.push_back({ equipo.first, equipo.second.resEj, equipo.second.tiempo });
    sort(v.begin(), v.end(), comp);
    for (const auto& e : v)
        cout << e.nomEq << " " << e.resEj << " " << e.tiempo << endl;
    cout << "---" << endl;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    unordered_map<nomEquipo, datosEquipo> mapa;
    nomEquipo nomEq;
    nomEjercicio nomEj;
    int tiempo;
    string sol;
    cin >> nomEq;
    while(nomEq != "FIN") {
        cin >> nomEj;
        cin >> tiempo;
        cin >> sol;
        if (!mapa[nomEq].dEj[nomEj].resuelto) {
            if (sol == "AC") {
                mapa[nomEq].resEj++;
                mapa[nomEq].tiempo += tiempo;
                mapa[nomEq].dEj[nomEj].intentos++;
                if (mapa[nomEq].dEj[nomEj].intentos != 1)
                    mapa[nomEq].tiempo += (mapa[nomEq].dEj[nomEj].intentos - 1) * 20;
                mapa[nomEq].dEj[nomEj].resuelto = true;
            }
            else
                mapa[nomEq].dEj[nomEj].intentos++;
        }
        
        cin >> nomEq;
    }
    resolver(mapa);
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
