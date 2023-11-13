#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct print_option - Struct print_option
 *
 * @specifier: The Operator
 * @function: The function associated
 */

typedef struct print_option
{
	char *specifier;
	int (*function)(va_list);
} print_option;

int _printf(const char *format, ...);
int (*check_a_print(const char *format))(va_list arg_ptr);
int print_buffer_return(va_list arg_ptr);
int print_none_return(va_list arg_ptr);
int print_buffer(const char *format);
int print_char(va_list arg_ptr);
int print_string(va_list arg_ptr);
int print_percent(va_list arg_ptr);
int print_int(va_list arg_ptr);
int print_bin(va_list arg_ptr);
int print_number(unsigned int num, int i);
int find_num_bits(int n);

#endif
