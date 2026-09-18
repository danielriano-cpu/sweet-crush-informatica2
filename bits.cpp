#include "bits.h"

int obtener_bits(unsigned char* ptr, int bitInicial, int cantidadBits){

    int byte = bitInicial/8;
    int offset = bitInicial % 8;

    if(offset + cantidadBits <= 8){
        int mask = (1 << cantidadBits) - 1;
        int valor = ptr[byte] >> offset & mask;
        return valor ;

    } else {
        int bitsEnPrimerByte = 8 - offset;
        int bitsEnSegundoByte = cantidadBits - bitsEnPrimerByte;
        int parteBaja = (ptr[byte] >> offset) & ((1 << bitsEnPrimerByte) - 1);
        int parteAlta = ptr[byte + 1] & ((1 << bitsEnSegundoByte) - 1);
        int valor = parteBaja | (parteAlta << bitsEnPrimerByte);
        return valor;

    }
}

void asignar_bits(unsigned char* ptr, int bitInicial, int cantidadBits, int valor){

    int byte = bitInicial/8;
    int offset = bitInicial % 8;

    if(offset + cantidadBits <= 8){
        int mask = (1 << cantidadBits) - 1;
        ptr[byte] = ptr[byte] & ~(mask << offset);
        ptr[byte] = ptr[byte] | (valor << offset);

    } else{
        int bitsEnPrimerByte = 8 - offset;
        int bitsEnSegundoByte = cantidadBits - bitsEnPrimerByte;
        int mascaraBaja = (1 << bitsEnPrimerByte) - 1;
        int mascaraAlta = (1 << bitsEnSegundoByte) - 1;

        ptr[byte] = ptr[byte] & ~(mascaraBaja << offset);
        ptr[byte] = ptr[byte] | ((valor & mascaraBaja) << offset);

        ptr[byte + 1] = ptr[byte + 1] & ~mascaraAlta;
        ptr[byte + 1] = ptr[byte + 1] | ((valor >> bitsEnPrimerByte) & mascaraAlta);

    }

}