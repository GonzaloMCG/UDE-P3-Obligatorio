#ifndef PARADA_H_INCLUDED
#define PARADA_H_INCLUDED
#include "String.h"

typedef struct {int numero;
                String nombre;
                }Parada;

void ParadaCrear(Parada &parada, String nombre, int numero);

int ParadaDevolverNumero (Parada parada);

void ParadaDevolverNombre (Parada parada, String &nombre);

void ParadaMostrar(Parada parada);

void ParadaDestruir(Parada parada);

void ParadaModificarNumero (Parada &parada, int numero);

#endif // PARADA_H_INCLUDED
