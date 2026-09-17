#pragma once
#include <iostream>
#include <vector>
#include "carta.h"

class Jugadores {
private:
	int id;
	std::vector<Carta*> mazo;
	int puntaje;

public:
	Jugadores(int _id, std::vector<Carta*> _mazo, int _puntaje) {
		id = _id;
		mazo = _mazo;
		puntaje = _puntaje;
	}
	Carta* jugarCarta(Carta* carta) {

	}
	void ganarCartas() {

	}
	void perderCartas() {

	}
	char elegirJuego() {

	}
};