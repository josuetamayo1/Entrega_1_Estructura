#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "carta.h"
#include "jugadores.h"
#include "ronda.h"

class Juego {
private:
	std::vector<Jugadores*> jugadores;
	std::vector<Carta> mazo;
	int jugadorDecidor;
	int ronda;
	Ronda rondaActual;

public:
	Juego(std::vector<Jugadores*> _jugadores) : rondaActual('R', 'a') {
		jugadores = _jugadores;
		jugadorDecidor = 0;
		ronda = 0;
	}

	void iniciarJuego() {
		mazo.clear();
		ronda = 0;

		
		for (int numero = 0; numero <= 10; numero++) {
			mazo.push_back(Carta(numero, 'R'));
			mazo.push_back(Carta(numero, 'A'));
			mazo.push_back(Carta(numero, 'V'));
		}

		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(mazo.begin(), mazo.end(), g);

		for (int id = 0; id < 4; id++) {
			for (int i = 0; i < 7; i++) {
				jugadores[id]->recibirCarta(mazo.back());
				mazo.pop_back();
			}
		}

		std::uniform_int_distribution<int> dist(0, 3);
		jugadorDecidor = dist(g);

		std::cout << "Se reparte. Empieza eligiendo el modo el Jugador "
			<< jugadorDecidor << std::endl;
	}

	void elegirJuego() {
		char colorElegido;
		bool esAlza;

		jugadores[jugadorDecidor]->elegirJuego(colorElegido, esAlza);

		char eleccion = esAlza ? 'a' : 'b';
		rondaActual = Ronda(colorElegido, eleccion);

		std::cout << "Esta ronda se juega con color " << colorElegido
			<< " y direccion " << (esAlza ? "alza" : "baja") << std::endl;
	}

	void jugarRonda() {
		for (int i = 0; i < 4; i++) {
			int idx = (jugadorDecidor + i) % 4;
			Carta cartaJugada = jugadores[idx]->jugarCarta();
			rondaActual.recibirCarta(cartaJugada, idx);
		}
	}

	void cerrarRonda() {
		int idGanador = rondaActual.ganadorRonda();
		rondaActual.resultadoRonda();

		std::vector<Carta> cartasGanadas = rondaActual.getCartasJugadas();
		jugadores[idGanador]->ganarCartas(cartasGanadas);

		jugadorDecidor = idGanador;
		rondaActual.reiniciarRonda();
		ronda++;
	}

	bool verificarFinal() {
		return ronda >= 7;
	}

	void mostrarResultados() {
		int mejorPuntaje = -1;
		int idGanador = -1;

		std::cout << "--- Resultados finales ---" << std::endl;

		for (int i = 0; i < (int)jugadores.size(); i++) {
			int puntaje = jugadores[i]->getPuntaje();
			std::cout << "Jugador " << i << ": " << puntaje << " puntos" << std::endl;

			if (puntaje > mejorPuntaje) {
				mejorPuntaje = puntaje;
				idGanador = i;
			}
		}

		std::cout << "\nGana el jugador " << idGanador
			<< " con " << mejorPuntaje << " puntos." << std::endl;
	}

	void jugar() {
		iniciarJuego();
		while (!verificarFinal()) {
			elegirJuego();
			jugarRonda();
			cerrarRonda();
		}
		mostrarResultados();
	}
};