#include "main.h"

/**
 * _putchar - writes char to stdout
 * @c: The character to print
 * Return: 1 (success) or -1 (failure-errno)
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
