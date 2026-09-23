#include <iostream>
#include <vector>
#include "carta.h"
#include "jugadores.h"
#include "juego.h"

int main() {
	ste::vector<Carta> manoVacia;
	std::vector<Jugadores*> jugadores;

	for(int id = 0; id < 4; id++) {
		jugadores.push_back(new Jugadores(id, manoVacia, 0));
}
	Juego juego(jugadores);
	juego.jugar();

	for (int i = 0; i < (int)jugadores.size(); i++) {
		delete jugadores[i];
	}
	return 0;
}