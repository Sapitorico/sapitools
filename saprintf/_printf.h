#ifndef MAIN_H
#define MAIN_H
/*libraries*/
#include <stdio.h>/*contains the macro definitions*/
#include <unistd.h>/*defines constants and symbolic types*/
#include <stdarg.h>/*allows them to accept any number of arguments*/
#include <limits.h>/*limit the values of several types of variables*/
/*printf function prototype*/
int _printf(const char *format, ...);

/*prototype of auxiliary functions*/
int _putchar(char c);
int _puts(char *str);
int _strlen(char *s);
char *string_toupper(char *str);

/*prototype of the base converter*/
char *base_convert(long int num, int base);

/*prototype of the address converter*/
char *addr_convert(unsigned long int num, int base);

/*prototype, function that returns the function corresponding to the format*/
int (*get_format(const char *format_flag))(va_list);

/**
 * struct get_formats - contains the formats
 * @f_s: format specifier
 * @f: pointer to formatting functions
 *
 */
typedef struct get_formats
{
	char f_s;
	int (*f)(va_list args);
} get_t;

/*format prototypes*/
int print_char(va_list args);

int print_string(va_list args);

int print_inter(va_list args);

int print_binary(va_list args);

int print_unsigned(va_list args);

int print_octa(va_list args);

int print_hexa(va_list args);

int print_HEXA(va_list args);

int print_rev(va_list args);

int print_address(va_list args);

int print_rot13ed(va_list args);

int Non_printable_char(va_list args);

int print_base64(va_list agrs);

int print_module(__attribute__ ((unused)) va_list);
#endif /*main.h*/
