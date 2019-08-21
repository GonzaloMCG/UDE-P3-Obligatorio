#include "Ciudad.h"

void CiudadCrear (Ciudad &ciudad, String nombre, int id)
{
    StringCrear(ciudad.nombre);
    StringCopiar(ciudad.nombre, nombre);
    ciudad.idciudad = id;
}

void CiudadLiberar(Ciudad &ciudad)
{
    StringDestruir(ciudad.nombre);
}

int CiudadDevolverID (Ciudad ciudad)
{
    return ciudad.idciudad;
}

void CiudadDevolverNombre (Ciudad ciudad, String &nombre)
{
    StringCopiar(nombre, ciudad.nombre);
}

void CiudadMostrar (Ciudad ciudad)
{
    StringMostrar(ciudad.nombre);
}
