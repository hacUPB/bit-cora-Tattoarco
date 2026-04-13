#include <iostream>
using namespace std;

// Función que modifica el parámetro pasado por valor
void modificarPorValor(int n) {
	cout << "Dentro de modificarPorValor, valor inicial: " << n << endl;
	n += 5;
	cout << "Dentro de modificarPorValor, valor modificado: " << n << endl;
}

// Función que modifica el parámetro pasado por referencia
void modificarPorReferencia(int& n) {
	cout << "Dentro de modificarPorReferencia, valor inicial: " << n << endl;
	n += 5;
	cout << "Dentro de modificarPorReferencia, valor modificado: " << n << endl;
}

// Función que modifica el parámetro utilizando punteros
void modificarPorPuntero(int* n) {
	cout << "Dentro de modificarPorPuntero, valor inicial: " << *n << endl;
	*n += 5;
	cout << "Dentro de modificarPorPuntero, valor modificado: " << *n << endl;
}

// 1. Paso por valor
void swapPorValor(int a, int b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "Dentro de swapPorValor:" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}

// 2. Paso por referencia
void swapPorReferencia(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

	cout << "Dentro de swapPorReferencia:" << endl;
	cout << "a = " << a << ", b = " << b << endl;
}

// 3. Paso por puntero
void swapPorPuntero(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	cout << "Dentro de swapPorPuntero:" << endl;
	cout << "*a = " << *a << ", *b = " << *b << endl;
}



int main() {
	int a = 10;    int b = 12;    int c = 15;
	cout << "Valor inicial de a (paso por valor): " << a << endl;    cout << "Valor inicial de b (paso por referencia): " << b << endl;    cout << "Valor inicial de c (paso por puntero): " << c << endl;
	cout << "\nLlamando a modificarPorValor(a)..." << endl;    modificarPorValor(a);    cout << "Después de modificarPorValor, valor de a: " << a << endl;
	cout << "\nLlamando a modificarPorReferencia(b)..." << endl;    modificarPorReferencia(b);    cout << "Después de modificarPorReferencia, valor de b: " << b << endl;
	cout << "\nLlamando a modificarPorPuntero(&c)..." << endl;    modificarPorPuntero(&c);    cout << "Después de modificarPorPuntero, valor de c: " << c << endl;
	//Actividad 2: Intercambio de valores utilizando paso por valor, referencia y puntero
	cout << "\nIntercambio de valores utilizando paso por valor..." << endl;    swapPorValor(a, b);    cout << "Después de swapPorValor, a = " << a << ", b = " << b << endl;
	cout << "\nIntercambio de valores utilizando paso por referencia..." << endl;    swapPorReferencia(a, b);    cout << "Después de swapPorReferencia, a = " << a << ", b = " << b << endl;
	cout << "\nIntercambio de valores utilizando paso por puntero..." << endl;    swapPorPuntero(&a, &b);    cout << "Después de swapPorPuntero, a = " << a << ", b = " << b << endl;
	return 0;
}