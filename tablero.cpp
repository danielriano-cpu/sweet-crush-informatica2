#include "tablero.h"
#include "bits.h"

int calcularIndice(int fila, int columna, int columnas){

    int Indice = fila * columnas + columna;
    return Indice;
}

int calcularBitInicial(int Indice){

    int BitInicial = Indice * 3;
    return BitInicial;

}

int leerFicha(unsigned char* ptr, int fila, int columna, int columnas){

    int Indice = calcularIndice(fila, columna, columnas);
    int BitInicial = calcularBitInicial(Indice);
    return obtener_bits(ptr, BitInicial, 3);

}

void escribirFicha(unsigned char* ptr, int fila, int columna, int columnas, int valor){

    int Indice = calcularIndice(fila, columna, columnas);
    int BitInicial = calcularBitInicial(Indice);
    asignar_bits(ptr, BitInicial, 3, valor);

}

int bytesNecesarios(int filas, int columnas){

    int bits = 3 * filas * columnas;
    return (bits + 7) / 8;
}
