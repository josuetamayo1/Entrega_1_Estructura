#include <iostream>

class Carta {
public:
	int numero;
	char color;
	Carta(int _numero, char _color) {
		numero = _numero;
		color = _color;

	}
private:
	int getnumero() {
		return numero;
	}
	char getcolor() {
		return color;
	}
	
}