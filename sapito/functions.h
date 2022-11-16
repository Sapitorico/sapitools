#ifndef SAPITO_H
#define SAPITO_H
/*librerias*/
#include <stdio.h>/*contiene las definiciones de las macros, las constantes, las declaraciones de funciones de la biblioteca estándar*/
#include <stdlib.h>/*Contiene los prototipos de funciones de C para gestión de memoria dinámica*/
#include <limits.h>/*determina varias propiedades de los distintos tipos de variables*/
#include <unistd.h>/*define constantes y tipos simbólicos misceláneos y declara funciones misceláneas*/
/*prototipos standar*/
int _putchar(char c);	/*escribe el carácter c en stdout*/

int _strlen(char *s);	/*largo de una string*/

void _puts(char *str);

char *_strcpy(char *dest, char *src);	/*prototpios de manejo de arreglos*/

char *_strcat(char *dest, char *src);	/*concatena dos strings*/

char *_strncat(char *dest, char *src, int n);	/*concatena dos strigns*/

char *_strncpy(char *dest, char *src, int n);	/*copia strings*/

int _strcmp(char *s1, char *s2);	/*compara dos strings*/

int _strncmp(char *s1, char *s2, int n);	/*compara dos strings*/

/*prototipos de busqueda seteo etc, de areglos*/
char *_memset(char *s, char b, unsigned int n);	/*setea un array a un byte cosntante*/

char *_memcpy(char *dest, char *src, unsigned int n);	/*copia un area de memeoria*/

char *_strchr(char *s, char c);	/*localiza un caracter en la string*/

unsigned int _strspn(char *s, char *accept);	/*obtiene la longitud de una subcadena de prefijo*/

char *_strpbrk(char *s, char *accept);	/*busca una cadena para cualquiera de un conjunto de bytes*/

char *_strstr(char *haystack, char *needle);	/*locates a substring*/

/*prototipos de asignacion de memoria*/
char *_strdup(char *str);	/*cuplica una string*/

char *str_concat(char *s1, char *s2);	/*concatena dos strings*/

char *string_nconcat(char *s1, char *s2, unsigned int n);	/*concatena dos cadenas*/

void *_calloc(unsigned int nmemb, unsigned int size);	/*asigna memoria para un tipo de datos*/

#endif /*sapito.h*/
