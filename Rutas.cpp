#include "Rutas.h"

void RutasCrear(Rutas rutas)
{
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < cant; j++)
        {
            rutas[i][j] = 0;
        }
    }
}

void RutasAgregarTramo(Rutas rutas, int vertice1, int vertice2)
{
    if(vertice1 == vertice2)
        printf("\nNo se puede agregar un tramo de una Ciudad a si misma.\n");
    else
    {
        if(rutas[vertice1][vertice2] == 1)
            printf("\nEl tramo entre estas ciudades ya existe.\n");
        else
        {
            rutas[vertice1][vertice2] = 1;
            if (vertice1 != vertice2)
                rutas[vertice2][vertice1] = 1;
            printf("\nSe agrego un tramo entre las dos ciudades ingresadas.\n");
        }
    }
}

bool RutasDFSecuencia(Rutas rutas, int verticeActual, int verticeFinal)
{
    bool visitado[cant];
    for (int i=0; i<cant; i++)
        visitado[i] = false;
    RutasDFS(rutas, verticeActual, visitado, verticeFinal);
    return(visitado[verticeFinal]);
}



void RutasDFS(Rutas rutas, int verticeActual, bool visitado[cant], int verticeFinal)
{
    int j = 0;
    visitado[verticeActual] = true;
    while (j < cant && !visitado[verticeFinal])
    {
        if ((rutas[verticeActual][j] == 1) && (!visitado[j]))
            RutasDFS(rutas, j, visitado, verticeFinal);
        j++;
    }
}

bool RutasExisteTramo(Rutas rutas, int vertice1, int vertice2)
{
    return(rutas[vertice1][vertice2] == 1);
}
