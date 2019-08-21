#include "Ciudades.h"

void CiudadesCrear (Ciudades &ciudades)
{
    int i;
    for (i = 0; i < cant ; i++)
    {
        CiudadesCrearLista(ciudades[i]);
    }
}

void CiudadesCrearLista (ListaCiudad &listaciudad)
{
    listaciudad = NULL;
}

void CiudadesLiberar(Ciudades &ciudades)
{
    for (int i = 0; i < cant; i++)
    {
        while (ciudades[i] != NULL)
        {
            CiudadesBorrarPrimeroEnLista(ciudades[i]);
        }
    }
}

int CiudadesH(String clave)
{
    int largo = StringLargo(clave), disp = 0;
    for (int i = 0; i < largo; i++)
    {
        disp = disp + clave[i];
    }
    return disp % cant;
}

bool CiudadesPerteneceALista (ListaCiudad listaciudad, String clave)
{
    bool pertenece = false;
    String aux;
    while (listaciudad!= NULL && !pertenece)
    {
        StringCrear(aux);
        CiudadDevolverNombre(listaciudad->ciudad, aux);
        if (StringIguales(aux, clave))
        {
            pertenece = true;
        }
        listaciudad = listaciudad->sig;
        StringDestruir(aux);
    }
    return pertenece;
}

bool CiudadesPertenece (Ciudades ciudades, String clave)
{
    int cubeta = CiudadesH(clave);
    return CiudadesPerteneceALista (ciudades[cubeta],clave);
}

void CiudadesInsfront (ListaCiudad &listaciudad, Ciudad ciudad)
{
	ListaCiudad aux = new NodoCiudades;
	aux->ciudad = ciudad;
	aux->sig = listaciudad;
	listaciudad = aux;
}

//Precondición: !Pertenece(ciudades,CiudadDevolverID(ciudad))
void CiudadesInsertar (Ciudades &ciudades, Ciudad ciudad)
{
    String clave;
    StringCrear(clave);
    CiudadDevolverNombre(ciudad, clave);
    int cubeta = CiudadesH(clave);
    CiudadesInsfront (ciudades[cubeta], ciudad);
    StringDestruir(clave);
}

Ciudad CiudadesObtenerEnLista (ListaCiudad listaciudad, String clave)
{
    bool encontro = false;
    String aux;
    while (listaciudad!= NULL && !encontro)
    {
        StringCrear(aux);
        CiudadDevolverNombre(listaciudad->ciudad, aux);
        if (StringIguales(aux, clave))
        {
            encontro = true;
        }
        else
        {
            listaciudad = listaciudad->sig;
        }
        StringDestruir(aux);
    }
    return listaciudad->ciudad;
}

//Precondición: Pertenece(ciudades, clave)
Ciudad CiudadesObtener (Ciudades ciudades, String clave)
{
    int cubeta = CiudadesH(clave);
    return CiudadesObtenerEnLista (ciudades[cubeta],clave);
}

void CiudadesBorrarPrimeroEnLista (ListaCiudad &listaciudad)
{
    ListaCiudad aux;
    aux = listaciudad;
    listaciudad = listaciudad->sig;
    delete aux;
}

void CiudadesBorrarEnLista (ListaCiudad &listaciudad, String clave)
{
    String aux;
    if (listaciudad != NULL)
    {
        StringCrear(aux);
        CiudadDevolverNombre(listaciudad->ciudad, aux);
        if (StringIguales(aux, clave))
        {
            CiudadesBorrarPrimeroEnLista(listaciudad);
        }
        else
            CiudadesBorrarEnLista(listaciudad->sig, clave);
    }
}

//Precondición: Pertenece(ciudades,clave)
void CiudadesEliminar (Ciudades &ciudades, String clave)
{
    int cubeta = CiudadesH(clave);
    CiudadesBorrarEnLista (ciudades[cubeta], clave);
}

void CiudadesMostrar(Ciudades ciudades)
{
    for (int i = 0; i < cant; i++)
    {
        while (ciudades[i] != NULL)
        {
            printf("%d", i);
            CiudadMostrar(ciudades[i]->ciudad);
            ciudades[i] = ciudades[i]->sig;
        }
    }
}
