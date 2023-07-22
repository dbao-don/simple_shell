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
