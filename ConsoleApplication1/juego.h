#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "carta.h"
#include "jugadores.h"
#include "ronda.h"

class  Juego {
private:
	std::vector<Jugadores*> jugadores;
	std::vector<Carta*> mazo;
	int jugadorDecidor;
	int ronda;
public:
	Juego(std::vector<Jugadores*> _jugadores, std::vector<Carta*> _mazo, int _jugadorDecidor, int _ronda) {
		jugadores = _jugadores;
		mazo = _mazo;
		jugadorDecidor = _jugadorDecidor;
		ronda = _ronda;
	}
	void iniciarJuego() {
		for (int numero = 0; numero <= 10; numero++) {
			mazo.push_back(Carta(numero, 'R'));
			mazo.push_back(Carta(numero, 'A'));
			mazo.push_back(Carta(numero, 'V'));
		}

		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(mazo.begin(), mazo.end(), g);

		for (int id = 0; id < 4; id++) {
			std::vector<Carta> manoJugador;
			for (int i = 0; i < 7; i++) {
				manoJugador.push_back(mazo.back());
				mazo.pop_back();
			}
			jugadores.push_back(Jugadores(id, manoJugador, 0));
		}

		std::uniform_int_distribution<int> dist(0, 3);
		jugadorDecidor = dist(g);
	}

	void elegirJuego() {
		char colorElegido;
		bool esAlza;
		jugadores[jugadorDecidor].elegirJuego(colorElegido, esAlza);

		char eleccion = esAlza ? 'a' : 'b';
		rondaActual = Ronda(colorElegido, eleccion);

		std::cout << "Esta ronda se juega con color " << colorElegido
			<< " y direccion " << (esAlza ? "alza" : "baja") << std::endl;
	}

	void jugarRonda() {
		for (int i = 0; i < 4; i++) {
			int idx = (jugadorDecidor + i) % 4;
			Carta cartaJugada = jugadores[idx].jugarCarta();
			rondaActual.recibirCarta(cartaJugada, idx);
		}
	}

	void cerrarRonda() {
		int idGanador = rondaActual.ganadorRonda();
		rondaActual.resultadoRonda();

		std::vector<Carta> cartasGanadas = rondaActual.getCartasJugadas();
		jugadores[idGanador].ganarCartas(cartasGanadas);

		jugadorDecidor = idGanador;

		rondaActual.reiniciarRonda();
	}

	bool verificarFinal() {
		for (int i = 0; i < jugadores.size(); i++) {
			if (!jugadores[i].tieneCartas()) {
				return true;
			}
		}
		return false;
	}

	void mostrarResultados() {
		int mejorPuntaje = -1;
		int idGanador = -1;

		std::cout << "--- Resultados finales ---" << std::endl;

		for (int i = 0; i < jugadores.size(); i++) {
			int puntaje = jugadores[i].getPuntaje();
			std::cout << "Jugador " << i << ": " << puntaje << " puntos" << std::endl;

			if (puntaje > mejorPuntaje) {
				mejorPuntaje = puntaje;
				idGanador = i;
			}
		}

		std::cout << "\nGana el jugador " << idGanador << " con " << mejorPuntaje << " puntos." << std::endl;
	}
};