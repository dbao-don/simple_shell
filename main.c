#include "header.h"
/**
 * main - entry point for the shell program.
 *
 * @argc: the no. of command line arguments(not used).
 * @argv: An array of strings containing the command-line arguments.
 * @env: An array of strings containing the environment variables
 * Return: 0 always.
 */
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	int odd = 1, term_input, _exit;
	size_t buffer_size;
	char *stdinput_line, **_tokens = NULL;

	while (odd)
	{
		buffer_size = 100;
		stdinput_line = NULL;
		term_input = isatty(0);
		if (term_input)
			write(STDOUT_FILENO, PROMPT, 2);
		if (getline(&stdinput_line, &buffer_size, stdin) == -1)
		{
			free(stdinput_line);
			break;
		}
		_tokens = str_tokens(stdinput_line);
		if (!_tokens)
		{
			free(stdinput_line);
			break;
		}
		_exit = check_exit(_tokens, argv[0], env);
		if (_exit == 0)
		{
			free(stdinput_line);
			free(_tokens);
			return (EXIT_SUCCESS);
		}
		else if (_exit == 1)
		{
			free(stdinput_line);
			free(_tokens);
			continue;
		}
		odd = create_fork(argv[0], _tokens, env, term_input);
		free(stdinput_line);
		free(_tokens);
	}
	return (EXIT_SUCCESS);
}

