#include <iostream>
#include "tablero.h"
#include "juego.h"
#include "marcador.h"
using namespace std;

int main(){

    int filas = 6;
    int columnas = 6;

    unsigned char* tablero = crearTablero(filas, columnas);

    int intentos = 50;
    bool todoBien = true;

    for (int i = 0; i < intentos; i++){

        iniciarTablero(tablero, filas, columnas);

        unsigned char* marcador = crearMarcador(filas, columnas);
        detectarHorizontal(tablero, filas, columnas, marcador);
        detectarVertical(tablero, filas, columnas, marcador);
        bool quedaAlgo = hayAlgunaMarcada(marcador, filas * columnas);
        liberarMarcador(marcador);

        if (quedaAlgo){
            cout << "FALLO en el intento " << i << ": quedo una combinacion sin resolver" << endl;
            todoBien = false;
        }
    }

    if (todoBien){
        cout << "PRUEBA EXITOSA: " << intentos << " tableros iniciados, ninguno quedo con combinaciones pendientes" << endl;
    } else {
        cout << "PRUEBA FALLIDA: revisa los mensajes de arriba" << endl;
    }

    // Mostramos el ultimo tablero generado, solo para verlo
    cout << "Ultimo tablero generado:" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++) cout << convertirALetra(leerFicha(tablero, f, c, columnas)) << " ";
        cout << endl;
    }

    liberarTablero(tablero);

    return 0;
}