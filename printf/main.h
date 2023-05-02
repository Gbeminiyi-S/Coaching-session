#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
typedef struct print_format
{
	char symbol;
	int (*print)(va_list arg);
} prt;

int print_char(va_list arg);
int print_str(va_list arg);
int print_mod(va_list arg);
int _printf(const char *format, ...);
int print_int(va_list arg);
int int_helper(unsigned int value);
int print_binary(va_list arg);
int binary_helper(long int value);
#endif
