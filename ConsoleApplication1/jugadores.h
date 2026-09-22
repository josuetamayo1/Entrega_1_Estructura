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

    Carta* jugarCarta(char colorElegido, bool esAlza) {
        int indiceElegido = -1;

        for (int i = 0; i < mazo.size(); i++) {
            if (mazo[i]->getcolor() == colorElegido) {
                if (indiceElegido == -1) {
                    indiceElegido = i;
                }
                else if (esAlza && mazo[i]->getnumero() > mazo[indiceElegido]->getnumero()) {
                    indiceElegido = i;
                }
                else if (!esAlza && mazo[i]->getnumero() < mazo[indiceElegido]->getnumero()) {
                    indiceElegido = i;
                }
            }
        }

        if (indiceElegido == -1) {
            return nullptr;
        }

        Carta* cartaJugada = mazo[indiceElegido];
        mazo.erase(mazo.begin() + indiceElegido);
        return cartaJugada;
    }

    void ganarCartas(std::vector<Carta*> cartasGanadas) {
        puntaje += cartasGanadas.size();
    }

    void perderCartas() {
        // El jugador solo pierde la carta que ya jugó (removida en jugarCarta)
    }

    // CORREGIDO: ahora el jugador elige manualmente el color Y si es alza o baja
    // colorElegido y esAlza se pasan por referencia para devolver ambos valores
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