#pragma once
#include <iostream>
#include <vector>
#include "carta.h"

class Jugadores {
private:
    int id;
    std::vector<Carta> mazo;
    int puntaje;

public:
    Jugadores(int _id, std::vector<Carta> _mazo, int _puntaje) {
        id = _id;
        mazo = _mazo;
        puntaje = _puntaje;
    }

    Carta jugarCarta() {
        std::cout << "Jugador " << id << ", estas son tus cartas:" << std::endl;
        for (int i = 0; i < mazo.size(); i++) {
            std::cout << i << ": Numero " << mazo[i].getnumero() << ", Color " << mazo[i].getcolor() << std::endl;
        }

        int indiceElegido;
        std::cout << "Elige el numero de la carta que quieres jugar: ";
        std::cin >> indiceElegido;

        Carta cartaJugada = mazo[indiceElegido];
        mazo.erase(mazo.begin() + indiceElegido);
        return cartaJugada;
    }

    void ganarCartas(std::vector<Carta> cartasGanadas) {
        puntaje += cartasGanadas.size();
    }

    void elegirJuego(char& colorElegido, bool& esAlza) {
        std::cout << "Jugador " << id << ", elige un color (ej: R, A, V): ";
        std::cin >> colorElegido;

        char opcion;
        std::cout << "¿Alza o baja? (a = alza, b = baja): ";
        std::cin >> opcion;
        esAlza = (opcion == 'a' || opcion == 'A');
    }

    int getPuntaje() {
        return puntaje;
    }
};
