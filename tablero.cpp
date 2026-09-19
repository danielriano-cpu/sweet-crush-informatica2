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

unsigned char* crearTablero(int filas, int columnas){

    int bytes = bytesNecesarios(filas, columnas);

    unsigned char* nuevo = new unsigned char [bytes];

    for (int i = 0; i < bytes; i++){
        nuevo[i]= 0;
    }

    return nuevo;
}

void liberarTablero(unsigned char* ptr){

    delete[]ptr;
}

unsigned char* redimensionarTablero(unsigned char* viejo, int filasViejas, int columnasViejas, int filasNuevas, int columnasNuevas){

    unsigned char*  tableroNuevo = crearTablero(filasNuevas, columnasNuevas);

    int filasLimite;
    //Asignamos como limite al menor entre filas viejas y nuevas
    if (filasViejas < filasNuevas){

        filasLimite = filasViejas;

    }else{
        filasLimite = filasNuevas;
    }

    int columnasLimite;
    //Asignamos como limite al menor entre columnas viejas y nuevas
    if (columnasViejas < columnasNuevas){

        columnasLimite = columnasViejas;

    }else{
        columnasLimite = columnasNuevas;
    }

    for (int f = 0; f < filasLimite; f++){

        for(int c = 0; c < columnasLimite; c++){

           int valor = leerFicha(viejo, f, c, columnasViejas);

            escribirFicha(tableroNuevo, f, c, columnasNuevas, valor);

        }
    }

    liberarTablero(viejo);

    return tableroNuevo;
}