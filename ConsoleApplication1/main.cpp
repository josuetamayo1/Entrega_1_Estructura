// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include "carta.h"
#include "jugadores.h"
#include "juego.h"

int main()
{
    std::vector<Carta> manoVacia;
    std::vector<Jugadores*> jugadores;

    for (int id = 0; id < 4; id++) {
        jugadores.push_back(new Jugadores(id, manoVacia, 0));
    }
    Juego juego(jugadores);

    char opcion;
    std::cout << "¿Quieres cargar una partida guardada? (s/n): ";
    std::cin >> opcion;

    if (opcion == 's' || opcion == 'S') {
        std::string nombreArchivo;
        std::cout << "Nombre del archivo a cargar: ";
        std::cin >> nombreArchivo;
        juego.jugar(true, nombreArchivo);
    }
    else {
        juego.jugar(false, "");
    }

    for (int i = 0; i < (int)jugadores.size(); i++) {
        delete jugadores[i];
    }
    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
