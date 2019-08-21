#ifndef RUTAS_H_INCLUDED
#define RUTAS_H_INCLUDED
#include <stdio.h>
#include "Constantes.h"

typedef int Rutas[cant][cant];

void RutasCrear(Rutas rutas);

void RutasAgregarTramo(Rutas rutas, int vertice1, int vertice2);

bool RutasDFSecuencia(Rutas G, int verticeActual, int verticeFinal);

void RutasDFS(Rutas G, int verticeActual, bool visitado[cant], int verticeFinal);

bool RutasExisteTramo(Rutas rutas, int vertice1, int vertice2);

#endif // RUTAS_H_INCLUDED


