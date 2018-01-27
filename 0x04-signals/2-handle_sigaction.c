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
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART; /* Restart functions ifinterrupted by handler */
	return (sigaction(SIGINT, &sa, NULL));
}
