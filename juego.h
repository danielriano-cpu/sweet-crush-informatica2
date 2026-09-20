#ifndef JUEGO_H
#define JUEGO_H

void detectarHorizontal(unsigned char* tablero, int filas, int columnas, unsigned char* marcador);

void detectarVertical(unsigned char* tablero, int filas, int columnas, unsigned char* marcador);

char convertirALetra(int codigo);

#endif // JUEGO_H
