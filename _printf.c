#include "main.h"
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * print_char - function to print char
 * @cha: argument char to print
 * Return: len of 1
 */

int print_char(va_list cha)
{
	char ch;

	ch = va_arg(cha, int);
	_putchar(ch);
	return (1);
}

/**
 * print_string - function to print string
 * @string: string to print
 * Return: len of str
 */
int print_string(va_list string)
{
	char *str;
	int i = 0;

	str = va_arg(string, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * _printf - print everything
 * @format: what to print
 * Return: 0 if succesful
 */
int _printf(const char *format, ...)
{
	int i = 0, j, count = 0;
	va_list arg_list;
	p_struct print_var[] = {{"c", print_char}, {"s", print_string},
	{"i", change_int}, {"d", change_int}, {NULL, NULL}};

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; print_var[j].var_type != NULL; j++)
			{
				if (format[i + 1] == print_var[j].var_type[0])
				{
					count += print_var[j].f(arg_list);
				}
			}
			if (format[i + 1] == '%')
				count += _putchar('%');
			else if (format[i + 1] != 'c' && format[i + 1] != 's' &&
			format[i + 1] != 'd' && format[i + 1] != 'i' &&
			format[i + 1] != '\0')
			{
				count += _putchar(format[i]);
				count += _putchar(format[i + 1]);
			}
			else if (format[i + 1] == '\0')
				return (-1);
			i++;

		}
		else
			count += _putchar(format[i]);
	}
	va_end(arg_list);
	return (count);
}
