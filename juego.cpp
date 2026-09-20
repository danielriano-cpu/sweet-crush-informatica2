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