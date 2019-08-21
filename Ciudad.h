#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED
#include "String.h"

typedef struct {String nombre;
                int idciudad;
                }Ciudad;

void CiudadCrear (Ciudad &ciudad, String nombre, int id);

void CiudadLiberar(Ciudad &ciudad);

void CiudadDevolverNombre (Ciudad ciudad, String &nombre);

int CiudadDevolverID (Ciudad ciudad);

void CiudadMostrar (Ciudad ciudad);

#endif // CIUDAD_H_INCLUDED
