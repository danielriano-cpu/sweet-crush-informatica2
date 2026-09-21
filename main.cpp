#include <iostream>
#include "tablero.h"
#include "juego.h"
using namespace std;

int main(){

    int filas = 4;
    int columnas = 10;

    unsigned char* tablero = crearTablero(filas, columnas);
    int capacidadBytes = bytesNecesarios(filas, columnas); // 15 bytes al inicio

    // Llenamos con un patron conocido y determinista
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            escribirFicha(tablero, f, c, columnas, (f * columnas + c) % 6);
        }
    }

    // Espejo "esperado"
    int esperado[4][10];
    for (int f = 0; f < filas; f++){
        for (int c = 0; c < columnas; c++){
            esperado[f][c] = (f * columnas + c) % 6;
        }
    }
    int columnasEsperadas = columnas;

    int posicion = 1; // siempre eliminamos la columna en indice 1 (posicion intermedia)
    bool todoBien = true;

    // Con filas=4, empezando en 10 columnas, esto da 3 eliminaciones que NO deben encoger
    // seguidas de una 4ta que SI debe encoger (misma progresion numerica que en eliminarFila)
    for (int intento = 0; intento < 4; intento++){

        unsigned char* punteroAntes = tablero;
        int capacidadAntes = capacidadBytes;

        tablero = eliminarColumna(tablero, filas, columnas, posicion, &capacidadBytes);
        columnas = columnas - 1;

        // Actualizamos el espejo esperado quitando la columna 'posicion'
        for (int f = 0; f < filas; f++){
            for (int c = posicion; c < columnasEsperadas - 1; c++){
                esperado[f][c] = esperado[f][c+1];
            }
        }
        columnasEsperadas = columnasEsperadas - 1;

        // Verificamos el contenido
        for (int f = 0; f < filas; f++){
            for (int c = 0; c < columnas; c++){
                int actual = leerFicha(tablero, f, c, columnas);
                if (actual != esperado[f][c]){
                    cout << "FALLO intento " << intento << " en (" << f << "," << c << "): esperaba " << esperado[f][c] << " obtuvo " << actual << endl;
                    todoBien = false;
                }
            }
        }

        // Verificamos la regla del 65%
        int bytesNecesariosAhora = bytesNecesarios(filas, columnas);
        bool deberiaEncoger = (bytesNecesariosAhora < 0.65 * capacidadAntes);
        bool siEncogio = (tablero != punteroAntes);

        cout << "Intento " << intento << ": columnas=" << columnas
             << " bytesNecesarios=" << bytesNecesariosAhora
             << " capacidadAntes=" << capacidadAntes
             << " capacidadDespues=" << capacidadBytes
             << " encogio=" << siEncogio << " (esperado=" << deberiaEncoger << ")" << endl;

        if (siEncogio != deberiaEncoger){
            cout << "FALLO intento " << intento << ": no encogio cuando debia (o viceversa)" << endl;
            todoBien = false;
        }
        if (siEncogio && capacidadBytes != bytesNecesariosAhora){
            cout << "FALLO intento " << intento << ": capacidadBytes no quedo exacta tras encoger" << endl;
            todoBien = false;
        }
        if (!siEncogio && capacidadBytes != capacidadAntes){
            cout << "FALLO intento " << intento << ": capacidadBytes cambio sin haber encogido" << endl;
            todoBien = false;
        }
    }

    if (todoBien){
        cout << "PRUEBA EXITOSA: eliminarColumna elimina correctamente en posicion intermedia y respeta la regla del 65%" << endl;
    } else {
        cout << "PRUEBA FALLIDA: revisa los mensajes de arriba" << endl;
    }

    liberarTablero(tablero);

    return 0;
}