#include <stdlib.h>
#include "main.h"
#include <string.h>
/**
 * numtobi - Converts int to str
 * @num: integer to convert
 * Return: string
 **/
char *numtobi(size_t num)
{
	int n, i, x;
	size_t c;
	char *bi, *rev;

	c = num;
	n = 0;

	for (x = 0; c > 0; x++)
	{
		c = c / 2;
	}

	bi = malloc(sizeof(char) * (x + 1));
	rev = malloc(sizeof(char) * (x + 1));

	for (i = 0; num > 0; i++)
	{
		rev[i] = (num % 2) + '0';
		num = num / 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		bi[n] = rev[i];
		n++;
	}
	free(rev);
	bi[x + 1] = '\0';

	return (bi);
}
