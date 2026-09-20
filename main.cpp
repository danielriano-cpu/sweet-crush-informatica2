#include <iostream>
#include "tablero.h"
#include "juego.h"
using namespace std;

int main(){

    int filas = 5;
    int columnas = 2;

    unsigned char* tablero = crearTablero(filas, columnas);

    // Columna 0: 6,3,6,5,6  -> después de gravedad debe quedar: 6,6,6,3,5
    escribirFicha(tablero, 0, 0, columnas, 6);
    escribirFicha(tablero, 1, 0, columnas, 3);
    escribirFicha(tablero, 2, 0, columnas, 6);
    escribirFicha(tablero, 3, 0, columnas, 5);
    escribirFicha(tablero, 4, 0, columnas, 6);

    // Columna 1: 2,6,4,6,1  -> después de gravedad debe quedar: 6,6,2,4,1
    escribirFicha(tablero, 0, 1, columnas, 2);
    escribirFicha(tablero, 1, 1, columnas, 6);
    escribirFicha(tablero, 2, 1, columnas, 4);
    escribirFicha(tablero, 3, 1, columnas, 6);
    escribirFicha(tablero, 4, 1, columnas, 1);

    cout << "Antes de gravedad:" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            cout << (int)leerFicha(tablero, f, c, columnas) << " ";
        }
        cout << endl;
    }

    aplicarGravedad(tablero, filas, columnas);

    cout << "Despues de gravedad:" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            cout << (int)leerFicha(tablero, f, c, columnas) << " ";
        }
        cout << endl;
    }

    liberarTablero(tablero);

    return 0;
}