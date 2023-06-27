#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * case_char - handles a case in a switch statement for char
 * @args: the variadic function argument list
 * @i: current iteration of the loop
 * @n_c: current character count
 * Return: nothing
 */
void case_char(va_list args, int *i, int *n_c)
{
	char x = va_arg(args, int);

	_putchar(x);
	(*i) += 2;
	(*n_c)++;
}

/**
 * case_str - handles a case in a switch statement for string
 * @args: the variadic function argument list
 * @i: current iteration of the loop
 * @n_c: current character count
 * Return: nothing
 */
void case_str(va_list args, int *i, int *n_c)
{
	char *x = va_arg(args, char *);

	if (x == NULL)
	{
		_putstr("(null)");
		(*i) += 2;
	}
	else
	{
		_putstr(x);
		(*i) += 2;
		(*n_c) += strlen(x);
	}
}

/**
 * case_mod - handles a case in a switch statement for mod char
 * @format: the format passed to printf
 * @i: current iteration of the loop
 * @n_c: current character count
 * Return: nothing
 */
void case_mod(const char *format, int *i, int *n_c)
{
	char c;

	c = format[*i];
	_putchar(c);
	(*i) += 2;
	(*n_c)++;
}

/**
 * case_int - handles a case in a switch statement for int
 * @args: the variadic function argument list
 * @i: current iteration of the loop
 * @n_c: current character count
 * Return: nothing
 */
void case_int(va_list args, int *i, int *n_c)
{
	int x = va_arg(args, int);

	_putint(x);
	(*i) += 2;
	if (x < 0)
	{
		(*n_c) += strlen(inttostr(x)) + 1;
	}
	else
	{
		(*n_c) += strlen(inttostr(x));
	}
}

/**
 * case_default - print default char not format specifier
 * @format: the format passed to printf
 * @i: current iteration of the loop
 * @n_c: current character count
 * Return: nothing
 */
void case_default(const char *format, int *i, int *n_c)
{
	_putchar(format[*i]);
	(*i)++;
	(*n_c)++;
}
