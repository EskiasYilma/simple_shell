#include "main.h"

/**
 * _cstrlen - get length of const string
 * @s: string
 * Return: length of string
 */
int _cstrlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strlen - get length of string
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * xprint - allows us to print simple lines
 * @str: const string to print
 */
void xprint(const char *str)
{
	int len;

	if (!str)
		return;
	len = _cstrlen(str);
	write(STDOUT_FILENO, str, len);
}

/**
 * _memset - fills memory with a constant byte.
 * @s: address begin to fill
 * @b: value to set on memory
 * @n: numbers of bytes to pointed by s
 * Return: char
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int cont = 0;

	while (cont < n)
	{
		*(s + cont) = b;
		cont++;
	}
	return (s);
}

/**
 * _atoi - converts a string to an integer
 * @s: the input string
 * Return: the converted int
 */
int _atoi(char *s)
{
	int n, sign, result;

	for (n = result = 0, sign = 1; s[n]; n++)
	{
		if (s[n] == '-')
			sign *= -1;
		if (s[n] >= '0' && s[n] <= '9')
			result = 10 * result - (s[n] - '0');
		if (result < 0 && (s[n] < '0' || s[n] > '9'))
			break;
	}
	if (sign > 0)
		result *= -1;
	return (result);
}
