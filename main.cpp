#include <iostream>
#include "bits.h"
#include "tablero.h"

using namespace std;

int main()
{
    unsigned char tablero[3] = {0, 0, 0};

    escribirFicha(tablero, 0, 0, 3, 5);
    int resultado = leerFicha(tablero, 0, 0, 3);
    cout << resultado << endl;   // debería salir 5

    escribirFicha(tablero, 1, 2, 3, 6);
    int resultado2 = leerFicha(tablero, 1, 2, 3);
    cout << resultado2 << endl;  // debería salir 6

    return 0;
}
