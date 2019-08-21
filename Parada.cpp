#include "Parada.h"

void ParadaCrear(Parada &parada, String nombre, int numero)
{
    StringCrear(parada.nombre);
    StringCopiar(parada.nombre, nombre);
    parada.numero = numero;
}

int ParadaDevolverNumero (Parada parada)
{
    return parada.numero;
}

void ParadaDevolverNombre (Parada parada, String &nombre)
{
    StringCopiar(nombre, parada.nombre);
}

void ParadaMostrar(Parada parada)
{
    printf("\n");
    printf("Numero de Parada: %d, ", parada.numero);
    printf("Ciudad: ");
    StringMostrar(parada.nombre);
    printf("\n");
}

void ParadaDestruir(Parada parada)
{
    StringDestruir(parada.nombre);
}

void ParadaModificarNumero (Parada &parada, int numero)
{
    parada.numero = numero;
}
