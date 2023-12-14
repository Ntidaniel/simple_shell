#include "shell.h"

/**
 * my_contextenv -  this  prints the current contextenv
 * @context: this struct containing potential arguments 
 * to maintain constant function prototype.
 * Return: Always 0
 */
int my_contextenv(info_t *context)
{
	print_list_str(context->env);
	return (0);
}

/**
 * get_contextenv - gets the value of an contextenv variable
 * @context:  this struct containing potential arguments. 
 * @env_name: env var env_name
 * Return: the value
 */
char *get_contextenv(info_t *context, const char *env_name)
{
	list_t *node = context->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, env_name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * env_init -  this Initialize a new contextenvment variable,
 *             or modify an existing one
 * @context: this struct  containing potential arguments.
 *  Return: Always 0
 */
int env_init(info_t *context)
{
	if (context->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (set_contextenv(context, context->argv[1], context->argv[2]))
		return (0);
	return (1);
}

/**
 * rem_env -  this remove an contextenvment variable
 * @context: this struct containing potential arguments.
 * Used  to maintain function prototype.
 * Return: Always 0
 */
int rem_env(info_t *context)
{
	int i;

	if (context->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= context->argc; i++)
		contextenv_unset(context, context->argv[i]);

	return (0);
}

/**
 * fill_env - populates the env linked list
 * @context: this structure containing potential
 * arguments
 * Return: Always 0
 */
int fill_env(info_t *context)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; contextenv[i]; i++)
		add_node_end(&node, contextenv[i], 0);
	context->env = node;
	return (0);
}
