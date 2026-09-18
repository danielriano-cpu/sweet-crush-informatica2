#ifndef TABLERO_H
#define TABLERO_H

int calcularIndice(int fila, int columna, int columnas);

int calcularBitInicial(int Indice);

int leerFicha(unsigned char* ptr, int fila, int columna, int columnas);

void escribirFicha(unsigned char* ptr, int fila, int columna, int columnas, int valor);

int bytesNecesarios(int filas, int columnas);


#endif // TABLERO_H