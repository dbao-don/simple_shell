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
