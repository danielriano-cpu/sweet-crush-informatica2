#include <iostream>
#include "bits.h"
#include "tablero.h"

using namespace std;

int main()
{

    unsigned char* tablero = crearTablero(3,3);
    llenarTableroAleatorio(tablero, 3, 3);


    for(int f = 0; f < 3; f++){
        for(int c = 0; c < 3; c++){
            int valor = leerFicha(tablero, f, c, 3);
            cout << valor << " ";
        }
        cout << endl;
    }
}