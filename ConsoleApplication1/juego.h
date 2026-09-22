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
	}
	void cerrarRonda() {
		// Lógica para cerrar la ronda, determinar el ganador y actualizar puntajes
	}
	bool verificarFinal() {
		// Lógica para verificar si el juego ha terminado
	}
	´void mostrarResultados() {
		// Lógica para mostrar los resultados finales del juego
	}
};