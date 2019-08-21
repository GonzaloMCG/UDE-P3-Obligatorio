#include "Paradas.h"

//Crea una lista LPPF de Paradas
void ParadasCrear (Paradas &p)
{
    p.prim = NULL;
    p.ult = NULL;
}

void ParadasLiberar(Paradas &p)
{
	while(p.prim != NULL)
	{
	    ParadasResto(p);
	}
}

//Pregunta si la lista es vacia
bool ParadasVacia (Paradas p)
{
    return (bool) (p.prim==NULL && p.ult==NULL);
}

//Devuelve la primer parada de la lista
//Precondición: !Vacia(l)
Parada ParadasPrimero (Paradas p)
{
    return p.prim->parada;
}

//devuelve la ultima parada de la lista
//Precondición: !Vacia(l)
Parada ParadasUltimo (Paradas p)
{
    return p.ult->parada;
}

//Devuelve la lista menos el primer elemento
//Precondición : !Vacia(l)
void ParadasResto (Paradas &p)
{
    NodoParadas * aux = p.prim->sig;
    ParadaDestruir(p.prim->parada);
    delete (p.prim);
    p.prim = aux;
    if (p.prim == NULL)
    {
        p.ult = NULL;
    }
}


//Inserta una nueva parada al principio de la lista
void ParadasInsfront (Paradas &p, Parada nuevap)
{
    NodoParadas * nuevo = new NodoParadas;
    nuevo->parada = nuevap;
    nuevo->sig = p.prim;
    p.prim = nuevo;
    if (p.ult == NULL)
        p.ult = nuevo;
}

//Inserta una nueva parada al final de la lista
void ParadasInsback (Paradas &p, String nombre)
{
    Parada parada;
    NodoParadas * nuevo = new NodoParadas;
    if (p.ult == NULL)
    {
        ParadaCrear(parada, nombre, 1);
    }
    else
    {
        ParadaCrear(parada, nombre, ParadaDevolverNumero(p.ult->parada) + 1);
    }
    nuevo->parada = parada;
    nuevo->sig = NULL;
    if (p.ult == NULL)
    {
        p.ult = nuevo;
        p.prim = nuevo;
    }
    else
    {
        p.ult->sig = nuevo;
        p.ult = nuevo;
    }
}

//Devuelve la cantidad de paradas en la lista
int ParadasCantidad (Paradas p)
{
    int i = 0;
    NodoParadas * nuevo = new NodoParadas;
    nuevo = p.prim;
    while (nuevo != NULL)
    {
        i++;
        nuevo = nuevo->sig;
    }
    return i;
}

void ParadasMostrar(Paradas p)
{
    if((ParadasCantidad (p)) == 0)
        printf("Esta linea aun no cuenta con paradas.\n");
    else
    {
        NodoParadas * nuevo = new NodoParadas;
        nuevo = p.prim;
        do
        {
            ParadaMostrar(nuevo->parada);
            nuevo = nuevo->sig;
        }while(nuevo != NULL);
    }
}

