#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: the format to print
 *
 * Return: an integer, the character count printed out
 */
int _printf(const char *format, ...)
{
	va_list args;

	int i, num_of_char;

	va_start(args, format);

	i = 0;
	num_of_char = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			char x = va_arg(args, int);

			_putchar(x);
			i += 2;
			num_of_char++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			char *x = va_arg(args, char *);

			if (x == NULL)
			{
				_putstr("(null)");
				i += 2;
			}
			else
			{
				_putstr(x);
				i += 2;
				num_of_char += strlen(x);
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar(format[i]);
			i += 2;
			num_of_char++;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			int x = va_arg(args, int);

			_putint(x);
			i += 2;
			num_of_char++;
		}
		else
		{
			_putchar(format[i]);
			i++;
			num_of_char++;
		}
	}
	va_end(args);
	return (num_of_char);
}

/**
 * _putchar - prints a character
 * @c: the character to print
 * Return: int
 */
int _putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

/**
 * _putstr - prints a character
 * @s: the string to print
 *
 * Return: int
 */
int _putstr(char *s)
{
	size_t s_len = strlen(s);

	write(1, s, sizeof(char) * s_len);
	return (s_len);
}

int _putint(int x)
{
	size_t  num;
	char *buffer;
	num = strlen(inttostr(x));
	buffer = malloc(sizeof(char) * num);
	strcpy(buffer, inttostr(x));
	write(1, buffer, num);
	return (num);
}
