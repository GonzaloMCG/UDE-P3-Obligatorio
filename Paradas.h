#ifndef PARADAS_H_INCLUDED
#define PARADAS_H_INCLUDED
#include "Parada.h"

typedef struct nodoP {Parada parada;
                      nodoP * sig;
                      }NodoParadas;

typedef struct {NodoParadas * prim;
                NodoParadas * ult;
                }Paradas;


//Crea una lista LPPF de Paradas
void ParadasCrear (Paradas &p);

void ParadasLiberar(Paradas &p);

//Pregunta si la lista es vacia
bool ParadasVacia (Paradas p);

//Devuelve la primer parada de la lista
//Precondición: !Vacia(p)
Parada ParadasPrimero (Paradas p);

//devuelve la ultima parada de la lista
//Precondición: !Vacia(p)
Parada ParadasUltimo (Paradas p);

//Devuelve la lista menos el primer elemento
//Precondición : !Vacia(p)
void ParadasResto (Paradas &p);

//Inserta una nueva parada al principio de la lista
void ParadasInsfront (Paradas &p, Parada nuevap);

//Inserta una nueva parada al final de la lista
void ParadasInsback (Paradas &p, String nombre);

//Devuelve la cantidad de paradas en la lista
int ParadasCantidad (Paradas p);

//Muestra todas las paradas
void ParadasMostrar (Paradas p);

#endif // PARADAS_H_INCLUDED

