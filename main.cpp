#include <iostream>
#include "tablero.h"
#include "juego.h"
#include "marcador.h"
using namespace std;

int main(){

    int filas = 5;
    int columnas = 5;

    unsigned char* tablero = crearTablero(filas, columnas);

    // Llenamos con un patron que NO forme combinaciones por si solo
    // (alternando 0,1,2 en diagonal para evitar rachas accidentales)
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            escribirFicha(tablero, f, c, columnas, (f + c) % 3);
        }
    }

    // Forzamos una combinacion horizontal real en la fila 2: tres "4" seguidos
    escribirFicha(tablero, 2, 0, columnas, 4);
    escribirFicha(tablero, 2, 1, columnas, 4);
    escribirFicha(tablero, 2, 2, columnas, 4);

    cout << "Antes de resolver:" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++) cout << convertirALetra(leerFicha(tablero, f, c, columnas)) << " ";
        cout << endl;
    }

    int cascadas = resolverCascadas(tablero, filas, columnas);

    cout << "Despues de resolver (" << cascadas << " cascada(s)):" << endl;
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++) cout << convertirALetra(leerFicha(tablero, f, c, columnas)) << " ";
        cout << endl;
    }

    // Verificamos que ya no quede ninguna combinacion pendiente
    unsigned char* marcadorFinal = crearMarcador(filas, columnas);
    detectarHorizontal(tablero, filas, columnas, marcadorFinal);
    detectarVertical(tablero, filas, columnas, marcadorFinal);
    bool quedaAlgo = hayAlgunaMarcada(marcadorFinal, filas * columnas);
    liberarMarcador(marcadorFinal);

    if (cascadas >= 1 && quedaAlgo == false){
        cout << "PRUEBA EXITOSA: se resolvio al menos una cascada y no quedan combinaciones" << endl;
    } else {
        cout << "PRUEBA FALLIDA: cascadas=" << cascadas << " quedaAlgo=" << quedaAlgo << endl;
    }

    liberarTablero(tablero);

    return 0;
}