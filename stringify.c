#include "shell.h"

/**
 **copyString - copies a string to another with a specified limit
 *@destination: represents the destination string to which the copy is made.
 *@the_source:  refers to the source string from which characters are copied.
 *@n: denotes the maximum number of characters to be copied.
 *Return: the concatenated string
 */
char *copyString(char *destination, char *the_source, int n)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (the_source[i] != '\0' && i < n - 1)
	{
		destination[i] = the_source[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **join_str - concatenates two strings
 *@destination: the first string
 *@the_source: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *join_str(char *destination, char *the_source, int n)
{
	int i, j;
	char *s = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (the_source[j] != '\0' && j < n)
	{
		destination[i] = the_source[j];
		i++;
		j++;
	}
	if (j < n)
		destination[i] = '\0';
	return (s);
}

/**
 **find_char - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *find_char(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
