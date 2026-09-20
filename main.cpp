#include <iostream>
#include "bits.h"
#include "tablero.h"
#include "marcador.h"
#include "juego.h"
using namespace std;

int main(){
    for(int codigo = 0; codigo <= 6; codigo++){
        char letra = convertirALetra(codigo);
        cout << "Codigo " << codigo << " -> " << letra << endl;
    }

    return 0;
}