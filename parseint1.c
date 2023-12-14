#include "shell.h"

/**
 * int_covt - this converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int int_covt(char *s)
{
	int i = 0;
	unsigned long int outcome = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			outcome *= 10;
			outcome += (s[i] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * print_error - prints an error message
 * @context: the parameter & return context struct
 * @error_str: the string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *context, char *error_str)
{
	_eputs(context->fname);
	_eputs(": ");
	print_d(context->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(context->argv[0]);
	_eputs(": ");
	_eputs(error_str);
}

/**
 * print_d - function prints a decimal (integer) number (the_base 10)
 * @input: the input
 * @file_dscrpt: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int file_dscrpt)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (file_dscrpt == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * change_int - this is a converter function, a clone of itoa
 * @val: represents number or value
 * @the_base: prestents the base
 * @arg_signals: argument arg_signals
 * Return: string
 */
char *change_int(long int val, int the_base, int arg_signals)
{
	static char *array;
	static char temp[50];
	char sign = 0;
	char *ptr;
	unsigned long n = val;

	if (!(arg_signals & CONVERT_UNSIGNED) && val < 0)
	{
		n = -val;
		sign = '-';

	}
	array = arg_signals & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &temp[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % the_base];
		n /= the_base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * comment_del - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void comment_del(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
