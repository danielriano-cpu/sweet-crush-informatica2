#ifndef TABLERO_H
#define TABLERO_H

int calcularIndice(int fila, int columna, int columnas);

int calcularBitInicial(int Indice);

int leerFicha(unsigned char* ptr, int fila, int columna, int columnas);

void escribirFicha(unsigned char* ptr, int fila, int columna, int columnas, int valor);

int bytesNecesarios(int filas, int columnas);

unsigned char* crearTablero(int filas, int columnas);

void liberarTablero(unsigned char* ptr);

unsigned char* redimensionarTablero(unsigned char* viejo, int filasViejas, int columnasViejas, int filasNuevas, int columnasNuevas);

int generarFichaAleatoria();

void llenarTableroAleatorio(unsigned char* ptr, int filas, int columnas);

unsigned char* agregarFila(unsigned char* tablero, int filas, int columnas, int posicion, int* capacidadBytes);

unsigned char* eliminarFila(unsigned char* tablero, int filas, int columnas, int posicion, int* capacidadBytes);

unsigned char* agregarColumna(unsigned char* tablero, int filas, int columnas, int posicion, int* capacidadBytes);

unsigned char* eliminarColumna(unsigned char* tablero, int filas, int columnas, int posicion, int* capacidadBytes);


#endif // TABLERO_H