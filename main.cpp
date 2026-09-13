#include <iostream>
#include "cartas.h"

int main() {
	Carta carta1(5, 'R');
	int cartanumero = carta1.getnumero();
	char cartacolor = carta1.getcolor();
	std::cout << "Carta: " << cartanumero << " Color: " << cartacolor << std::endl;
	return 0;
}