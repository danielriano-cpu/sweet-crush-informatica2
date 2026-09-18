#include <iostream>
#include "bits.h"

using namespace std;

int main()
{
    unsigned char prueba[2] = {128, 0};
    int resultado = obtener_bits(prueba, 7, 3);
    cout << resultado << endl;   // debería salir 1

    asignar_bits(prueba, 7, 3, 5);
    int resultado2 = obtener_bits(prueba, 7, 3);
    cout << resultado2 << endl;  // debería salir 5

    return 0;
}
