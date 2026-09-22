#pragma once
#include <iostream>
#include <vector>
#include "carta.h"
#include "jugadores.h"
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
		// Lógica para iniciar el juego, repartir cartas y establecer el jugador decidor
	}
	void elegirJuego() {
		// Lógica para que el jugador decidor elija el color/tipo de juego
	}
    void jugarRonda() {
        // Lógica para ejecutar una ronda completa del juego
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
        };