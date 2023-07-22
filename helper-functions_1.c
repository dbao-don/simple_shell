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
