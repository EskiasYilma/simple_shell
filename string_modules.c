#include "main.h"

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 * Return: diference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i = 0, j = 0;

	while (n && s1[i] && (s1[i] == s2[j]))
	{
		i++;
		j++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (s1[i] - s2[j]);
	}
}

/**
 * _strcmp - this function compare two strings
 * @s1: the first string
 * @s2: the second string
 * Return: return a number depends os the resul fo comparation.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}

/**
 * *_strcpy - copies the string pointed to by src to the buffer pointed to dest
 * @dest: char dest
 * @src: char src
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	char a;

	for (i = 0; src[i] != '\0'; i++)
	{
		a = src[i];
		dest[i] = a;
	}
	dest[i] = '\0';
	return (dest);
}

/**
  * _strdup - duplicates a string
  * @src: src to copy from
  * Return: pointer to malloc'd space
  */

char *_strdup(char *src)
{
	int len, i;
	char *dest;

	if (src == NULL)
		return (NULL);
	len = _strlen(src);
	if (len < 0)
		return (NULL);
	len++;
	dest = malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings.
 * @dest: destination string
 * @src: source string
 * Return: Return a concatenate string
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}

	*ptr = '\0';

	return (dest);
}
