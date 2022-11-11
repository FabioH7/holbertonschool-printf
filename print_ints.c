#include "main.h"

/**
 * change_int - take the value of int
 * @arg_list: argument to change
 * Return: function to print int a.k.a len
 */
int change_int(va_list arg_list)
{
	long int x;

	x = va_arg(arg_list, int);
	if (x < 0)
		return (print_int(x, 2));
	return (print_int(x, 1));
}

/**
 * print_int - print int
 * @n: number to print
 * @count: len of int
 * Return: new_count
 */
int print_int(long int n, int count)
{
	int new_count = count;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		new_count = print_int(n / 10, count + 1);
	}
	_putchar(n % 10 + '0');
	return (new_count);
}
