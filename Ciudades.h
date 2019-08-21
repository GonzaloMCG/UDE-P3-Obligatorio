#ifndef CIUDADES_H_INCLUDED
#define CIUDADES_H_INCLUDED
#include "Ciudad.h"
#include "Constantes.h"


typedef struct nodoC {Ciudad ciudad;
                      nodoC * sig;
                      }NodoCiudades;

typedef NodoCiudades * ListaCiudad;

typedef ListaCiudad Ciudades[cant];



void CiudadesCrear (Ciudades &ciudades);

void CiudadesLiberar(Ciudades &ciudades);

void CiudadesCrearLista (ListaCiudad &listaciudad);

int CiudadesH(String clave);

bool CiudadesPerteneceALista (ListaCiudad listaciudad, String clave);

bool CiudadesPertenece (Ciudades ciudades, String clave);

void CiudadesInsfront (ListaCiudad &listaciudad, Ciudad ciudad);

//Precondición: !Pertenece(ciudades,CiudadDevolverID(ciudad))
void CiudadesInsertar (Ciudades &ciudades, Ciudad ciudad);

Ciudad CiudadesObtenerEnLista (ListaCiudad listaciudad, String clave);

//Precondición: Pertenece(ciudades, clave)
Ciudad CiudadesObtener (Ciudades ciudades, String clave);

void CiudadesBorrarPrimeroEnLista (ListaCiudad &listaciudad);

void CiudadesBorrarEnLista (ListaCiudad &listaciudad, String clave);

//Precondición: Pertenece(ciudades,clave)
void CiudadesEliminar (Ciudades &ciudades, String clave);

void CiudadesMostrar(Ciudades ciudades);

#endif // CIUDADES_H_INCLUDED
