#include "shell.h"

/**
 * _quit - exits the shell
 * @context: the Structure containing arguments
 * Return: with a given exit status return exit
 * (0) if context.argv[0] != "exit"
 */
int _quit(info_t *context)
{
	int exitcode;

	if (context->argv[1])
	{
		exitcode = int_covt(context->argv[1]);
		if (exitcode == -1)
		{
			context->status = 2;
			print_error(context, "Illegal number: ");
			_eputs(context->argv[1]);
			_eputchar('\n');
			return (1);
		}
		context->err_num = int_covt(context->argv[1]);
		return (-2);
	}
	context->err_num = -1;
	return (-2);
}

/**
 * _cd -  this changes the current directory
 * @context: the struct containing potential arguments.for prototype
 * Return: Always 0
 */
int _cd(info_t *context)
{
	char *s, *path, temp[1024];
	int cd_ret;

	s = getcwd(temp, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!context->argv[1])
	{
		path = get_environ(context, "HOME=");
		if (!path)
			cd_ret =
				chdir((path = get_environ(context, "PWD=")) ? path : "/");
		else
			cd_ret = chdir(path);
	}
	else if (_strcmp(context->argv[1], "-") == 0)
	{
		if (!get_environ(context, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(get_environ(context, "OLDPWD=")), _putchar('\n');
		cd_ret =
			chdir((path = get_environ(context, "OLDPWD=")) ? path : "/");
	}
	else
		cd_ret = chdir(context->argv[1]);
	if (cd_ret == -1)
	{
		print_error(context, "can't cd to ");
		_eputs(context->argv[1]), _eputchar('\n');
	}
	else
	{
		set_environ(context, "OLDPWD", get_environ(context, "PWD="));
		set_environ(context, "PWD", getcwd(temp, 1024));
	}
	return (0);
}

/**
 * _aid - this changes the current directory of the process
 * @context: Structure containing potential arguments.
 * Return: Always 0
 */
int _aid(info_t *context)
{
	char **params;

	params = context->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*params);
	return (0);
}
