#include <iostream>

#include "juego.h"
#include "tablero.h"
#include "marcador.h"
using namespace std;

int detectarHorizontal(unsigned char* tablero, int filas, int columnas, unsigned char* marcador){

    int contador = 0;
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

                contador++;
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

    return contador;
}

int detectarVertical(unsigned char* tablero, int filas, int columnas, unsigned char* marcador){

    int contador = 0;
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

                contador++;
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

    return contador;
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

int resolverCascadas(unsigned char* tablero, int filas, int columnas, int* combinacionesDetectadas){

    int cascadas = 0;

    while (true){

        unsigned char* marcadorNuevo = crearMarcador(filas, columnas);

        int comboH = detectarHorizontal(tablero, filas, columnas, marcadorNuevo);
        int comboV = detectarVertical(tablero, filas, columnas, marcadorNuevo);
        *combinacionesDetectadas = *combinacionesDetectadas + comboH + comboV;

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
    int combinacionesIniciales = 0;
    resolverCascadas(tablero, filas, columnas, &combinacionesIniciales);
}

void imprimirFichaBinario(int valor){
    int bit2 = (valor >> 2) & 1;
    int bit1 = (valor >> 1) & 1;
    int bit0 = valor & 1;
    cout << bit2 << bit1 << bit0;
}

void mostrarEstadoJuego(unsigned char* tablero, int filas, int columnas,
                        int eliminacionesUsuario, int fichasEliminadasTotal,
                        int combinacionesDetectadas, int cascadasUltimaJugada,
                        int puntuacion){

    cout << "--------------" << endl;
    cout << "Tablero (fichas):" << endl;
    cout << "  ";
    for(int c = 0; c < columnas; c++){
        cout << c << " ";
    }
    cout << endl;
    cout << "  ";
    for(int c = 0; c < columnas; c++){
        cout << "--";
    }
    cout << endl;
    for (int f = 0; f < filas; f++){
        cout << f << "|";
        for(int c = 0; c < columnas; c++){
            int valor = leerFicha(tablero, f, c, columnas);
            cout << convertirALetra(valor) << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "--------------" << endl;
    cout << "Tablero (binario):" << endl;
    cout << "  ";
    for(int c = 0; c < columnas; c++){
        cout << c << "   ";
    }
    cout << endl;
    cout << "  ";
    for(int c = 0; c < columnas; c++){
        cout << "----";
    }
    cout << endl;
    for (int f = 0; f < filas; f++){
        cout << f << "|";
        for(int c = 0; c < columnas; c++){
            int valor = leerFicha(tablero, f, c, columnas);
            imprimirFichaBinario(valor);
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "--------------" << endl;
    cout << "Dimensiones: " << filas << "x" << columnas << endl;
    cout << "Eliminaciones del usuario: " << eliminacionesUsuario << endl;
    cout << "Fichas eliminadas (total): " << fichasEliminadasTotal << endl;
    cout << "Combinaciones detectadas: " << combinacionesDetectadas << endl;
    cout << "Cascadas de esta jugada: " << cascadasUltimaJugada << endl;
    cout << "Puntuacion: " << puntuacion << endl;
    cout << "--------------" << endl;
}

int eliminarFichaJugador(unsigned char* tablero, int filas, int columnas, int fila, int columna, int* combinacionesDetectadas){

    if(fila < 0 || fila >= filas || columna < 0 || columna >= columnas){
        return -1;
    }

    escribirFicha(tablero, fila, columna, columnas, 6);

    aplicarGravedad(tablero, filas, columnas);
    rellenarVacios(tablero, filas, columnas);

    int cascadas = resolverCascadas(tablero, filas, columnas, combinacionesDetectadas);

    return cascadas;
}