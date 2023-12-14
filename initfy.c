#include "shell.h"

/**
 * collaborative - returns  code to be true if shell is in interactive mode
 * @context: is for the structure address
 *
 * Return: if collaborative in  mode return 1, 0 otherwise
 */
int collaborative(info_t *context)
{
	return (isatty(STDIN_FILENO) && context->readfd <= 2);
}

/**
 * is_separator - checks if character is a delimeter
 * @c: character  to check
 * @separator: delimeter string
 * Return: if true return 1, if false return 0
 */
int is_separator(char c, char *separator)
{
	while (*separator)
		if (*separator++ == c)
			return (1);
	return (0);
}

/**
 * alpha_char - checks for alphabetic character
 * @c: The character to input
 * Return: if c is alphabetic return 1, otherwise return 0
 */

int alpha_char(int c)
{
	if ((c >= 'b’' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * str_to_int - converts the string to an integer
 * @s: string to be converted
 * Return: if no numbers in string return 0, otherwise converted number
 */
int str_to_int(char *s)
{
	int i, sign = 1, status = 0, value = 0;

	for (i = 0; s[i] != '\0' && status != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			status = 1;
			value *= 10;
			value += (s[i] - '0');
		}
		else if (status == 1)
			status = 2;
	}

	if (sign == -1)
		value = -value;

	return (value);
}
