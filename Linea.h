#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED
#include "Ciudad.h"
#include "Paradas.h"

typedef struct {String codigo;
                Ciudad origen;
                Ciudad destino;
                Paradas paradas;
                }Linea;

void LineaCrear(Linea &linea, String codigo, Ciudad origen, Ciudad destino);

void LineaLiberar (Linea &linea);

void LineaDevolverCodigo (Linea linea, String &codigo);

Ciudad LineaDevolverOrigen (Linea linea);

Ciudad LineaDevolverDestino (Linea linea);

Paradas LineaDevolverParadas (Linea linea);

void LineaMostrar (Linea linea);

void LineaMostrarParadas(Linea linea);

void LineaInsertarParada (Linea &linea, String nombre);

#endif // LINEA_H_INCLUDED

