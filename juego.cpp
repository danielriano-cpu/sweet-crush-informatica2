#include "juego.h"
#include "tablero.h"
#include "marcador.h"

void detectarHorizontal(unsigned char* tablero, int filas, int columnas, unsigned char* marcador){

    for (int f = 0; f < filas;f++){

        int racha = 1;

        for(int c = 0; c < columnas; c++){

            int valor = leerFicha(tablero, f, c, columnas);

            if(c == 0){

                racha = 1;

            }else{

                int valorAnterior = leerFicha(tablero, f, c-1, columnas);

                if (valor == valorAnterior){

                    racha = racha + 1;

                }else{
                    racha = 1;
                }

            }

            if (racha == 3){
                int indiceAnterior1 = calcularIndice(f, c-1, columnas);
                int indiceAnterior2 = calcularIndice(f, c-2, columnas);
                marcarCelda(marcador, indiceAnterior1);
                marcarCelda(marcador, indiceAnterior2);

            }

            if (racha >= 3){
                int indice = calcularIndice(f, c, columnas);
                marcarCelda(marcador, indice);

            }


        }

    }


}

void detectarVertical(unsigned char* tablero, int filas, int columnas, unsigned char* marcador){

    for (int c = 0; c < columnas; c++){

        int racha = 1;

        for(int f = 0; f < filas;f++){

            int valor = leerFicha(tablero, f, c, columnas);

            if(f == 0){

                racha = 1;

            }else{

                int valorAnterior = leerFicha(tablero, f-1, c, columnas);

                if (valor == valorAnterior){

                    racha = racha + 1;

                }else{
                    racha = 1;
                }

            }

            if (racha == 3){
                int indiceAnterior1 = calcularIndice(f-1, c, columnas);
                int indiceAnterior2 = calcularIndice(f-2, c, columnas);
                marcarCelda(marcador, indiceAnterior1);
                marcarCelda(marcador, indiceAnterior2);

            }

            if (racha >= 3){
                int indice = calcularIndice(f, c, columnas);
                marcarCelda(marcador, indice);

            }


        }

    }

}

char convertirALetra(int codigo){
    if(codigo == 6){
        return 'V';
    }else{
        return 'A' + codigo;
    }
}

void eliminarMarcadas(unsigned char* tablero, int filas, int columnas, unsigned char* marcador){

    for (int c = 0; c < columnas; c++){

        for(int f = 0; f < filas;f++){

            int indice = calcularIndice(f, c, columnas);

            int marca = estaMarcada(marcador, indice);

            if(marca == 1){

                escribirFicha(tablero, f, c, columnas, 6);

            }
        }
    }
}

void aplicarGravedad(unsigned char* tablero, int filas, int columnas){

    for (int c = 0; c < columnas; c++){

        int filaEscritura = filas - 1;

        for(int f = filas - 1; f >= 0; f--){

            int ficha = leerFicha(tablero, f, c, columnas);

            if (ficha != 6){
                escribirFicha(tablero, filaEscritura, c, columnas, ficha);
                filaEscritura--;
            }

        }

        for(int f = filaEscritura; f >= 0; f--) escribirFicha(tablero, f, c, columnas, 6);
    }
}

void rellenarVacios(unsigned char* tablero, int filas, int columnas){

    for (int c = 0; c < columnas; c++){

        for(int f = 0; f < filas;f++){

            int ficha = leerFicha(tablero, f, c, columnas);

            if(ficha == 6){

                int fichaNueva = generarFichaAleatoria();

                escribirFicha(tablero, f, c, columnas, fichaNueva);

            }
        }
    }
}

int resolverCascadas(unsigned char* tablero, int filas, int columnas){

    int cascadas = 0;

    while (true){

        unsigned char* marcadorNuevo = crearMarcador(filas, columnas);

        detectarHorizontal(tablero, filas, columnas, marcadorNuevo);

        detectarVertical(tablero, filas, columnas, marcadorNuevo);

        if (hayAlgunaMarcada(marcadorNuevo, filas*columnas)){

            eliminarMarcadas(tablero, filas, columnas, marcadorNuevo);
            aplicarGravedad(tablero, filas, columnas);
            rellenarVacios(tablero, filas, columnas);

            cascadas++;

            liberarMarcador(marcadorNuevo);


        }else{

            liberarMarcador(marcadorNuevo); break;

        }

    }

    return cascadas;
}

void iniciarTablero(unsigned char* tablero, int filas, int columnas){

    llenarTableroAleatorio(tablero, filas, columnas);
    resolverCascadas(tablero, filas, columnas);
}