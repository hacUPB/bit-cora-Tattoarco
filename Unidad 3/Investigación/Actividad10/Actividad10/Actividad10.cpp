#include <iostream>
using namespace std;
class Enemigo {
public:
	static int totalEnemigos;
	int vida;
	int* armas;
	Enemigo(int v) : vida(v) {
		totalEnemigos++;
		armas = new int[3];
		armas[0] = 10;
		armas[1] = 15;
		armas[2] = 20;
	}
};
int Enemigo::totalEnemigos = 0;
void crearEscuadron() {
	for (int i = 0; i < 5; i++) {
		Enemigo soldado(100);
		soldado.vida -= 10;
	}
	cout << "Escuadrón creado. Total enemigos: " << Enemigo::totalEnemigos << endl;
}
int main() {
	crearEscuadron();
	crearEscuadron();
	return 0;
}