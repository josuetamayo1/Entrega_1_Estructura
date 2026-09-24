# Entrega_1_Estructura

Juego de Cartas (C++)
Descripción de las reglas y el funcionamiento del juego.

Reglas del juego:

-Participan 4 jugadores, cada uno con 7 cartas al empezar la partida.
-Cada carta tiene un número (0 a 10) y un color: R,A o V (roja,amarila,verde).
-Al iniciar la partida se arma un mazo de 33 cartas (11 números por 3 colores), se baraja y se reparten 7 a cada jugador. Luego se sortea al azar quién decide el modo de la primera ronda.
-En cada ronda, el jugador con el turno elije:
  -un color (R,A o V)
  -alza(gana la carta más alta), o baja(gana el que escoja la carta con el numero de menor valor).

-Los 4 jugadores juegan una carta cada uno, en orden rotativo a partir de quien decidió el modo. Entre cada turno el juego se pausa y limpia la pantalla, para que cada jugador vea su mano sin que los demás la vean ("pasar y jugar").

-Al completarse las 4 jugadas se revela el ganador de la ronda:
  -se busca la mejor carta del color elegido (la más alta si es alza, la más baja si es a la baja);
  -si nadie jugó ese color, se ignora el filtro y se compara por número entre las 4 cartas jugadas.
  -El ganador de la ronda se queda con las 4 cartas jugadas (cada una suma un punto a su puntaje) y pasa a decidir el modo de la siguiente ronda.
  -La partida dura 7 rondas en total. Al terminar, gana quien acumuló más cartas.

Guardar y cargar partida:
-Antes de cada ronda (salvo la última) se puede optar por guardar el progreso en un archivo de texto y pausar la partida, para continuarla más tarde.
-Al iniciar el programa se pregunta si se quiere cargar una partida guardada; de ser así, se pide el nombre del archivo correspondiente.

Estructura del proyecto:
Archivo carta.h: clase Carta: Representa una carta (número más el color). Objeto simple e incambiable que se maneja siempre por valor.

Archivo jugadores.h clase Jugadores: Representa a un jugador: su mano, su puntaje, y sus acciones (jugar una carta, elegir el modo de una ronda, recibir cartas ganadas).

Archivo ronda.h clase Ronda: Recibe las 4 cartas jugadas en una ronda, calcula el ganador según el color/dirección elegidos, y reporta el resultado.

Archivo juego.h clase Juego: Organiza el flujo completo: reparte las cartas, dirige cada ronda apoyándose en Ronda y Jugadores, y maneja el guardado(carga) de partidas.

Archivo main.cpp: Punto de entrada: crea los 4 jugadores y el objeto Juego, y arranca la partida (nueva o cargada).

Decisiones de diseño:
-Carta la manejamos por valor: es un objeto pequeño (8 bytes) e inmutable, así que copiarlo no tiene costo real, y evita la complejidad de manejar memoria con punteros.

-Jugadores se maneja por el puntero (std::vector<Jugadores*>): a diferencia de Carta, cada jugador mantiene un estado que cambia durante toda la partida (mano, puntaje). Usar punteros asegura que exista una única instancia por jugador durante todo el juego, sin copias accidentales de ese estado.

-3 colores en vez de 2: con 11 números posibles, 2 colores solo darían 22 cartas que son insuficientes para repartir las 28 que hacen falta (4 jugadores por 7 cartas). Con 3 colores el mazo queda en 33 cartas, con margen de sobra.

-Fin de partida por conteo de rondas: en vez de revisar si algún jugador se quedó sin cartas, el juego termina automáticamente tras 7 rondas — justo las necesarias para repartir las 28 cartas iniciales, ya que cada ronda reparte exactamente 4.

Diagrama UML: 
<img width="956" height="682" alt="image" src="https://github.com/user-attachments/assets/8a7690f7-1e8b-443c-962d-96816d559166" />




Las cabras tiburones 3000:
-Cristopher Corrales Boada.
-Johan Hernando Lopez Londoño.
-Josué Tamayo Uribe.

