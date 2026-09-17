#pragma once
#include <iostream>
#include <vector>
#include "carta.h"


class Ronda {
private:
	char colorElegido;
	char eleccion;
	std::vector<Carta> cartasJugadas;
	int ganador;

public:
	Ronda(char _colorElegido, char _eleccion) {
		colorElegido = _colorElegido;
		eleccion = _eleccion;
		ganador = -1;
	};
	void recibirCarta(Carta carta) {
		// Lógica para recibir una carta
	};
	bool verificarJugada() {
		// Lógica para verificar cuando acaba la ronda
		return false;
	};
	void ganadorRonda() {
		// Lógica para determinar el ganador de la ronda
	};
	void resultadoRonda() {
		// Lógica para mostrar el resultado de la ronda
	};
	void reiniciarRonda() {
		// Lógica para reiniciar la ronda
	};



};
