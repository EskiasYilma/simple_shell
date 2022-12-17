#include "main.h"

/**
 * _sprintf - prints an error message
 * @argv: arguement vector
 * @cmd_cnt: command counter
 * @msg: error message
 * Return: 0 (success), -1 (Failure->errno)
 */
void _sprintf(char **argv, int cmd_cnt, char msg[])
{
	char buffer[1000];
	char *cnt;

	cnt = _itoa(cmd_cnt, buffer, 10);
	xprint(argv[0]);
	xprint(": ");
	xprint(cnt);
	xprint(": ");
	xprint(argv[1]);
	xprint(": ");
	xprint(msg);
	if (_strcmp(argv[1], "cd") == 0 && argv[2])
		xprint(argv[2]);
	_putchar('\n');
	_putchar(BUF_FLUSH);

}

/**
 * swap - swaps characters
 * @x: char 1
 * @y: char 2
 */

void swap(char *x, char *y)
{
	char t = *x;
	*x = *y;
	*y = t;
}

/**
 * reverse - reverses a string buffer
 * @buffer: string
 * @i: initial position
 * @j: final position
 * Return: reversed string
 */

char *reverse(char *buffer, int i, int j)
{
	while (i < j)
	{
		swap(&buffer[i++], &buffer[j--]);
	}

	return (buffer);
}

/**
 * _itoa - Converts integer to string
 * @value: integer
 * @buffer: String to save integer
 * @base: base 10
 * Return: Converted string
 */

char *_itoa(int value, char *buffer, int base)
{
	int n = abs(value);
	int i = 0, r;

	if (base < 2 || base > 32)
	{
		return (buffer);
	}


	while (n)
	{
		r = n % base;

		if (r >= 10)
			buffer[i++] = 65 + (r - 10);
		else
			buffer[i++] = 48 + r;

		n = n / base;
	}

	if (i == 0)
		buffer[i++] = '0';

	if (value < 0 && base == 10)
		buffer[i++] = '-';

	buffer[i] = '\0';
	return (reverse(buffer, 0, i - 1));
}
