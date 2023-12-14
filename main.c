#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t context[] = { INFO_INIT };
	int file_dscrpt = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (file_dscrpt)
			: "r" (file_dscrpt));

	if (ac == 2)
	{
		file_dscrpt = open(av[1], O_RDONLY);
		if (file_dscrpt == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		context->readfd = file_dscrpt;
	}
	fill_env(context);
	read_history(context);
	hsh(context, av);
	return (EXIT_SUCCESS);
}
