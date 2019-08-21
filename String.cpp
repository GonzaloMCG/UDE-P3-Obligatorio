#include "String.h"
///Implementación de los subprogramas definidos en el .h

    //Crea un string vacío
void StringCrear(String &str)
{
    str = new char[1];
    str[0] = '\0';
}

    //Libera la memoria usada por el string
void StringDestruir(String &str)
{
    delete [] str;
    str = NULL;

}

    //Carga un String Dinamico
void StringCargar(String &str)
{
    String aux = new char[MAX];
    int i=0;
    char c;
    scanf ("%c", &c);
    while ((c!= '\n') && (i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StringCopiar(str,aux);
    StringDestruir(aux);
}

// Devuelve un String cortado desde la ocurrencia de un separador hasta un “espacio” o ‘\0’
void DarStringHastaSeparador(String &strcorto, String &strlargo, char separador, int ocurrencia)
{
    String aux = new char[MAX];
    int i=0, j=0;
    char c;
    c = strlargo[i];
    while (c == separador)
    {
        i++;
        c = strlargo[i];
    }
    while (ocurrencia > 0 && strlargo[i] != '\0')
    {
        if (strlargo[i] == separador && strlargo[i+1] != separador)
            ocurrencia--;
        i++;
    }
    c = strlargo[i];
    while ((c!= separador) && (j < MAX-1) && (c!= '\0'))
    {
        aux[j] = c;
        j++;
        i++;
        c = strlargo[i];
    }
    aux[j] = '\0';
    StringCopiar(strcorto,aux);
    StringDestruir(aux);
}

    //Muestra un String Dinamico
void StringMostrar(String str)
{
    int i = 0;
    while(str[i]!= '\0')
    {
        printf ("%c", str[i]);
        i++;
    }
}

    //Devuelve el largo del string
int StringLargo(String str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

    //Copia el contenido del str2 en str1
void StringCopiar(String &str1, String str2)
{
    int i = 0;
    int largo = StringLargo(str2) + 1;
    delete [] str1;
    str1 = new char[largo];
    while (str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}

    //Determina si los strings s1 y s2 son iguales
bool StringIguales (String str1, String str2)
{
    int i = 0;
    bool iguales = true;
    while (iguales && (str1[i] != '\0') && (str2[i] != '\0'))
    {
        if (str1[i] != str2[i])
        iguales = false;
        i++;
    }
    if ((str1[i] != '\0') || (str2[i] != '\0'))
        iguales = false;
    return iguales;
}

bool StringSonEnteros(String stringevaluar)
{
    bool Salida=true;
    int i=0;
    if (stringevaluar[i] != '\0' && (stringevaluar[i] == '-' || (stringevaluar[i] >= 48 && stringevaluar[i] <= 57)))
    {
        if (stringevaluar[i] == '-')
        {
            if (stringevaluar[i+1] >= 48 && stringevaluar[i+1] <= 57)
            {
                i++;
                while(stringevaluar[i] != '\0' && Salida == true)
                {
                    if(stringevaluar[i] < 48 || stringevaluar[i] >  57)
                        Salida = false;
                    else
                        i++;
                }
            }
            else
                Salida = false;
        }
        else
        {
            while(stringevaluar[i] != '\0' && Salida == true)
            {
                if(stringevaluar[i] < 48 || stringevaluar[i] >  57)
                    Salida = false;
                else
                    i++;
            }
        }
    }
    else
        Salida = false;
    return Salida;
}

int StringOcurrenciaDeElemento(String str, char elem)
{
    int i = 0, ocurrencias = 0;
    while (str[i] != '\0')
    {
        if (str[i] == elem)
            ocurrencias++;
        i++;
    }
    return ocurrencias;
}

//recibe dos strings y devuelve true si el primero de ellos es menor alfabeticamente  que el segundo.
bool StringMenor(String str1, String str2)
{
    int i = 0;
    bool encontre = false;
    bool menor = false;
    while ((!encontre) && (str1[i] != '\0') && (str2[i] != '\0'))
    {
        if (str1[i] != str2[i])
        {
            encontre = true;
            if (str1[i] < str2[i])
                menor = true;
        }
        i++;
    }
    if ((!encontre) && (str2[i]!='\0'))
        menor = true;
    return menor;
}

// Indica si todos los elementos del string son alfanumericos
bool StringEsAlfaNumerico(String stringevaluar)
{
    bool Salida=true;
    int i=0;
    while(stringevaluar[i] != '\0' && Salida == true)
    {
        if(stringevaluar[i] > 47 && stringevaluar[i] <  123)
        {
            if((stringevaluar[i] > 57 && stringevaluar[i] < 65) || (stringevaluar[i] > 57 && stringevaluar[i] < 65) || (stringevaluar[i] > 90 && stringevaluar[i] < 97))
                Salida = false;
            i++;
        }
        else
            Salida = false;
    }
    return Salida;
}
