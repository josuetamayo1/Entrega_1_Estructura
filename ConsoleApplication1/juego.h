#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "carta.h"
#include "jugadores.h"
#include "ronda.h"
#include <fstream>

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

	void jugar(bool cargarDesdeArchivo, std::string nombreArchivo) {
		if (cargarDesdeArchivo) {
			cargarPartida(nombreArchivo);
		}
		else {
			iniciarJuego();
		}

		while (!verificarFinal()) {
			elegirJuego();
			jugarRonda();
			cerrarRonda();

			if (!verificarFinal()) {
				char opcion;
				std::cout << "¿Quieres seguir jugando o guardar y pausar? (s = seguir, g = guardar): ";
				std::cin >> opcion;

				if (opcion == 'g' || opcion == 'G') {
					std::string nombreGuardado;
					std::cout << "Nombre del archivo para guardar: ";
					std::cin >> nombreGuardado;
					guardarPartida(nombreGuardado);
					return;
				}
			}
		}

		mostrarResultados();
	}
	void guardarPartida(std::string nombreArchivo) {
		std::ofstream archivo(nombreArchivo);

		archivo << jugadorDecidor << std::endl;
		archivo << ronda << std::endl;

		for (int i = 0; i < (int)jugadores.size(); i++) {
			std::vector<Carta> mano = jugadores[i]->getMazo();

			archivo << i << " " << jugadores[i]->getPuntaje() << " " << mano.size() << std::endl;

			for (int j = 0; j < (int)mano.size(); j++) {
				archivo << mano[j].getnumero() << " " << mano[j].getcolor() << std::endl;
			}
		}

		archivo.close();
		std::cout << "Partida guardada en " << nombreArchivo << std::endl;
	}
	void cargarPartida(std::string nombreArchivo) {
		std::ifstream archivo(nombreArchivo);

		if (!archivo.is_open()) {
			std::cout << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
			return;
		}

		archivo >> jugadorDecidor;
		archivo >> ronda;

		for (int i = 0; i < (int)jugadores.size(); i++) {
			int idLeido, puntajeLeido, cantidadCartas;
			archivo >> idLeido >> puntajeLeido >> cantidadCartas;

			jugadores[i]->reiniciarJugador(puntajeLeido);

			for (int j = 0; j < cantidadCartas; j++) {
				int numero;
				char color;
				archivo >> numero >> color;
				jugadores[i]->recibirCarta(Carta(numero, color));
			}
		}

		archivo.close();
		std::cout << "Partida cargada desde " << nombreArchivo << std::endl;
	}
};