#include <iostream>
#include "tablero.h"
#include "juego.h"
using namespace std;

int main(){

    cout << "========================================" << endl;
    cout << "              SWEET CRUSH" << endl;
    cout << "========================================" << endl;
    cout << endl;

    int filas;

    cout << "Elija las dimensiones de su tablero" <<endl;
    cout << "Ingrese el numero de filas (minimo 3): ";
    cin >> filas;
    while(filas < 3){
        cout << "Valor invalido. Debe ser al menos 3. Ingrese el numero de filas: ";
        cin >> filas;
    }

    int columnas;
    cout << "Ingrese el numero de columnas (minimo 3): ";
    cin >> columnas;
    while(columnas < 3){
        cout << "Valor invalido. Debe ser al menos 3. Ingrese el numero de columnas: ";
        cin >> columnas;
    }

    unsigned char *tablero = crearTablero(filas, columnas);
    iniciarTablero(tablero, filas, columnas);
    int capacidadBytes = bytesNecesarios(filas, columnas);

    int eliminacionesUsuario = 0;
    int fichasEliminadasTotal = 0;
    int combinacionesDetectadas = 0;
    int puntuacion = 0;

    mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, 0, puntuacion);

    int opcion = -1;
    while(opcion != 0){
        cout << "0. Salir" << endl;
        cout << "1. Eliminar ficha" << endl;
        cout << "2. Agregar fila" << endl;
        cout << "3. Eliminar fila" << endl;
        cout << "4. Agregar columna" << endl;
        cout << "5. Eliminar columna" << endl;
        cin >> opcion;

        if(opcion == 1){
            int fila, columna;
            cout << "Fila: ";
            cin >> fila;
            cout << "Columna: ";
            cin >> columna;

            int combinacionesAntes = combinacionesDetectadas;   // <-- INSERCION 1: antes de la accion

            int cascadas = eliminarFichaJugador(tablero, filas, columnas, fila, columna, &combinacionesDetectadas);

            if(cascadas == -1){
                cout << "Posicion invalida, intenta de nuevo" << endl;
            } else {
                eliminacionesUsuario = eliminacionesUsuario + 1;
                fichasEliminadasTotal = fichasEliminadasTotal + 1;

                // <-- INSERCION 2: calculo de puntuacion, antes de mostrarEstadoJuego
                int combinacionesEstaJugada = combinacionesDetectadas - combinacionesAntes;
                int bonoCascadas = 5 * (cascadas - 1);
                if(cascadas <= 0){
                    bonoCascadas = 0;
                }
                int puntuacionJugada = 10 * combinacionesEstaJugada + bonoCascadas;
                puntuacion = puntuacion + puntuacionJugada;

                mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, cascadas, puntuacion);
            }
        }

        else if(opcion == 2){
            int posicion;
            cout << "Posicion: ";
            cin >> posicion;

            int combinacionesAntes = combinacionesDetectadas;

            if(posicion < 0 || posicion > filas){
                cout << "Posicion invalida, intenta de nuevo" << endl;
            } else {
                tablero = agregarFila(tablero, filas, columnas, posicion, &capacidadBytes);
                filas = filas + 1;
                int cascadas = resolverCascadas(tablero, filas, columnas, &combinacionesDetectadas);

                // <-- INSERCION 2: calculo de puntuacion, antes de mostrarEstadoJuego
                int combinacionesEstaJugada = combinacionesDetectadas - combinacionesAntes;
                int bonoCascadas = 5 * (cascadas - 1);
                if(cascadas <= 0){
                    bonoCascadas = 0;
                }
                int puntuacionJugada = 10 * combinacionesEstaJugada + bonoCascadas;
                puntuacion = puntuacion + puntuacionJugada;

                mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, cascadas, puntuacion);
            }
        }

        else if (opcion == 3) {
            int posicion = 0;
            cout << "Ingrese la posicion de la fila a eliminar (0 a " << filas - 1 << "): ";
            cin >> posicion;

            int combinacionesAntes = combinacionesDetectadas;

            // ojo: aqui es >= filas, no > filas, porque debe ser una fila EXISTENTE
            if (posicion < 0 || posicion >= filas) {
                cout << "Posicion invalida." << endl;
            } else {
                tablero = eliminarFila(tablero, filas, columnas, posicion, &capacidadBytes);
                filas--;
                int cascadas = resolverCascadas(tablero, filas, columnas, &combinacionesDetectadas);

                // <-- INSERCION 2: calculo de puntuacion, antes de mostrarEstadoJuego
                int combinacionesEstaJugada = combinacionesDetectadas - combinacionesAntes;
                int bonoCascadas = 5 * (cascadas - 1);
                if(cascadas <= 0){
                    bonoCascadas = 0;
                }
                int puntuacionJugada = 10 * combinacionesEstaJugada + bonoCascadas;
                puntuacion = puntuacion + puntuacionJugada;

                mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, cascadas, puntuacion);
            }
        }

        else if (opcion == 4) {
            int posicion = 0;
            cout << "Ingrese la posicion de la columna a agregar (0 a " << columnas << "): ";
            cin >> posicion;

            int combinacionesAntes = combinacionesDetectadas;

            if (posicion < 0 || posicion > columnas) {
                cout << "Posicion invalida." << endl;
            } else {
                tablero = agregarColumna(tablero, filas, columnas, posicion, &capacidadBytes);
                columnas++;
                int cascadas = resolverCascadas(tablero, filas, columnas, &combinacionesDetectadas);

                // <-- INSERCION 2: calculo de puntuacion, antes de mostrarEstadoJuego
                int combinacionesEstaJugada = combinacionesDetectadas - combinacionesAntes;
                int bonoCascadas = 5 * (cascadas - 1);
                if(cascadas <= 0){
                    bonoCascadas = 0;
                }
                int puntuacionJugada = 10 * combinacionesEstaJugada + bonoCascadas;
                puntuacion = puntuacion + puntuacionJugada;


                mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, cascadas, puntuacion);
            }
        }

        else if (opcion == 5) {
            int posicion = 0;
            cout << "Ingrese la posicion de la columna a eliminar (0 a " << columnas - 1 << "): ";
            cin >> posicion;

            int combinacionesAntes = combinacionesDetectadas;

            // Se usa >= porque debe ser una columna EXISTENTE
            if (posicion < 0 || posicion >= columnas) {
                cout << "Posicion invalida." << endl;
            } else {
                tablero = eliminarColumna(tablero, filas, columnas, posicion, &capacidadBytes);
                columnas--;
                int cascadas = resolverCascadas(tablero, filas, columnas, &combinacionesDetectadas);

                // <-- INSERCION 2: calculo de puntuacion, antes de mostrarEstadoJuego
                int combinacionesEstaJugada = combinacionesDetectadas - combinacionesAntes;
                int bonoCascadas = 5 * (cascadas - 1);
                if(cascadas <= 0){
                    bonoCascadas = 0;
                }
                int puntuacionJugada = 10 * combinacionesEstaJugada + bonoCascadas;
                puntuacion = puntuacion + puntuacionJugada;


                mostrarEstadoJuego(tablero, filas, columnas, eliminacionesUsuario, fichasEliminadasTotal, combinacionesDetectadas, cascadas, puntuacion);
            }
        }

    }

    liberarTablero(tablero);
}