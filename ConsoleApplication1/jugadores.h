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
		// Lógica para que el jugador juegue una carta de su mazo

	}
	void ganarCartas() {
		// Lógica para cuando el jugador gana la ronda y recibe cartas o puntos

	}
	void perderCartas() {
		// Lógica para cuando el jugador pierde cartas tras perder la ronda

	}
	char elegirJuego() {
		// Lógica para que el jugador elija el color/tipo de juego a jugar

	}
};