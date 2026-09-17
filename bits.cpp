#include "bits.h"

int obtener_bits(unsigned char* ptr, int bitInicial, int cantidadBits){

    int byte = bitInicial/8;
    int offset = bitInicial % 8;
    int mask = (1 << cantidadBits) - 1;
    int valor = ptr[byte] >> offset & mask;
    return valor ;
}

void asignar_bits(unsigned char* ptr, int bitInicial, int cantidadBits, int valor){

    int byte = bitInicial/8;
    int offset = bitInicial % 8;
    int mask = (1 << cantidadBits) - 1;
    ptr[byte] = ptr[byte] & ~(mask << offset);
    ptr[byte] = ptr[byte] | (valor << offset);

}