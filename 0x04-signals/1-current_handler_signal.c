#include "signals.h"

/**
 * current_handler_signal - Retrieves the current handler of the signal SIGINT
 *
 * Return: A pointer to the current handler of SIGINT, or NULL on failure
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, print_hello);
	if (handler == SIG_ERR)
		return (NULL);
	return (handler);
}
