#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * inttostr - converts an integer to a string
 * @num: the integer to convert to string
 * Return: a pointer to a string
 */
char *inttostr(int num)
{
	int len, i, y, tmp, tmp2, digit;
	char *str1;

	y = num;
	num = num < 0 ? num * -1 : num;
	i = 0;
	len = 0;
	tmp = num;
	tmp2 = num;

	while (tmp != 0)
	{
		len++;
		tmp /= 10;
	}

	str1 = malloc(sizeof(char) * (len + 1));

	for (i = len - 1; i >= 0; i--)
	{
		digit = tmp2 % 10;
		tmp2 /= 10;
		str1[i] = digit + '0';
	}
	str1[len] = '\0';
	if (y < 0)
	{
		char *str2;

		str2 = malloc(sizeof(char) * (len + 2));
		str2[0] = '-';
		strcat(str2, str1);
		free(str1);
		return (str2);
	}
	else
	{
		return (str1);
	}
}
