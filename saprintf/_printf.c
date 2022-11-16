#include "_printf.h"
/**
 * _printf - function that prints a format string
 * @format: pointer to the constant string to be printed as the format
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;	/*tructure type matrix for the various arguments*/
	int constant = 0, counter = 0;
	int (*f)(va_list agrs);

	va_start(args, format);/*initialize arguments list*/
	if (!format)	/*in case of receiving an empty argument returns error*/
		return (-1);
	while (format[constant])/*does not depend on the number of iterations*/
	{
		/*travels up to %, without taking it into account*/
		for (; format[constant] != 37 && format[constant]; constant++)
		{
			counter += _putchar(format[constant]);/*prints string*/
		}
		/*check if where it is positioned there is a % of*/
		if (format[constant] == 37)
		{
			constant++;
			/*checks in case of having received only % as argument*/
			if (!format[constant])
				return (-1);
			/*requests the function to print the format*/
			f = get_format(&format[constant]);
			if (f)
			{
				counter += f(args);
			}
			else if (format[constant] == 37)
				counter += _putchar(37);/*if the character after the % is another %*/
			else
			{
				/*printed the % and character follow in case of no flag*/
				counter += _putchar(format[counter]);
				counter += _putchar(format[constant]);
			}
			constant++;
		}
	}
	va_end(args);
	return (counter);/*returns the number of characters printed*/
}
/**
 * get_format - providing the function to print the requested format
 * @format_flag: pointer to the requested format type
 *
 * Return: returns the function to print the formati, 0 if not found
 */
int (*get_format(const char *format_flag))(va_list)
{
	get_t functions[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_inter},
		{'i', print_inter},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octa},
		{'x', print_hexa},
		{'X', print_HEXA},
		{'r', print_rev},
		{'R', print_rot13ed},
		{'p', print_address},
		{'S', Non_printable_char},
		{'\0', NULL},
	};
	int iterator = 0;

	for (; functions[iterator].f_s; iterator++)
		/*looks for a match with the format structure*/
		if (*format_flag == functions[iterator].f_s)
			return (functions[iterator].f);
	return (0);
}
/**
 * print_char - prints a character
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_char(va_list args)
{
	char character = va_arg(args, int);

	return (_putchar(character));
}
/**
 * print_string - prints a string
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	return (_puts(str));
}
/**
 * print_rev - prints a Sting in reverse
 * @args: the value returned from the returned function
 *
 * Return: the number of printed characters
 */
int print_rev(va_list args)
{
	char *str = va_arg(args, char *);
	int len = _strlen(str) - 1;

	for (; len >= 0; len--)
		_putchar(str[len]);
	return (_strlen(str));
}

/**
 * print_HEXA - prints numbers in hexadecimal with uppercase letters
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_HEXA(va_list args)
{
	unsigned int HEXA = va_arg(args, unsigned int);

	return (_puts(string_toupper(base_convert(HEXA, 16))));
}

/**
 * print_rot13ed - prints an encrypted string in rot13
 * @args: list of arguments received from the varied function
 *
 * Return: number of characters printed
 */
int print_rot13ed(va_list args)
{
	int count = 0;
	char *str = va_arg(args, char *);

	for (; *str;)
	{
		if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
			_putchar(*str + 13);
		else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'Z'))
			_putchar(*str - 13);
		else
			_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
/**
 * print_inter - prints integer
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_inter(va_list args)
{
	long int inter = va_arg(args, int);

	if (inter < 0)
	{
		inter = -inter;
		_putchar(45);
		return (_puts(base_convert(inter, 10)) + 1);
	}
	return (_puts(base_convert(inter, 10)));
}
/**
 * print_binary - prints unsigned numbers in binary
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_binary(va_list args)
{
	unsigned int bin = va_arg(args, unsigned int);

	return (_puts(base_convert(bin, 2)));
}
/**
 * print_unsigned - prints unsigned numbers
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_unsigned(va_list args)
{
	unsigned int unsig = va_arg(args, unsigned int);

	return (_puts(base_convert(unsig, 10)));
}
/**
 * print_octa - prints unsigned numbers in octal
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_octa(va_list args)
{
	unsigned int octa = va_arg(args, unsigned int);

	return (_puts(base_convert(octa, 8)));
}
/**
 * print_hexa - prints unsigned hexadecimal numbers
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_hexa(va_list args)
{
	unsigned int hexa = va_arg(args, unsigned int);

	return (_puts(base_convert(hexa, 16)));
}
/**
 * print_address - prints memory addresses
 * @args: list of arguments received from the varied function
 *
 * Return: the value returned from the returned function
 */
int print_address(va_list args)
{
	long int addr = va_arg(args, long int);

	if (addr == '\0')
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + _puts(addr_convert(addr, 16)));
}
/**
 * addr_convert - converts an address to hexa
 * @num: number to convert, dividend
 * @base: base, divider
 *
 * Return: pointer to the last remainder obtained in the buffer
 */
char *addr_convert(unsigned long int num, int base)
{
	static const char set[] = "0123456789abcdef";
	static char bufer[64];
	char *ptr = NULL;
	int rest = 0;

	ptr = &bufer[63];
	*ptr = '\0';
	if (num == 0)
	{
		*--ptr = '0';
	}
	for (; num != 0;)
	{
		rest = num % base;
		*--ptr = set[rest];
		num = num / base;
	}
	return (ptr);
}
/**
 * not implemented
 */
int Non_printable_char(va_list args)
{
	char *ASCII = va_arg(args, char *);
	int iterator = 0, j = 0, counter = 0;
	if (ASCII == NULL)
		return (write(1, "(null)", 6));
	for (; ASCII[iterator] ; iterator++)
	{
		if (ASCII[iterator] < 32 || ASCII[iterator] >= 127)
		{
			counter += write(1, "\\x", 2);
			j = 1;
			while (iterator + counter < iterator + 2)
			{
				counter += _putchar(string_toupper(addr_convert(ASCII[iterator], 16))[0]);
				counter += _putchar(string_toupper(addr_convert(ASCII[iterator], 16))[1]);
				j++;
			}
		}
		else
			counter += write(1, &ASCII[iterator], 1);
	}
	return (counter);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string
 * @str: pointer to the address of the first position of the string
 *
 * Return: the output value from write
 */
int _puts(char *str)
{
	return (write(1, str, _strlen(str)));
}
/**
 * _strlen - returns the length of a string
 * @s: pinter to addres os strign
 *
 * Return: all elements of the stirng
 */
int _strlen(char *s)
{
	int count = 0;

	for (; s[count]; count++)
		;
	return (count);
}
/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: pointer to the string
 * Return: returns the position of the changed characters
 */
char *string_toupper(char *str)
{
	int i = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
	}
	return (str);
}
/**
 * base_convert - converts an integer to any base
 * @num: number to convert, dividend
 * @base: base, divider
 *
 * Return: pointer to the last remainder obtained in the buffer
 */
char *base_convert(long int num, int base)
{
	static const char set[] = "0123456789abcdef";
	static char bufer[64];
	char *ptr = NULL;
	int rest = 0;

	ptr = &bufer[63];
	*ptr = '\0';
	if (num == 0)
	{
		*--ptr = '0';
	}
	for (; num != 0;)
	{
		rest = num % base;
		*--ptr = set[rest];
		num = num / base;
	}
	return (ptr);
}

