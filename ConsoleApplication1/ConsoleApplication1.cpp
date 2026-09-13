// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "carta.h"

int main()
{
	Carta carta1(1, 'R');
	std::cout << "***********************************************************************************************************" << std::endl;
	std::cout << "Bienvenido al juego" << std::endl;
	std::cout << "Elija el tipo de juego que desea jugar, 1 es a la baja y 2 es a la alta" << std::endl;
	std::cout << "Ingrese un numero entre 1 y 2: " << std::endl;
	std::cout << "***********************************************************************************************************" << std::endl;
	char numero;
	std::cin >> numero;
    if(numero== '2') {
		std::cout << "Se juega a la alta" << std::endl;
		std::cout << "***********************************************************************************************************" << std::endl;

	}
	else {
		std::cout << "se juega a la baja" << std::endl;
		std::cout << "***********************************************************************************************************" << std::endl;
	}

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
