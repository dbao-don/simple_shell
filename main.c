#include "header.h"

/**
 * main - entry point for the shell program.
 *
 * @argc: the no. of command line arguments(not used).
 * @argv: An array of strings containing the command-line arguments.
* @envp: An array of strings containing the environment variables
* Return: 0 always.
*/

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;

	run_shell(argv, envp);

	return (0);
}
