#include "main.h"

int change_int(va_list arg_list)
{
	long int x = va_arg(arg_list, int);
	return (print_int(x, 1));
}

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
		new_count += print_int(n / 10, count + 1);
	}
	_putchar(n % 10 + '0');
	return (new_count);
}
