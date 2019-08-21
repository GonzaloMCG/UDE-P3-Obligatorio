#include "Linea.h"

void LineaCrear(Linea &linea, String codigo, Ciudad origen, Ciudad destino)
{
    StringCrear(linea.codigo);
    StringCopiar(linea.codigo, codigo);
    linea.origen = origen;
    linea.destino = destino;
    ParadasCrear(linea.paradas);
}

void LineaLiberar (Linea &linea)
{
    StringDestruir(linea.codigo);
    CiudadLiberar(linea.origen);
    CiudadLiberar(linea.destino);
    ParadasLiberar(linea.paradas);
}

void LineaDevolverCodigo (Linea linea, String &codigo)
{
    StringCopiar(codigo, linea.codigo);
}

Ciudad LineaDevolverOrigen (Linea linea)
{
    return linea.origen;
}

Ciudad LineaDevolverDestino (Linea linea)
{
    return linea.destino;
}

Paradas LineaDevolverParadas (Linea linea)
{
    return linea.paradas;
}

void LineaMostrar (Linea linea)
{
    printf("Codigo: ");
    StringMostrar(linea.codigo);
    printf(", Origen: ");
    CiudadMostrar(linea.origen);
    printf(", Destino: ");
    CiudadMostrar(linea.destino);
    printf(", Cantidad de paradas: ");
    printf("%d.\n", ParadasCantidad(linea.paradas));
}

void LineaMostrarParadas(Linea linea)
{
    ParadasMostrar(linea.paradas);
}

void LineaInsertarParada (Linea &linea, String nombre)
{
    ParadasInsback(linea.paradas, nombre);
    //ParadasInsertPenultimo(linea.paradas, nombre);
}

