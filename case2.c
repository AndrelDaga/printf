#include "main.h"
#include <string.h>
#include <stddef.h>
/**
 * case_bi - entry point
 * @i: current iteration
 * @n_c: number of char
 * @args: arguments
 * Return: nothing
 **/

void case_bi(va_list args, int *i, int *n_c)
{
	int u;

	u = va_arg(args, int);
	_putstr(numtobi(u));
	(*i) += 2;
	(*n_c) += strlen(numtobi(u));
}
