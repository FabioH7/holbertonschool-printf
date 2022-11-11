#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
typedef struct print_struct
{
	char *var_type;
	int (*f)(va_list arg_list);
} p_struct;
int print_int(long int n, int count);
int change_int(va_list arg_list);
int print_char(va_list cha);
int print_string(va_list string);
int _putchar(char c);
int _printf(const char *format, ...);
#endif
