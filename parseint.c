#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * print_inp_str - writes the character c to given file_dscrpt
 * @c: The character to print
 * @file_dscrpt: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_inp_str(char c, int file_dscrpt)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(file_dscrpt, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * print_inp_str - this prints an input string
 * @str: this is the string to be printed
 * @file_dscrpt: the filedescriptor to write to
 * Return: the number of chars put
 */
int print_inp_str(char *str, int file_dscrpt)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += print_inp_str(*str++, file_dscrpt);
	}
	return (i);
}
