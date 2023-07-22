#include "header.h"

/**
* handle_interrupt - Signal handler for interrupt (SIGINT)
* @signal_number: The signal number
*/
void handle_interrupt(int signal_number)
{
	(void)signal_number;
	write(STDOUT_FILENO, "\n" PROMPT, 6);
}

/**
* free_buf - Frees allocated memory and exits the program
* @s: String to be written to stdout before exiting (can be NULL)
* @len: Length of the string s
* @buffer: Pointer to the dynamically allocated buffer to be freed
* @state: Exit state (can be NULL if no exit state provided)
*/
void free_buf(char *s, int len, char *buffer, char *state)
{
	int exitStatus;

	if (s != NULL)
		write(STDOUT_FILENO, s, len);

	if (state == NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else
	{
		exitStatus = to_int(state);
		free(buffer);
		exit(exitStatus);
	}
}

/**
* check_exit - Checks if the user input is an exit command
* @s: User input as a string
* Return: 1 if the input is an exit command, otherwise 0
*/
int check_exit(char *s)
{
	int i = 0, len = 0;
	char *exit_str = "exit";

	if (s == NULL)
		return (-1);

	while (s[i] != '\0')
	{
		if (s[i] == exit_str[i])
			len++;
		else
			len = 0;
		if (len > 3)
			return (1);
		i++;
	}

	return (0);
}

/**
* execute_child - Executes the command in the child process
* @cmnd: The command to be executed
* @arg: Array of arguments for the command
* @buffer: Input buffer holding the user's input
* @av: Name of the shell program
* @env: Array of environment variables
* Return: Always returns 0
*/
int execute_child(char *cmnd, char *arg[], char *buffer, char *av, char *env[])
{
	char *search_path, *path;

	if (!cmnd)
		free_buf(NULL, 0, buffer, "1");

	search_path = find_path(environ, "PATH");
	path = strtok(search_path, ":");
}

/**
* find_path - Finds the value of an environment variable
* @env: Array of environment variables
* @variable: The variable name to search for
* Return: The value of the environment variable if found, otherwise NULL
*/
char *find_path(char **env, char *variable)
{
	int index = 0;
	char *value = NULL;

	while (env[index] != NULL)
	{
		value = strtok(env[index], "=");
		if (str_compare(value, variable) == 1)
		{
			value = strtok(NULL, "\n");
			return (value);
		}
		index++;
	}

	write(STDOUT_FILENO, ERR_PATH, 18);

	return (NULL);
}
