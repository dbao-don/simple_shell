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

/**
 * run_shell - The main loop for the shell
 * @argv: Command-line arguments array
 * @envp: Array of environment variables
 *
 * Return: Always return 0
 */
int run_shell(char *argv[], char *envp[])
{
	char *args[] = {"/bin/sh", NULL, NULL, NULL};
	char *input_buffer = NULL;
	size_t buffer_size;

	while(TRUE)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, 5);

		signal(SIGNIT, handle_interrupt);
	}
}
