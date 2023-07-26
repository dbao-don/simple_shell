#include "header.h"

/**
 * check_exit - Handles program token being "exit"
 * or "env".
 *
 * @tokens: tokens from stdin in this program
 * @_shell: name of the executable of this program
 * @env: shell environment of this program
 *
 * Return: 0 for exit, 1 for continue or 2 for neither
 */
int check_exit(char **tokens, char *_shell, char **env)
{
	if (tokens[0])
	{
		if (_strcmp(tokens[0], "exit") == 0)
		{
			if (!tokens[1])
				return (0);

			write(STDOUT_FILENO, _shell, _strlen(_shell));
			write(STDOUT_FILENO, NA_NO, 31);
			write(STDOUT_FILENO, tokens[1], _strlen(tokens[1]));
			write(STDOUT_FILENO, "\n", 1);

			return (1);
		}
		if (_strcmp(tokens[0], "env") == 0)
		{
			int i = 0;
			int str_len = 0;

			while (env[i])
			{
				str_len = _strlen(env[i]);
				write(STDOUT_FILENO, env[i], str_len);
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
			return (1);
		}
	}
	return (2);
}
