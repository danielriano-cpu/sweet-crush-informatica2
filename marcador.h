#ifndef MARCADOR_H
#define MARCADOR_H

int bytesNecesariosMarcador(int filas, int columnas);

unsigned char* crearMarcador(int filas, int columnas);

void liberarMarcador(unsigned char* marcador);

void marcarCelda(unsigned char* marcador, int indice);

int estaMarcada(unsigned char* marcador, int indice);

bool hayAlgunaMarcada(unsigned char* marcador, int totalCeldas);

#endif // MARCADOR_H
