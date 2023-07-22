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
	char *input_buffer = NULL, *command = NULL;
	int input_length, is_exit_command = 0, child_pid = 0;
	size_t buffer_size;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, PROMPT, 5);

		signal(SIGINT, handle_interrupt);
		input_length = getline(&input_buffer, &buffer_size, stdin);

		if (input_length == EOF)
		{
			if (isatty(STDIN_FILENO))
				free_buf("\n", 1, input_buffer, "1");
			exit(0);
		}

		command = strtok(input_buffer, "\n ");
		args[1] = strtok(NULL, "\n ");
		args[2] = strtok(NULL, "\n ");
		is_exit_command = check_exit(input_buffer);

		if (is_exit_command == TRUE)
		{
			if (args[1] == NULL)
				args[1] = NULL;
			free_buf(NULL, 0, input_buffer, args[1]);
		}

		child_pid = fork();
		if (child_pid == 0)
			exec_child(command, args, input_buffer, argv[0], envp);
		else
			wait(NULL);
	}
}
