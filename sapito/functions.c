#include "sapito.h"
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
 * _strlen - returns the length of a string
 * @s: pinter to addres os strign
 *
 * Return: all elements of the stirng
 */
int _strlen(char *s)
{
	int count = 0;

	for (; s[count]; count++)	/*saves the size of constant chars traversed in count*/
		;
	return (count);		/*returns the total number of elements*/
}
/**
 * _puts - prints a string
 * @str: pointer to the address of the first position of the string
 */
void _puts(char *str)
{
	for (; *str; str++)
		_putchar(*str);	/*prints the value that points the address to the variable str*/
	_putchar('\n');
}
/**
 * *_strcpy -  function that copies the string
 * @src: pointer to the strign
 * @dest: string copy destination
 *
 * Return: returns copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *copy = dest;	/*store the memory address of de dest in an auxiliary pointer*/

	while ((*copy++ = *src++) != '\0')	/*copy the values pointed to by src into dest*/
		;
	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: pointer to the target srtring to be concatenated
 * @src: pointer to the strign to concatenate
 *
 * Return: the concatenated character string
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i;

	for (i = 0; i < _strlen(src); i++)	/*iterates within the array until smaller '\0' string*/
	{
		dest[len + i] = src[i];		/*concatenates the string*/
	}
	dest[len + i] = '\0';		/*delimits the concatenated Sting */
	return (dest);
}
/**
 * _strncat - concatenates two strings
 * @dest: concatenated destination
 * @src: pointer to string to be concatenated
 * @n: n is the number of bytes of src
 *
 * Return: pointer to the resulting string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int len = _strlen(dest);

	for (i = 0; i < n && src[i] != '\0'; i++)	/*it will use at most n bytes from src*/
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
/**
 * _strncpy - copies the string at most n bytes
 * @dest: string copy destination
 * @src: string copy
 * @n: number of bytes copied, value of src
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; i < n && src[i]; i++)	/*takes the n bytes elements of src*/
		dest[i] = src[i];	/*copy and upload only the specified size within the destination*/
	for (; i < n; i++)
		dest[i] = 0;	/*representation of the value has less digits, it is prefixed with 0's*/
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer to the compared string
 * @s2: pointer to comparison strin
 * Return: difference of characters in their ASCII numeric value or 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)	/*iterates within the two strings*/
		if (s1[i] != s2[i])	/*if they are different return their difference*/
			return (s1[i] - s2[i]);
	return (0);	/*returns 0 specifying that they are equal*/
}
/**
 * _strncmp - compares two strings
 * @s1: pointer to the compared string
 * @s2: pointer to comparison strin
 * @n: s2 elements
 *
 * Return: difference of characters in their ASCII numeric value or 0 if equal
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	for (; i < n && s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the array address
 * @b: is the added constant character or bytes
 * @n: the constant number of bytes b
 *
 * Return: returns the initial position of the array
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)	/*increase in the specified positions I want to access*/
		s[i] = b;	/*full by increased position the b constant character*/
	return (s);	/*initial position*/
}
/**
 * _memcpy - copies memory area
 * @dest: destination
 * @src: what will be copied
 * @n: the amount to be copied
 *
 * Return: to the initial position
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *copy = dest;	/*copies memory*/

	for (; i < n; i++)
		copy[i] = src[i];	/*copy the constants*/
	return (dest);
}
/**
 * _strchr - locates a character in a string
 * @s: pointer to the string
 * @c: desired character
 *
 * Return: to the matching position, if null 0
 */
char *_strchr(char *s, char c)
{
	for (; ; s++)
	{
		if (*s == c)	/*search for a match with c*/
			return (s);
		if (!*s)	/*if null*/
			return (0);
	}
}
/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to the string
 * @accept: bytes of the substring
 *
 * Return: the bytes of the found substring
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0;

	if (!s || !accept)	/*I verify that they are not null pointer*/
		return (i);
	while (*s && _strchr(accept, *s++))	/*count from the indicated position*/
	{
		i++;
	}
	return (i);
}
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string
 * @accept: pointer to the string
 *
 * Return: to the position found, or null if not found
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}
	return (NULL);
}
/**
 * _strstr- locates a substring
 * @haystack: pointer to the string
 * @needle: pointer to the substring
 *
 * Return: position of the found substring, NULL substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *aux = haystack;

	for (; *aux; aux++)
	{
		if (_strncmp(aux, needle, _strlen(needle)) == 0)
			return (aux);
	}
	return (NULL);
}
/**
 * _strdup - returns a pointer to a new string which is a duplicate of the string str
 * @str: pointer to the string
 *
 * Return: pointer to a new string duplicate or NULL
 */
char *_strdup(char *str)
{
	char *copy = NULL;

	if (!str)
		return (copy);
	/*it is also valid to use sizeof, since this operator returns the amount of memory required to store the content of the required data. */
	copy = malloc(_strlen(str) + 1);	/*space required for the number of elements, plus 1 to assign the limiting '\0' character*/
	if (!copy)
		return (copy);
	copy = _strcpy(copy, str);	/*makes a copy of the str to the new array that will contain its copy*/
	return (copy);
}
/**
 * str_concat - concatenates two strings
 * @s1: pointer to the main string
 * @s2: pointer to the secondary string
 *
 * Return: pointer to the concatenated strig, or NULL if empty
 */
char *str_concat(char *s1, char *s2)
{
	char *dest = NULL;

	if (!s1)	/*if NULL is passed, treat it as an empty string*/
		s1 = "";
	if (!s2)
		s2 = "";
	dest = malloc(_strlen(s1) + _strlen(s2) + 1);	/*I need the number of elements that I want to concatenate inside the destination plus the null at the end.*/
	if (!dest)
		return (dest);
	dest = _strcat(dest, s1);	/*I save the first string in the destination, dest as it does not contain any element it is not concatenated beyond its assigned size, but ideally a _strcpy is the best option.*/
	dest = _strcat(dest, s2);	/*I concatenate the second data to the data followed after the first saved data */
	return (dest);
}
/**
 * string_nconcat - concatenates two strings
 * @s1: pointer to the main string
 * @s2: pointer to the secondary string
 * @n: first n bytes of s2
 *
 * Return: pointer to the concatenated strig, or NULL if empty
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *dest = NULL;

	if (!s1)	/*if NULL is passed, treat it as an empty string*/
		s1 = "";
	if (!s2)
		s2 = "";
	dest = malloc(_strlen(s1) + n + 1);
	if (!dest)	/*If the function fails, it should return NULL*/
		return (dest);
	dest = _strcpy(dest, s1);
	dest = _strncat(dest, s2, n);
	return (dest);
}
/**
 * _calloc - allocates memory for a data type
 * @nmemb: number of elementsi of a data type
 * @size: data type size
 *
 * Return: empty pointer to the allocated memory block
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *arrl = NULL;

	if (!nmemb || !size)	/*If nmemb or size is 0, then _calloc returns NULL*/
		return (arrl);
	arrl = malloc(nmemb * size);
	if (!arrl)	/*If nmemb or size is 0, then _calloc returns NULL*/
		return (NULL);
	arrl = _memset(arrl, 0, (size * nmemb)); /*calloc sets the allocated memory to zero*/
	return (arrl);
}
