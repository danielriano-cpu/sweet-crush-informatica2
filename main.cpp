#include <iostream>
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    int filas = 4;
    int columnas = 3;

    // ---- PARTE A: probar detectarHorizontal/detectarVertical de forma aislada ----
    unsigned char* tablero1 = crearTablero(filas, columnas);

    escribirFicha(tablero1, 0, 0, columnas, 3);
    escribirFicha(tablero1, 0, 1, columnas, 1);
    escribirFicha(tablero1, 0, 2, columnas, 4);

    escribirFicha(tablero1, 1, 0, columnas, 3);
    escribirFicha(tablero1, 1, 1, columnas, 0);
    escribirFicha(tablero1, 1, 2, columnas, 1);

    escribirFicha(tablero1, 2, 0, columnas, 3);
    escribirFicha(tablero1, 2, 1, columnas, 4);
    escribirFicha(tablero1, 2, 2, columnas, 0);

    escribirFicha(tablero1, 3, 0, columnas, 2);
    escribirFicha(tablero1, 3, 1, columnas, 2);
    escribirFicha(tablero1, 3, 2, columnas, 2);

    cout << "--- Tablero inicial (parte A) ---" << endl;
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            cout << convertirALetra(leerFicha(tablero1, f, c, columnas)) << " ";
        }
        cout << endl;
    }

    unsigned char* marcador1 = crearMarcador(filas, columnas);
    int comboH = detectarHorizontal(tablero1, filas, columnas, marcador1);
    int comboV = detectarVertical(tablero1, filas, columnas, marcador1);

    cout << "comboH = " << comboH << " (esperado 1)" << endl;
    cout << "comboV = " << comboV << " (esperado 1)" << endl;

    liberarMarcador(marcador1);
    liberarTablero(tablero1);

    // ---- PARTE B: probar resolverCascadas completo sobre el mismo tablero ----
    unsigned char* tablero2 = crearTablero(filas, columnas);

    escribirFicha(tablero2, 0, 0, columnas, 3);
    escribirFicha(tablero2, 0, 1, columnas, 1);
    escribirFicha(tablero2, 0, 2, columnas, 4);

    escribirFicha(tablero2, 1, 0, columnas, 3);
    escribirFicha(tablero2, 1, 1, columnas, 0);
    escribirFicha(tablero2, 1, 2, columnas, 1);

    escribirFicha(tablero2, 2, 0, columnas, 3);
    escribirFicha(tablero2, 2, 1, columnas, 4);
    escribirFicha(tablero2, 2, 2, columnas, 0);

    escribirFicha(tablero2, 3, 0, columnas, 2);
    escribirFicha(tablero2, 3, 1, columnas, 2);
    escribirFicha(tablero2, 3, 2, columnas, 2);

    int combinacionesDetectadas = 0;
    int cascadas = resolverCascadas(tablero2, filas, columnas, &combinacionesDetectadas);

    cout << "\n--- Tablero final (parte B, tras resolverCascadas) ---" << endl;
    for(int f = 0; f < filas; f++){
        for(int c = 0; c < columnas; c++){
            cout << convertirALetra(leerFicha(tablero2, f, c, columnas)) << " ";
        }
        cout << endl;
    }

    cout << "cascadas = " << cascadas << " (esperado minimo 1)" << endl;
    cout << "combinacionesDetectadas = " << combinacionesDetectadas << " (esperado minimo 2)" << endl;

    liberarTablero(tablero2);

    return 0;
}