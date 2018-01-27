#include "signals.h"

/**
 * print_hello - Prints " Hello :)"
 *
 * Return: void
 */
void print_hello(int __attribute__((unused)) signum)
{
	printf("Hello :\n");
}

/**
 * set_print_hello - Sets a handler for the signal SIGINT
 *
 * Return: void
 */
void set_print_hello(void)
{
	signal(SIGINT, print_hello);
}
