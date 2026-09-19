#include <iostream>
#include "bits.h"
#include "tablero.h"

using namespace std;

int main()
{

    unsigned char* tablero = crearTablero(2,2);

    escribirFicha(tablero, 0, 0, 2, 3);
    escribirFicha(tablero, 1, 1, 2, 5);

    tablero = redimensionarTablero(tablero, 2, 2, 3, 3);

    int resultado1 = leerFicha(tablero, 0, 0, 3);
    int resultado2 = leerFicha(tablero, 1, 1, 3);

    cout << resultado1 << endl;
    cout << resultado2 << endl;

    return 0;
}
