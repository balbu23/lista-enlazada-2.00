#include <iostream>
using namespace std;

struct nodo {
	int dato;
	nodo* siguiente;
};

void agregarnodo(nodo*& cabeza, int valor) {
	nodo* nuevonodo = new nodo;
	nuevonodo->dato = valor;
	nuevonodo->siguiente = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevonodo;
	}
	else {
		nodo* actual = cabeza;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevonodo;
	}
}
void imprimirlista(nodo* cabeza) {
	nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << "";
		actual = actual->siguiente;
	}
	cout << endl;
}
void borrarlista(nodo* cabeza) {
	while (cabeza != nullptr) {
		nodo* siguiente = cabeza->siguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "elemento eliminado";
	}
}
int main() {
	nodo* cabeza = nullptr;
	int tamanolista;
	cout << "ingrese la cantidad de elementos que desea agregar a la lista:";
	cin >> tamanolista;

	if (tamanolista <= 0) {
		cout << "cantidad de elementos no valida" << endl;
		return 1;
	}
	for (int i = 0;i < tamanolista;i++) {
		int valor;
		cout << "ingrese dato" << i + 1 << ":";
		cin >> valor;

		agregarnodo(cabeza, valor);
	}
	cout << "imprimiendo lista" << endl;
	imprimirlista(cabeza);

	borrarlista(cabeza);

	return 0;
}
