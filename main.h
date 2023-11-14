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
int (*check_a_print(const char *format, int *frankenstein))(va_list arg_ptr);
int print_buffer_return(va_list arg_ptr);
int print_none_return(va_list arg_ptr);
int print_buffer(const char *format);
int print_char(va_list arg_ptr);
int print_string(va_list arg_ptr);
int print_percent(va_list arg_ptr);
int print_percent_2_space(va_list arg_ptr);
int print_percent_space(va_list arg_ptr);
int print_int(va_list arg_ptr);
int print_int_plus(va_list arg_ptr);
int print_int_space(va_list arg_ptr);
int print_bin(va_list arg_ptr);
int print_number(unsigned int num, int i);
int find_num_bits(int n);
int print_unsigned(va_list arg_ptr);
int print_octal(va_list arg_ptr);
int print_hex(va_list arg_ptr);
int print_hex_u(va_list arg_ptr);
int write_hex(char unp);
int print_n_string(va_list arg_ptr);
int print_r_string(va_list arg_ptr);
int print_rev_string(va_list arg_ptr);
int print_addr(va_list arg_ptr);
int nilly(void);

#endif
