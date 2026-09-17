#include <iostream>
#include "bits.h"

using namespace std;

int main()
{
    unsigned char prueba = 182;
    int resultado = obtener_bits(&prueba, 3, 3);
        cout<< resultado;

    asignar_bits(&prueba, 3, 3, 5);
    cout <<endl<< (int)prueba;

    return 0;
}
