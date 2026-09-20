#include <iostream>
#include "tablero.h"
#include "juego.h"
using namespace std;

int main(){

    int filas = 3;
    int columnas = 3;

    unsigned char* tablero = crearTablero(filas, columnas);

    // Board con mezcla de fichas reales y vacíos
    escribirFicha(tablero, 0, 0, columnas, 2);
    escribirFicha(tablero, 0, 1, columnas, 6);
    escribirFicha(tablero, 0, 2, columnas, 4);
    escribirFicha(tablero, 1, 0, columnas, 6);
    escribirFicha(tablero, 1, 1, columnas, 1);
    escribirFicha(tablero, 1, 2, columnas, 6);
    escribirFicha(tablero, 2, 0, columnas, 3);
    escribirFicha(tablero, 2, 1, columnas, 6);
    escribirFicha(tablero, 2, 2, columnas, 0);

    // Guardamos el estado "antes" para poder comparar después
    int antes[3][3];
    cout << "Antes de rellenar:" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            antes[f][c] = leerFicha(tablero, f, c, columnas);
            cout << antes[f][c] << " ";
        }
        cout << endl;
    }

    rellenarVacios(tablero, filas, columnas);

    cout << "Despues de rellenar:" << endl;
    bool todoBien = true;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            int actual = leerFicha(tablero, f, c, columnas);
            cout << actual << " ";

            if (antes[f][c] == 6){
                // era vacío: debe haber cambiado a un valor entre 0 y 5
                if (actual < 0 || actual > 5){
                    cout << "[FALLO en (" << f << "," << c << ") sigue vacío o fuera de rango] ";
                    todoBien = false;
                }
            } else {
                // no era vacío: no debió cambiar
                if (actual != antes[f][c]){
                    cout << "[FALLO en (" << f << "," << c << ") una ficha real fue modificada] ";
                    todoBien = false;
                }
            }
        }
        cout << endl;
    }

    if (todoBien){
        cout << "PRUEBA EXITOSA: todos los vacios se rellenaron y las fichas reales no se tocaron" << endl;
    } else {
        cout << "PRUEBA FALLIDA: revisa los mensajes de arriba" << endl;
    }

    liberarTablero(tablero);

    return 0;
}