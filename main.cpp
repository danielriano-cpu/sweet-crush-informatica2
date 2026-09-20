#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    // Creamos un tablero de 2 filas x 3 columnas (6 celdas en total)
    unsigned char* tablero = crearTablero(2, 3);

    // Llenamos el tablero con valores conocidos, celda por celda,
    // para poder predecir exactamente qué debería pasar después.
    // escribirFicha(tablero, fila, columna, columnasTotales, valor)
    escribirFicha(tablero, 0, 0, 3, 1);   // fila 0, columna 0 -> ficha 1
    escribirFicha(tablero, 0, 1, 3, 2);   // fila 0, columna 1 -> ficha 2
    escribirFicha(tablero, 0, 2, 3, 3);   // fila 0, columna 2 -> ficha 3
    escribirFicha(tablero, 1, 0, 3, 4);   // fila 1, columna 0 -> ficha 4
    escribirFicha(tablero, 1, 1, 3, 5);   // fila 1, columna 1 -> ficha 5
    escribirFicha(tablero, 1, 2, 3, 0);   // fila 1, columna 2 -> ficha 0

    // Creamos el marcador correspondiente (mismo tamaño que el tablero),
    // arranca todo en 0 (ninguna celda marcada)
    unsigned char* marcador = crearMarcador(2, 3);

    // Marcamos DOS celdas a mano, simulando que ya se detectó
    // una combinación en esas posiciones (sin necesidad de correr
    // detectarHorizontal/detectarVertical, solo para probar eliminarMarcadas
    // de forma aislada y controlada)
    marcarCelda(marcador, calcularIndice(0, 1, 3));   // marca la celda (0,1)
    marcarCelda(marcador, calcularIndice(1, 2, 3));   // marca la celda (1,2)

    // Corremos la función que estamos probando: debería escribir
    // el código 6 (vacío) en cada celda marcada, y dejar el resto intacto
    eliminarMarcadas(tablero, 2, 3, marcador);

    // Recorremos todo el tablero e imprimimos el valor final de cada celda,
    // para verificar visualmente el resultado
    for(int f = 0; f < 2; f++){
        for(int c = 0; c < 3; c++){
            int valor = leerFicha(tablero, f, c, 3);
            cout << "(" << f << "," << c << ")=" << valor << "  ";
        }
        cout << endl;
    }

    return 0;
}