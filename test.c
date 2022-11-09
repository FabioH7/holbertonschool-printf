#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%!\n");
	len2 = printf("%!\n");
	printf("\n%d\n%d\n", len, len2);
	len = _printf("%c", 'S');
	len2 = printf("%c", 'S');
	printf("\n%d\n%d\n", len, len2);

	return (0);
}
