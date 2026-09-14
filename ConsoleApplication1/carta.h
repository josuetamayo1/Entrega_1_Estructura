#include <iostream>
#pragma once


class Carta {
private:
	int numero;
	char color;
	
public:
	Carta(int _numero, char _color) {
		numero = _numero;
		color = _color;
	}
	int getnumero() {
		return numero;
	}
	char getcolor() {
		return color;
	}
};
