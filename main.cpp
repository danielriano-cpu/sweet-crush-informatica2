#include <iostream>
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    int filas = 4;
    int columnas = 4;

    unsigned char* tablero = crearTablero(filas, columnas);
    iniciarTablero(tablero, filas, columnas);

    int eliminacionesUsuario = 3;
    int fichasEliminadasTotal = 12;
    int combinacionesDetectadas = 7;
    int cascadasUltimaJugada = 2;
    int puntuacion = 95;

    mostrarEstadoJuego(tablero, filas, columnas,
                       eliminacionesUsuario, fichasEliminadasTotal,
                       combinacionesDetectadas, cascadasUltimaJugada,
                       puntuacion);

    liberarTablero(tablero);

    return 0;
}