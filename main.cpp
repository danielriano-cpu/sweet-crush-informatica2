#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    // Armamos un tablero de 1 fila x 5 columnas, a mano, para controlar el caso de prueba
    unsigned char* tablero = crearTablero(1, 5);
    escribirFicha(tablero, 0, 0, 5, 2);
    escribirFicha(tablero, 0, 1, 5, 2);
    escribirFicha(tablero, 0, 2, 5, 2);
    escribirFicha(tablero, 0, 3, 5, 5);
    escribirFicha(tablero, 0, 4, 5, 1);

    // Creamos el marcador correspondiente (arranca todo en 0, sin ninguna celda marcada)
    unsigned char* marcador = crearMarcador(1, 5);

    // Corremos la detección horizontal
    detectarHorizontal(tablero, 1, 5, marcador);

    // Imprimimos las fichas y si quedaron marcadas o no
    for(int c = 0; c < 5; c++){
        int valor = leerFicha(tablero, 0, c, 5);
        int indice = calcularIndice(0, c, 5);
        int marcada = estaMarcada(marcador, indice);
        cout << "Columna " << c << ": ficha=" << valor << " marcada=" << marcada << endl;
    }

    return 0;
}