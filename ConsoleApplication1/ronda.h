#pragma once
#include <iostream>
#include <vector>
#include "carta.h"


class Ronda {
private:
	char colorElegido;
	char eleccion;
	std::vector<Carta> cartasJugadas;
	std::vector<int> idsJugadores;  // idsJugadores[i] es el dueño de cartasJugadas[i]
	int ganador;

public:
	Ronda(char _colorElegido, char _eleccion) {
		colorElegido = _colorElegido;
		eleccion = _eleccion;
		ganador = -1;
	};
	void recibirCarta(Carta carta, int idJugador) {
		cartasJugadas.push_back(carta);
		idsJugadores.push_back(idJugador);
	};
	bool verificarJugada() {
		return cartasJugadas.size() == 4;
	};
	int ganadorRonda() { 
		/* 1. Recorre todas las cartas revisando si son del color elegido
		2. la primera carta del color elegido se guarda como la mejor carta
		3. si encuentra otra carta del color elegido, se compara con la mejor carta y se actualiza si es mejor
		4. si no hay cartas del color elegido, se hace lo mismo pero con todas las cartas
		*/
		int indiceElegido = -1;

		for (int i = 0; i < 4; i++) {
			if (cartasJugadas[i].getcolor() == colorElegido) {
				if (indiceElegido == -1) {
					indiceElegido = i;
				}
				else if ((eleccion == 'a' or eleccion == 'A') and cartasJugadas[i].getnumero() > cartasJugadas[indiceElegido].getnumero()) {
					indiceElegido = i;
				}
				else if ((eleccion == 'b' or eleccion == 'B') and cartasJugadas[i].getnumero() < cartasJugadas[indiceElegido].getnumero()) {
					indiceElegido = i;
				}
			}
		}
		if (indiceElegido == -1) {
			indiceElegido = 0;
			for (int i = 1; i < 4; i++) {
				if ((eleccion == 'a' or eleccion == 'A') and cartasJugadas[i].getnumero() > cartasJugadas[indiceElegido].getnumero()) {
					indiceElegido = i;
				}
				else if ((eleccion == 'b' or eleccion == 'B') and cartasJugadas[i].getnumero() < cartasJugadas[indiceElegido].getnumero()) {
					indiceElegido = i;
				}
			}
		}

		ganador = idsJugadores[indiceElegido];
		return ganador;
	};
	void resultadoRonda() {
		std::cout << "Ganador de la ronda: Jugador " << ganador << std::endl;
		std::cout << "Cartas jugadas:" << std::endl;
		for (int i = 0; i < cartasJugadas.size(); i++) {
			std::cout << "  Jugador " << idsJugadores[i] << " jugo: "
				<< cartasJugadas[i].getnumero() << " "
				<< cartasJugadas[i].getcolor() << std::endl;
		}
	};
	void reiniciarRonda() {
		cartasJugadas.clear();
		idsJugadores.clear();
		ganador = -1;
	};
	std::vector<Carta> getCartasJugadas() {
		return cartasJugadas;
	};

	std::vector<int> getIdsJugadores() {
		return idsJugadores;
	};

};




