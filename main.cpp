#include <iostream>
#include "tablero.h"
#include "juego.h"
using namespace std;

int main(){

    int filas = 4;
    int columnas = 3;

    unsigned char* tablero = crearTablero(filas, columnas);
    int capacidadBytes = bytesNecesarios(filas, columnas);

    // Llenamos con un patron conocido (no importa si forma combinaciones, no estamos probando eso aqui)
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            escribirFicha(tablero, f, c, columnas, (f * columnas + c) % 6);
        }
    }

    // Guardamos el estado "antes" para comparar despues
    int antes[4][3];
    cout << "Antes (4x3):" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            antes[f][c] = leerFicha(tablero, f, c, columnas);
            cout << convertirALetra(antes[f][c]) << " ";
        }
        cout << endl;
    }

    int posicion = 2; // insertamos la fila nueva justo en el medio

    tablero = agregarFila(tablero, filas, columnas, posicion, &capacidadBytes);
    filas = filas + 1; // ahora son 5 filas

    cout << "Despues de agregarFila en posicion " << posicion << " (5x3):" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++) cout << convertirALetra(leerFicha(tablero, f, c, columnas)) << " ";
        cout << endl;
    }

    // Verificaciones automaticas
    bool todoBien = true;

    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            int actual = leerFicha(tablero, f, c, columnas);

            if (f < posicion){
                // fila que no debio moverse
                if (actual != antes[f][c]){
                    cout << "FALLO en (" << f << "," << c << "): esperaba " << antes[f][c] << " (fila sin mover), obtuvo " << actual << endl;
                    todoBien = false;
                }
            } else if (f == posicion){
                // fila nueva: debe ser una ficha valida 0-5
                if (actual < 0 || actual > 5){
                    cout << "FALLO en (" << f << "," << c << "): la fila nueva no tiene un valor valido" << endl;
                    todoBien = false;
                }
            } else {
                // fila vieja que se recorrio una posicion hacia abajo
                if (actual != antes[f-1][c]){
                    cout << "FALLO en (" << f << "," << c << "): esperaba " << antes[f-1][c] << " (fila recorrida), obtuvo " << actual << endl;
                    todoBien = false;
                }
            }
        }
    }

    // Verificamos que capacidadBytes se haya actualizado correctamente
    int esperadoCapacidad = bytesNecesarios(filas, columnas);
    if (capacidadBytes != esperadoCapacidad){
        cout << "FALLO: capacidadBytes deberia ser " << esperadoCapacidad << " pero es " << capacidadBytes << endl;
        todoBien = false;
    }

    if (todoBien){
        cout << "PRUEBA EXITOSA: agregarFila inserta correctamente, conserva filas anteriores y posteriores, y actualiza capacidadBytes" << endl;
    } else {
        cout << "PRUEBA FALLIDA: revisa los mensajes de arriba" << endl;
    }

    liberarTablero(tablero);

    return 0;
}