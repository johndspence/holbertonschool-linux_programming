#include "signals.h"

/**
 * signal_handler - Prints Gotcha! [<signum>] when a signal is received.
 * @signum: signal integer
 * Return: void
 */
void signal_handler(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}

/**
 * handle_sigaction - a function that sets the handler for the signal SIGINT
 * Return: 0 on success, or -1 on error.
 */
int handle_sigaction(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		return (-1);
	return (0);
}
