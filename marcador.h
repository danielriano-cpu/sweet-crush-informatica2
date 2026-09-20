#ifndef MARCADOR_H
#define MARCADOR_H

int bytesNecesariosMarcador(int filas, int columnas);

unsigned char* crearMarcador(int filas, int columnas);

void marcarCelda(unsigned char* marcador, int indice);

int estaMarcada(unsigned char* marcador, int indice);

#endif // MARCADOR_H
