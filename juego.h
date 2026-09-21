#ifndef JUEGO_H
#define JUEGO_H

int detectarHorizontal(unsigned char* tablero, int filas, int columnas, unsigned char* marcador);

int detectarVertical(unsigned char* tablero, int filas, int columnas, unsigned char* marcador);

char convertirALetra(int codigo);

void eliminarMarcadas(unsigned char* tablero, int filas, int columnas, unsigned char* marcador);

void aplicarGravedad(unsigned char* tablero, int filas, int columnas);

void rellenarVacios(unsigned char* tablero, int filas, int columnas);

int resolverCascadas(unsigned char* tablero, int filas, int columnas, int* combinacionesDetectadas);

void iniciarTablero(unsigned char* tablero, int filas, int columnas);

void imprimirFichaBinario(int valor);

void mostrarEstadoJuego(unsigned char* tablero, int filas, int columnas,
                        int eliminacionesUsuario, int fichasEliminadasTotal,
                        int combinacionesDetectadas, int cascadasUltimaJugada,
                        int puntuacion);

int eliminarFichaJugador(unsigned char* tablero, int filas, int columnas, int fila, int columna, int* combinacionesDetectadas);

#endif // JUEGO_H
