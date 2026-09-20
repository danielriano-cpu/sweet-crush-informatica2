#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    // Tablero de 5 filas x 3 columnas
    unsigned char* tablero = crearTablero(5, 3);

    // Llenamos la columna 0 alternando valores, para evitar formar una racha sin querer
    int valoresAlternados[5] = {0, 1, 0, 1, 0};
    for(int f = 0; f < 5; f++){
        escribirFicha(tablero, f, 0, 3, valoresAlternados[f]);
    }

    // La combinación vertical la ponemos en la COLUMNA 2 (no la 0), filas 0,1,2
    escribirFicha(tablero, 0, 2, 3, 4);
    escribirFicha(tablero, 1, 2, 3, 4);
    escribirFicha(tablero, 2, 2, 3, 4);
    escribirFicha(tablero, 3, 2, 3, 1);
    escribirFicha(tablero, 4, 2, 3, 5);


    // Llenamos la columna 1 también alternando valores, para evitar formar una racha sin querer
    int valoresAlternados2[5] = {1, 0, 1, 0, 1};
    for(int f = 0; f < 5; f++){
        escribirFicha(tablero, f, 1, 3, valoresAlternados2[f]);
    }

    unsigned char* marcador = crearMarcador(5, 3);
    detectarVertical(tablero, 5, 3, marcador);

    for(int f = 0; f < 5; f++){
        for(int c = 0; c < 3; c++){
            int indice = calcularIndice(f, c, 3);
            int marcada = estaMarcada(marcador, indice);
            cout << "(" << f << "," << c << ") marcada=" << marcada << "  ";
        }
        cout << endl;
    }

    return 0;
}