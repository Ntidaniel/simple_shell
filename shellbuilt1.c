#include "shell.h"

/**
 * print_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @context:  this struct containing potential arguments.for  constant function prototype.
 *  Return: 0 always
 */
int print_history(info_t *context)
{
	print_list(context->history);
	return (0);
}

/**
 * remove_alias - remoes an alias from the list
 * @context: the  parameter structure
 * @str:  string alias
 *
 * Return: success 0,  error 1.
 */
int remove_alias(info_t *context, char *str)
{
	char *q, s;
	int ret;

	q = find_char(str, '=');
	if (!q)
		return (1);
	s= *q;
	* q= 0;
	ret = delete_node_at_index(&(context->alias),
		get_node_index(context->alias, node_starts_with(context->alias, str, -1)));
	*q = s;
	return (ret);
}

/**
 * add_alias - this code  sets alias to string
 * @context: this is the parameter structure
 * @str: string alias
 *
 * Return: on success 0, on error 1
 */
int add_alias(info_t *context, char *str)
{
	char *q;

	p = find_char(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (remove_alias(context, str));

	remove_alias(context, str);
	return (add_node_end(&(context->alias), str, 0) == NULL);
}

/**
 * print_alias -  this prints an alias string in the code
 * @node: alias node
 *
 * Return: on success 0, 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if (node)
	{
		q = find_char(node->str, '=');
		for (b = node->str; b<= q; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias shellbuilt (man alias)
 * @context: the structure containing arguments.  to maintain function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *context)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (context->argc == 1)
	{
		node = context->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; context->argv[i]; i++)
	{
		q = find_char(context->argv[i], '=');
		if (q)
			add_alias(context, context->argv[i]);
		else
			print_alias(node_starts_with(context->alias, context->argv[i], '='));
	}

	return (0);
}
