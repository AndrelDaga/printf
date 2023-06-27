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
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				case_char(args, &i, &num_of_char);
				break;
			case 's':
				case_str(args, &i, &num_of_char);
				break;
			case '%':
				case_mod(format, &i, &num_of_char);
				break;

			case 'd':
			case 'i':
				case_int(args, &i, &num_of_char);
				break;
			default:
				case_default(format, &i, &num_of_char);
				break;
			}
		}
		else
		{
			case_default(format, &i, &num_of_char);
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

/**
 * _putint - prints an integer
 * @x: the integer to print
 *
 * Return: int
 */
int _putint(int x)
{
	int num;
	char *buffer;

	num = strlen(inttostr(x));
	buffer = malloc(sizeof(char) * num);
	strcpy(buffer, inttostr(x));
	write(1, buffer, num);
	return (num);
}
