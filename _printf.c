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
	int i;

	str = va_arg(string, char *);
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

	p_struct print_var[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	va_start(arg_list, format);
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				_putchar('%');
			while (print_var[j].var_type != NULL)
			{
				if (format[i] == print_var[j].var_type[0])
					count += print_var[j].f(arg_list);
				j++;
			}
		}
		else if (format[i] == '\\')
		{
			i++;
			if (format[i] == '0')
				_putchar('\0');
			else if (format[i] == 'n')
				_putchar('\n');
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg_list);
	return (count);
}
