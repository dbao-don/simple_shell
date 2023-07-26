#include "header.h"
/**
 * create_fork - Creates a new process and executes a command.
 * @shell_name: Name of the shell program (argv[0]).
 * @tokens: Array of strings containing the command and its arguments.
 * @env: Array of strings containing environment variables.
 * @is_terminal: Flag indicating if the shell is running in a terminal.
 *
 * Return: 1 on success, 0 on failure.
 */
int create_fork(char *shell_name, char **tokens, char **env, int is_terminal)
{
	pid_t child_pid;
	int status;
	char *full_file_name, *path, *exec_name;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (0);
	}
	else if (child_pid == 0)
	{
		if (!tokens || !tokens[0])
			return (0);
		execve(tokens[0], tokens, env);
		path = get_path(env);
		full_file_name = split_path(tokens[0], path);
		if (full_file_name != NULL && path != NULL)
		{
			exec_name = tokens[0], tokens[0] = full_file_name;
			execve(tokens[0], tokens, env), tokens[0] = exec_name;
			free(full_file_name);
		}
		if (tokens != NULL && *tokens != NULL)
		{
			write(STDOUT_FILENO, shell_name, _strlen(shell_name));
			if (is_terminal)
				write(STDOUT_FILENO, ERR_PATH, 28);
			else
			{
				write(STDOUT_FILENO, ": 1: ", 5);
				write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
				write(STDOUT_FILENO, ERR_MSG, 12);
			}
		}
		return (0);
	}
	wait(&status);
	return (1);
}

