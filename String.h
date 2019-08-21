#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

///Definición de constante simbólica y tipo de datos

const int MAX = 80;
typedef char * String;

///Cabezales sintácticos de subprogramas

    //Crea un string vacío
void StringCrear(String &str);

    //Libera la memoria usada por el string
void StringDestruir(String &str);

    //Carga un String Dinamico
void StringCargar(String &str);

    //Muestra un String Dinamico
void StringMostrar(String str);

    //Devuelve el largo del string
int StringLargo (String str);

    //Copia el contenido del str2 en str1
void StringCopiar(String &str1, String str2);

    //Determina si los strings s1 y s2 son iguales
bool StringIguales(String str1, String str2);

// Devuelve un String cortado desde la ocurrencia de un separador hasta un “espacio” o ‘\0’
void DarStringHastaSeparador(String &strcorto, String &strlargo, char separador, int ocurrencia);

// Indica si todos los elementos del string son enteros
bool StringSonEnteros(String stringevaluar);

// Cuenta la cantidad de veces que aparece un elemento en un string
int StringOcurrenciaDeElemento(String str, char elem);

//recibe dos strings y devuelve TRUE si el primero de ellos es menor alfabeticamente  que el segundo.
bool StringMenor(String str1, String str2);

// Indica si todos los elementos del string son alfanumericos
bool StringEsAlfaNumerico(String str);

#endif // STRING_H_INCLUDED
