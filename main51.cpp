// ALEJANDRO CORPAS CALVO
// alcorpas10

#ifndef LIBROS
#define LIBROS

#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;
using nomLibro = string;
using numEjs = int;

class venta_libros {
private:
	unordered_map<nomLibro, numEjs> libros;
	list<nomLibro> v;
public:
	venta_libros() {}
	void nuevoLibro(numEjs n, nomLibro x) {
		libros[x] += n;
	}
	void comprar(nomLibro x) {
		auto it = libros.find(x);
		if (it != libros.cend()) {
			if (it->second != 0)
				v.push_back(it->first);
			else throw out_of_range("No hay ejemplares");
		}
		else throw invalid_argument("Libro no existente");
	}
	bool estaLibro(nomLibro x) {
		return libros.count(x);
	}
	void elimLibro(nomLibro x) {
		if (libros.count(x))
			libros.erase(x);
	}
	int numEjemplares(nomLibro x) {
		auto it = libros.find(x);
		if (it != libros.cend())
			return it->second;
		else throw invalid_argument("Libro no existente");
	}
	list<nomLibro> top10() {
		return v;
	}
};

#endif //LIBROS

