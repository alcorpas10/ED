// ALEJANDRO CORPAS CALVO
// alcorpas10

#include <iostream>               
#include <fstream>               
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
using nomSensor = string;
using hora = string;

// COMENTARIO SOBRE LA SOLUCION Y SU COSTE JUSTIFICADO
//Para obtener la solucion he decidido usar un hashmap ya que para este ejercicio tener las claves ordenadas de cierta manera no era importante y asi consigo
//que las operaciones que realice sobre el map tengan un coste menor al que tendrian con uno ordenado. He decidido usar como clave el nombre de los sensores
//ya que he visto que a la hora de buscar lo que tendria que mostrar como salida tenia que usar eso mismo y se simplificaria todo bastante, dado que el nombre
//seria la clave solo quedaba que las horas fueran parte del valor, para ello he decidido usar un vector de horas (string) ya que es equivalente a un mapa
//ordenado con numeros como clave, gracias a ello he podido acceder directamente al valor de la hora que ocupaba la posicion del vector que nos pide el jefe.

//En cuanto al coste total es de O(max(N, M)) siendo N el numero de sensores y M el numero de solicitudes que hace el jefe.
//Esto es debido a que hay 2 bucles en el programa, cada uno independiente del otro, y ambos con instrucciones de coste constante en su interior gracias a haber
//usado unordered_map, por tanto N veces algo constante da N (y lo mismo con el bucle de M). Tambien encontramos instrucciones fuera de bucles con coste constante

bool resuelveCaso() {
    unordered_map<nomSensor, vector<hora>> mapa;
    nomSensor n;
    hora h;
    int N, M, puesto;
    cin >> N;
    if (!cin)
        return false;
    cin >> M;
    //coste O(N) ya que tanto la lectura como la insercion en un vector son de coste constante y realizados N veces da ese coste (N numero de sensores)
    for (int i = 0; i < N; i++) {
        cin >> n >> h;
        mapa[n].push_back(h);
    }
    //coste O(M) ya que tanto la lectura, como una resta, como una comparacion, como las operaciones que se realizan sobre el mapa, como las operaciones que se
    //sobre el vector, como la escritura son de coste constante y realizados M veces da ese coste (M numero de preguntas)
    for (int i = 0; i < M; i++) {
        cin >> n >> puesto;
        puesto--;
        if (mapa.count(n) && puesto < mapa[n].size()) {
            cout << mapa[n].at(puesto) << " ";
        }
        else
            cout << "-- ";
    }
    cout << endl;
    return true;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
